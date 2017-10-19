/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwordsall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 20:47:37 by paoroste          #+#    #+#             */
/*   Updated: 2017/10/19 20:48:45 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_countwordsall(char const *str)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (IS_SPACE(str[i]))
			i++;
		if (!IS_SPACE(str[i]) && str[i] != '\0')
			count++;
		while (!IS_SPACE(str[i]) && str[i] != '\0')
			i++;
	}
	return (count);
}
