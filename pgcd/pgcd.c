/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 10:04:00 by exam              #+#    #+#             */
/*   Updated: 2016/10/11 10:30:06 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int			main(int ac, char **av)
{
	int		n1;
	int		n2;
	int		div;
	int		res;

	if (ac != 3)
	{
		printf("\n");
		return (0);
	}
	n1 = atoi(av[1]);
	n2 = atoi(av[2]);
	if (n1 <= 0 || n2 <= 0)
	{
		printf("------------ Bad use of the progam ------------\n");
		return (0);
	}
	else if (n1 == 1 || n2 == 1)
	{
		printf("1\n");
		return (0);
	}
	else if (n1 == n2)
	{
		printf("%d\n", n1);
		return (0);
	}
	div = 1;
	res = 0;
	while(div <= n1 && div <= n2)
	{
		if (n1 % div == 0 && n2 % div == 0)
			res = div;
		div++;
	}
	printf("%d\n", res);
	return (0);
}
