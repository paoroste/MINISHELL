/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 21:09:34 by paoroste          #+#    #+#             */
/*   Updated: 2016/11/18 21:34:38 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*ptr;
	char	*adr;
	size_t	i;

	i = 0;
	ptr = (char*)dest;
	adr = (char*)src;
	while (i < n)
	{
		ptr[i] = adr[i];
		i++;
	}
	return (ptr);
}
