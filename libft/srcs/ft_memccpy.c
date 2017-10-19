/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:39:44 by paoroste          #+#    #+#             */
/*   Updated: 2016/11/21 14:11:07 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*ptr;
	char	*adr;
	size_t	nb;

	ptr = (char*)dest;
	adr = (char*)src;
	nb = 0;
	while (nb < n)
	{
		ptr[nb] = adr[nb];
		if (ptr[nb] == c)
		{
			nb++;
			return (&ptr[nb]);
		}
		nb++;
	}
	return (0);
}
