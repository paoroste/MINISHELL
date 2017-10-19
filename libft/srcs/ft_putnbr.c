/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 20:46:36 by paoroste          #+#    #+#             */
/*   Updated: 2016/11/18 23:18:33 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long	tmp;

	tmp = n;
	if (n < 0)
	{
		ft_putchar('-');
		tmp = tmp * (-1);
	}
	if (tmp >= 10)
	{
		ft_putnbr(tmp / 10);
		ft_putnbr(tmp % 10);
	}
	else
	{
		n = tmp;
		n = n + '0';
		ft_putchar(n);
	}
}
