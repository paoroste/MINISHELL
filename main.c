/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 15:06:32 by paoroste          #+#    #+#             */
/*   Updated: 2017/10/19 22:58:34 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*parse_env_var(char *str, int pos)
{
	char	*value;
	char	*key;
	char	c;

	key = ft_strnew(1);
	while (str[pos] && !IS_SPACE(str[pos]))
	{
		c = str[pos];
		key = ft_chjoinfree(key, c);
		pos++;
	}
	if (!(value = get_var(key)))
	{
		free(key);
		return (NULL);
	}
	free(key);
	return (value);
}

char		*parse_input(char *input)
{
	int		i;
	char	*new;

	i = -1;
	new = ft_strnew(1);
	while (input[++i])
	{
		if (input[i] == '$' && input[i + 1])
		{
			new = ft_freejoin(new, parse_env_var(input, i + 1), 1);
			while (input[i + 1] && !IS_SPACE(input[i + 1]) && input[i + 1] != '$')
				i++;
		}
		else if (((i != 0 && !IS_SPACE(input[i - 1])) || i == 0) && input[i] == '~')
		{
			new = ft_freejoin(new, parse_home_path(input + i, 1), 3);
			i += ft_strlen(input + i) - 1;
		}
		else
			new = ft_chjoinfree(new, input[i]);
	}
	free(input);
	return (new);
}

void		get_input(char **input)
{
	int		ret;
	char	buf;
	int		i;
	int		count;

	*input = ft_strnew(1);
	count = 1;
	i = 0;
	while ((ret = read(0, &buf, 1)) && buf != '\n')
	{
		*(*input + i++) = buf;
		*input = ft_realloc(*input, count, count + 1);
		count++;
	}
	*(*input + i) = '\0';
	if(!ret)
	{
		free(*input);
		out_shell();
	}
	if ((ft_strchr(*input, '$') != NULL) || (ft_strchr(*input, '~') != NULL))
		parse_input(*input);
}

int			exec_commands(char **commands)
{
	int		i;
	int		ret;
	char	**command;

	i = -1;
	ret = 0;
	while (commands[++i])
	{
		command = ft_strsplitall(command[i]);
		ret = exec_command(command);
		ft_freestrarr(command);
		if (ret == -1)
			break ;
	}
	return (ret);
}

void		print_env(void)
{
	int		i;

	i = -1;
	while (g_envv[++i])
		ft_putendl(g_envv[i]);
}

int			envv_len(char **envv)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (envv[++i])
		count++;
	return (count);
}

void		init_envv(int ac, char **av, char **envv)
{
	int		i;

	(void)ac;
	(void)av;
	g_envv = (char**)ft_memalloc(sizeof(char*) * (envv_len(envv) + 1));
	i = -1;
	while (envv[++i])
	{
		if (!(g_envv[i] = ft_strdup(envv[i])))
			out_shell();
	}
}

int			main(int ac, char **av, char **envv)
{
	char	*input;
	char	**commands;
	int		ret;

	init_envv(ac, av, envv);
	while (1)
	{
		affichage();
		//signal(SIGINT, signal_handler);
		get_input(&input);
	}
	return (0);
}
