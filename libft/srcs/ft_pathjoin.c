/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 20:06:46 by paoroste          #+#    #+#             */
/*   Updated: 2017/10/19 20:35:51 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_pathjoin(char *p1, char *p2)
{
	char	*tmp2;

	if (!p1 || !p2)
		return (NULL);
	if (!ft_strendswith(p1, "/"))
	{
		if(p2[0] == '/')
			return (ft_strjoin(p1, p2));
		else
		{
			tmp2 = ft_freejoin(ft_chjoin(p1, '/'), p2, 1);
			return (tmp2);
		}
	}
	else
	{
		if (p2[0] == '/')
			return (ft_strjoin(p1, p2 + 1));
		else
			return (ft_strjoin(p1, p2));
	}
}
