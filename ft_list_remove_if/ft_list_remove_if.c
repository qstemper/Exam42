/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 15:13:02 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/10 15:29:35 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*tmp;

	tmp = *begin_list;
	while (tmp)
	{
		if (tmp->next && (*cmp)(tmp->next->data, data_ref) == 0)
		{
			free(tmp->next);
			tmp->next = *begin_list->next-next;
		}
		tmp = tmp->next;
	}
	*begin_list = tmp;
}
