/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstartswith.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 19:52:26 by paoroste          #+#    #+#             */
/*   Updated: 2017/10/09 19:53:43 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strstartswith(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s2[i++])
		if (s1[i] != s2[i])
			return (0);
	return (1);
}
