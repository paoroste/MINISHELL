/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 22:59:46 by paoroste          #+#    #+#             */
/*   Updated: 2017/10/24 18:59:09 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		print_pth(char *path)
{
	char		*parsed_home;

	parsed_home = parse_home_path(path, 0);
	ft_putstr(parsed_home);
	free(parsed_home);
}

void			change_dir(char *path, int print_path)
{
	char		*cwd;
	char		buff[4096 + 1];

	cwd = getcwd(buff, 4096);
	if (!chdir(path))
	{
		if (print_path)
		{
			print_pth(path);
			write(1, "\n", 1);
		}
		set_var("OLDPWD", cwd);
	}
	else
	{
		ft_putstr("cd: ");
		if (access(path, F_OK) == -1)
			ft_putstr("no such file or directory: ");
		else if (access(path, R_OK) == -1)
			ft_putstr("permission denied: ");
		else
			ft_putstr("not a directory: ");
		ft_putendl(path);
	}
}

static int		two_args(char **args)
{
	char		*cwd;
	char		buff[4096 + 1];
	char		*tmp;

	if (args[1])
	{
		if (args[2])
		{
			ft_putendl("cd: too many arguments");
			return (1);
		}
		cwd = getcwd(buff, 4096);
		if (!(tmp = ft_strreplace(cwd, args[0], args[1])))
		{
			ft_putstr("cd: string not in pwd: ");
			ft_putendl(args[0]);
			free(tmp);
			return (1);
		}
		change_dir(tmp, 1);
		free(tmp);
		return (1);
	}
	return (0);
}

int			ft_cd(char **args)
{
	char		*home_path;

	home_path = get_var("HOME");
	if (!args[0])
	{
		change_dir(home_path, 0);
		return (1);
	}
	if (two_args(args))
		return (1);
	else
	{
		if (ft_strequ(args[0], "--"))
		{
			change_dir(home_path, 0);
			return (1);
		}
		else if (args[0][0] == '-' && args[0][2])
		{
			change_dir(get_var("OLDPWD"), 1);
			return (1);
		}
		change_dir(args[0], 0);
	}
	return (1);
}
