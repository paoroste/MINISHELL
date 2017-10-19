/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 20:41:06 by paoroste          #+#    #+#             */
/*   Updated: 2016/11/24 16:42:59 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*dest;

	i = (ft_strlen(s1) + ft_strlen(s2));
	dest = (char*)malloc(sizeof(char) * (i + 1));
	if (dest == 0)
		return (0);
	ft_strcpy(dest, s1);
	ft_strcat(dest, s2);
	ft_strdup(dest);
	if (dest == 0)
		return (0);
	return (dest);
}
