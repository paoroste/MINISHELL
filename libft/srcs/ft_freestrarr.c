/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestrarr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 20:53:59 by paoroste          #+#    #+#             */
/*   Updated: 2017/10/19 20:55:40 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_freestrarr(char **arr)
{
	int		i;

	if (!arr)
		return ;
	i = -1;
	while (arr[++i])
	{
		free(arr[i]);
	}
	free(arr);
	arr = NULL;
}
