/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chjoinfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 17:00:34 by paoroste          #+#    #+#             */
/*   Updated: 2017/10/19 17:02:12 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_chjoinfree(char *s1, char c)
{
	char		*new;

	if (!(new = ft_chjoin(s1, c)))
		return (NULL);
	free(s1);
	s1 = NULL;
	return (new);
}
