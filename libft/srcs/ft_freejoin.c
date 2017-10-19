/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freejoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:54:35 by paoroste          #+#    #+#             */
/*   Updated: 2017/05/23 16:08:50 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_freejoin(char *s1, char *s2, int nb)
{
	int		a;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (0);
	a = (ft_strlen(s1) + ft_strlen(s2));
	str = (char*)malloc(sizeof(char) * (a + 1));
	if (str == NULL)
		return (0);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	if (nb == 1)
		free(s1);
	if (nb == 2)
		free(s2);
	if (nb == 3)
	{
		free(s1);
		free(s2);
	}
	return (str);
}
