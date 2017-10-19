/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:09:57 by paoroste          #+#    #+#             */
/*   Updated: 2016/11/17 18:34:03 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_strequ(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;
	int		i;

	str1 = (char*)s1;
	str2 = (char*)s2;
	i = 0;
	if (str1[i] == '\0' && str2[i] == '\0')
		return (1);
	if (str1[i] == '\0' || str2[i] == '\0')
		return (0);
	while (str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] == str2[i] && (str1[i + 1] == '\0' || str2[i + 1] == '\0'))
			return (1);
		i++;
	}
	return (0);
}
