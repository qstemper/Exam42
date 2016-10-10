/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 08:35:15 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/10 09:35:56 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		*ft_rrange(int start, int end)
{
	int	*tab;
	int	count;
	int	i;

	tab = NULL;
	count = 0;
	if (start == end)
		count = 1;
	else if ((start >= 0 && end > 0 && start < end) || (start < 0 && end > 0))
		count = end - start + 1;
	else if ((start > 0 && end >= 0 && start > end) || (start > 0 && end < 0))
		count = start - end + 1;
	else if (start < 0 && end <= 0 && start < end)
		count = -(start + end) - 1;
	else if (start <= 0 && end < 0 && start > end)
		count = -(end + start) - 1;
	if (!(tab = (int *)malloc(sizeof(int) * count)))
		return (tab);
	i = 0;
	if (start == end)
		tab[i] = start;
	if (start < end)
	{
		while (tab[i])
		{
			tab[i] = end--;
			i++;
		}
	}
	if (start > end)
	{
		tab[i] = end++;
		i++;
	}
	return (tab);
}
