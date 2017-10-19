/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:21:25 by paoroste          #+#    #+#             */
/*   Updated: 2016/11/22 22:43:54 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s1, int c)
{
	int		i;
	int		t;
	char	*str;

	i = 0;
	t = -1;
	str = (char*)s1;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			t = i;
		i++;
	}
	if (str[ft_strlen(str)] == (char)c)
		return (&str[i]);
	if (t != -1)
		return (&str[t]);
	return (0);
}
