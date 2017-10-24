/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 22:23:33 by paoroste          #+#    #+#             */
/*   Updated: 2017/10/24 19:02:47 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		run_cmd(char *path, char **args)
{
	pid_t		pid;

	pid = fork();
	signal(SIGINT, proc_signal_handler);
	if (pid == 0)
		execve(path, args, g_envv);
	else if (pid < 0)
	{
		free(path);
		ft_putendl("Fork failed to create a new process.");
		return (-1);
	}
	wait(&pid);
	if (path)
		free(path);
	return (1);
}

static int		check_built(char **command)
{
	if (ft_strcmp(command[0], "exit") == 0)
		return (-1);
	else if (ft_strcmp(command[0], "echo") == 0)
		return (ft_echo(command + 1));
	else if (ft_strcmp(command[0], "cd") == 0)
		return (ft_cd(command + 1));
	else if (ft_strcmp(command[0], "setenv") == 0)
		return (ft_setenv(command + 1));
	else if (ft_strcmp(command[0], "unsetenv") == 0)
		return (ft_unsetenv(command + 1));
	else if (ft_strcmp(command[0], "env") == 0)
	{
		print_env();
		return (1);
	}
	return (0);
}

static int		is_executable(char *bin_path, struct stat f, char **command)
{
	if (f.st_mode & S_IFREG)
	{
		if (f.st_mode & S_IXUSR)
			return (run_cmd(bin_path, command));
		else
		{
			ft_putstr("minishell: permission denied: ");
			ft_putendl(bin_path);
		}
		free(bin_path);
		return (1);
	}
	free(bin_path);
	return (0);
}

static int		check_bins(char **command)
{
	int				i;
	char			*bin_path;
	char			**path;
	struct stat		f;

	path = ft_strsplit(get_var("PATH"), ':');
	i = -1;
	while (path && path[++i])
	{
		if (ft_strstartswith(command[0], path[i]))
			bin_path = ft_strdup(command[0]);
		else
			bin_path = ft_pathjoin(path[i], command[0]);
		if (lstat(bin_path, &f) == -1)
			free(bin_path);
		else
		{
			ft_freestrarr(path);
			return (is_executable(bin_path, f, command));
		}
	}
	ft_freestrarr(path);
	return (0);
}

int				exec_command(char **command)
{
	struct stat		f;
	int				built;

	if ((built = check_built(command)) == 1 || check_bins(command))
		return (0);
	if (built < 0)
		return (-1);
	if (lstat(command[0], &f) != -1)
	{
		if (f.st_mode & S_IFDIR)
		{
			change_dir(command[0], 0);
			return (0);
		}
		else if (f.st_mode & S_IXUSR)
			return (run_cmd(ft_strdup(command[0]), command));
	}
	ft_putstr("minishell: command not found: ");
	ft_putendl(command[0]);
	return (0);
}
