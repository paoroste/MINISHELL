/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 20:23:13 by paoroste          #+#    #+#             */
/*   Updated: 2016/11/24 20:53:53 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*fin;

	tmp = (*f)(lst);
	fin = tmp;
	lst = lst->next;
	while (lst)
	{
		tmp->next = (*f)(lst);
		if (tmp == NULL)
			return (fin);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (fin);
}
