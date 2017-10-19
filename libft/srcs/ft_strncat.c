/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:09:43 by paoroste          #+#    #+#             */
/*   Updated: 2016/11/21 14:18:05 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	size_t	d;
	size_t	s;
	char	*str;

	d = 0;
	s = 0;
	str = (char*)src;
	while (dest[d] != '\0')
		d++;
	while (str[s] != '\0' && s < nb)
	{
		dest[d] = str[s];
		d++;
		s++;
	}
	dest[d] = '\0';
	return (dest);
}
