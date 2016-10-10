/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 09:44:37 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/10 09:46:45 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_FOREACH_H
# define FT_LIST_FOREACH_H

typedef struct		s_list
{
	struct s_list	*next;
	void			*data;
}					t_list

void				ft_list_foreach(t_list *begin_list, void (*f)(void *));

#endif
