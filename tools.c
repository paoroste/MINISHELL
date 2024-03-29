/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 19:29:00 by paoroste          #+#    #+#             */
/*   Updated: 2017/10/24 19:40:20 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		out_shell(void)
{
	ft_freestrarr(g_envv);
	write(1, "\n", 1);
	exit(0);
}

char		*get_var(char *var)
{
	int			i;
	char		*tmp;

	i = -1;
	while (g_envv[++i])
	{
		tmp = ft_chjoin(var, '=');
		if (ft_strstartswith(g_envv[i], tmp))
		{
			free(tmp);
			return (ft_strchr(g_envv[i], '=') + 1);
		}
		free(tmp);
	}
	return (NULL);
}

char		*cut_path(char *str)
{
	int		i;
	int		a;
	char	*new;

	i = 0;
	a = 0;
	if (str == NULL)
		return (NULL);
	while (str[i])
		i++;
	new = (char*)malloc(sizeof(char) * (i + 1));
	i--;
	while (str[i] != '/')
		i--;
	while (str[i++])
	{
		new[a] = str[i];
		a++;
	}
	new[a] = '\0';
	return (new);
}

char		*parse_home_path(char *path, int reverse_parse)
{
	char		*home_path;
	char		*new;

	if (!path)
		return (NULL);
	home_path = get_var("HOME");
	if (!ft_strstartswith(path, reverse_parse ? "~" : home_path))
		return (ft_strdup(path));
	if (reverse_parse)
		new = ft_pathjoin(home_path, path + 1);
	else
	{
		if (*(path + ft_strlen(home_path)) == '\0')
			new = ft_strdup("~");
		else
			new = ft_pathjoin("~", path + ft_strlen(home_path));
	}
	return (cut_path(new));
}

void		affichage(void)
{
	char	*path;
	char	buf[4096 + 1];
	char	*parse_path;
	//char	*final;

	//final = ft_strnew(1);
	path = getcwd(buf, 4096);
	parse_path = parse_home_path(path, 0);
	ft_putstr(""YELLOW" # ");
	ft_putstr(parse_path);
	free(parse_path);
	//free(final);
	ft_putstr(""RED" ═> "STOP"");
}
