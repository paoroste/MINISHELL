/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 17:19:07 by paoroste          #+#    #+#             */
/*   Updated: 2017/10/23 20:35:33 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		remove_env_var(int var_pos)
{
	int			i;
	int			var_count;

	free(g_envv[var_pos]);
	g_envv[var_pos] = NULL;
	i = var_pos;
	var_count = var_pos + 1;
	while (g_envv[i + 1])
	{
		g_envv[i] = ft_strdup(g_envv[i + 1]);
		free(g_envv[i + 1]);
		i++;
		var_count++;
	}
	g_envv = realloc_envv(var_count - 1);
}

int				ft_unsetenv(char **args)
{
	int			i;
	int			var_pos;

	if (!args[0])
	{
		ft_putendl("unsetenv: Too few arguments.");
		return (1);
	}
	i = -1;
	while (args[++i])
	{
		var_pos = find_env_var(args[i]);
		if (g_envv[var_pos])
			remove_env_var(var_pos);
	}
	return (1);
}
