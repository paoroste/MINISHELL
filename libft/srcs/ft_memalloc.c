/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:51:36 by paoroste          #+#    #+#             */
/*   Updated: 2016/11/22 18:14:42 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*memoire;

	memoire = (unsigned char*)malloc(sizeof(unsigned char) * size);
	if (memoire == NULL)
		return (0);
	ft_memset(memoire, 0, size);
	return (memoire);
}
