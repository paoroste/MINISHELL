/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mssg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 14:56:43 by paoroste          #+#    #+#             */
/*   Updated: 2017/10/11 15:00:49 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_mssg(void)
{
	char	*path;
	char	buff[2048 + 1];
	char	*parse_path;

	path = getcwd(buff, 2048);
}