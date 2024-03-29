/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:58:35 by paoroste          #+#    #+#             */
/*   Updated: 2017/10/11 14:17:06 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdel(char **as)
{
	int		i;

	if (!*as)
		return ;
	i = 0;
	while (as[i])
	{
		free(as[i]);
		i++;
	}
	free(*as);
	*as = NULL;
}
