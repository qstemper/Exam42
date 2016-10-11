/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 17:24:34 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/11 18:59:39 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_rrange(int start, int end)
{
	int		*tab;
	int		count;
	int		i;

	tab = NULL;
	count = 0;
	if (start == end)
		count = 1;
	else if (start < end)
		count = end - start + 1;
	else 
		count = start - end + 1;
	if (!(tab = (int *)malloc(sizeof(int) * count)))
		return (tab);
	tab[count] = (int)NULL;
	i = -1;
	while (++i < count)
	{
		if (start < end)
			tab[i] = end--;
		else
			tab[i] = end++;
	}
	return (tab);
}
