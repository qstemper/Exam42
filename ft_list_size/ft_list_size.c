/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 07:14:51 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/10 07:20:49 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int					ft_list_size(t_list *begin_list)
{
	int				count;
	t_list			*tmp_list;

	count = 0;
	if (!begin_list)
		return (count);
	tmp_list = begin_list;
	while (tmp_list)
	{
		count++;
		tmp_list = tmp_list->next;
	}
	return (count);
}
