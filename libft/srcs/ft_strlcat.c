/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 18:00:37 by paoroste          #+#    #+#             */
/*   Updated: 2016/11/23 17:50:44 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = ft_strlen(dest);
	if (i < size)
		ft_strncat(dest, src, size - i - 1);
	if ((ft_strlen(src) + size) < (ft_strlen(src) + ft_strlen(dest)))
		return (ft_strlen(src) + size);
	else
		return (ft_strlen(src) + i);
}
