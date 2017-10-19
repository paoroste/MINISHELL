/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chjoin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 15:53:36 by paoroste          #+#    #+#             */
/*   Updated: 2017/10/19 15:56:53 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_chjoin(char const *s1, char c)
{
	char		*new_str;
	size_t		i;
	size_t		len;

	if (!s1 || !c)
		return (NULL);
	len = ft_strlen(s1);
	new_str = ft_strnew(len + 1);
	if (!new_str)
		return (NULL);
	i = -1;
	while (++i < len)
		*(new_str + i) = *(s1 + i);
	*(new_str + i) = c;
	return (new_str);
}
