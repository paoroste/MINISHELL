/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 17:20:37 by paoroste          #+#    #+#             */
/*   Updated: 2017/10/24 14:29:44 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			find_env_var(char *var)
{
	int		i;
	char	*tmp;

	i = -1;
	while (g_envv[++i])
	{
		tmp = ft_chjoin(var, '=');
		if (ft_strstartswith(g_envv[i], tmp))
		{
			free(tmp);
			return (i);
		}
		free(tmp);
	}
	return (i);
}

char		**realloc_envv(int new_size)
{
	char	**new;
	int		i;

	new = (char**)ft_memalloc(sizeof(char*) * (new_size + 1));
	i = -1;
	while (g_envv[++i] && i < new_size)
	{
		new[i] = ft_strdup(g_envv[i]);
		free(g_envv[i]);
	}
	free(g_envv);
	return (new);
}

void		set_var(char *key, char *value)
{
	int		pos;
	char	*tmp;

	pos = find_env_var(key);
	tmp = ft_strjoin("=", value);
	if (g_envv[pos])
	{
		free(g_envv[pos]);
		if (value)
			g_envv[pos] = ft_strjoin(key, tmp);
		else
			g_envv[pos] = ft_strjoin(key, "=");
	}
	else
	{
		g_envv = realloc_envv(pos + 1);
		if (value)
			g_envv[pos] = ft_strjoin(key, tmp);
		else
			g_envv[pos] = ft_strjoin(key, "=");
	}
	free(tmp);
}

int			ft_setenv(char **args)
{
	if (!args[0])
	{
		print_env();
		return (1);
	}
	if (args[1])
	{
		if (args[2])
		{
			ft_putendl("setenv: Too many arguments.");
			return (1);
		}
	}
	set_var(args[0], args[1]);
	return (1);
}
