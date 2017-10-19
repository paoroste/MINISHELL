/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 22:59:46 by paoroste          #+#    #+#             */
/*   Updated: 2016/11/24 23:08:34 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_hex(int nb)
{
	long tmp;

	tmp = nb;
	if (nb >= 16)
	{
		ft_put_hex(tmp / 16);
		ft_put_hex(tmp % 16);
	}
	else
	{
		nb = tmp;
		nb = nb + '0';
		if (nb >= ':' && nb <= '?')
			nb = nb + 39;
		ft_putchar(nb);
	}
}
