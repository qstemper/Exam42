/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 09:46:48 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/16 12:30:13 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void				ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list			*tmp;

	if (!begin_list || !f)
		return ;
	tmp = begin_list;
	while (tmp)
	{
		(*f)(tmp->data);
		tmp = tmp->next;
	}
}
