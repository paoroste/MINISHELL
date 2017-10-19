/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 20:34:56 by paoroste          #+#    #+#             */
/*   Updated: 2017/05/30 15:12:41 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	char			*str;
	unsigned int	i;
	size_t			l;

	str = (char*)s;
	i = (unsigned int)start;
	l = 0;
	dest = (char*)malloc(sizeof(dest) * (len + 1));
	if (dest == 0)
		return (0);
	while (l < len)
	{
		dest[l] = str[i];
		l++;
		i++;
	}
	dest[l] = '\0';
	if (dest == 0)
		return (0);
	return (dest);
}
