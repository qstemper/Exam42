/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 11:09:45 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/10 12:14:50 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		main(int ac, char **av)
{
	int		aav;
	int		prime;

	if (ac != 2)
	{
		printf("\n");
		return (0);
	}
	aav = atoi(av[1]);
	if (aav == 1)
	{
		printf("%d", aav);
		return (0);
	}
	while (1)
	{
		prime = 1;
		while (++prime <= aav)
		{
			if (aav % prime == 0)
			{
				printf("%d", prime);
				aav /= prime;
				break ;
			}
		}
		if (aav == 1)
			break ;
		else
			printf("*");
	}
	printf("\n");
	return (0);
}
