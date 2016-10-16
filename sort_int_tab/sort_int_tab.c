/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 10:25:43 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/16 11:05:50 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		sort_int_tab(int *tab, unsigned int size)
{
	unsigned int		i;
	unsigned int		j;
	int					tmp;

	if (!tab || size == 0 || size == 1)
		return ;
	tmp = 0;
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab [j + 1] = tmp;
			}
		}
	}
}
