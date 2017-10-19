/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:35:15 by paoroste          #+#    #+#             */
/*   Updated: 2016/11/21 14:16:34 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcat(char *dest, const char *src)
{
	int		d;
	int		s;
	char	*str;

	d = 0;
	s = 0;
	str = (char*)src;
	while (dest[d] != '\0')
		d++;
	while (str[s] != '\0')
	{
		dest[d] = str[s];
		d++;
		s++;
	}
	dest[d] = '\0';
	return (dest);
}
