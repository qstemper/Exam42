/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 15:13:02 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/11 07:43:39 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!begin_list || !cmp)
		return ;
	tmp = *begin_list;
	while (tmp)
	{
		if ((*cmp)(tmp->data, data_ref) == 0)
		{
			tmp2 = tmp->next;
			free(tmp->data);
			free(tmp);
			tmp = tmp2;
		}
		else
			tmp = tmp->next;
	}
}
