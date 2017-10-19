/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:13:28 by paoroste          #+#    #+#             */
/*   Updated: 2016/11/24 16:43:12 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*trim(char *str, char *dest)
{
	int		i;
	int		b;

	i = 0;
	b = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i] != '\0')
	{
		dest[b] = str[i];
		i++;
		b++;
	}
	while (dest[b - 1] == ' ' || dest[b - 1] == '\t' || dest[b - 1] == '\n')
		b--;
	dest[b] = '\0';
	return (dest);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	char	*dest;

	str = ft_strdup(s);
	if (str == 0)
		return (0);
	ft_strcpy(str, s);
	dest = ft_strdup(str);
	if (dest == 0)
		return (0);
	trim(str, dest);
	ft_strdup(dest);
	if (str == 0)
		return (0);
	return (dest);
}
