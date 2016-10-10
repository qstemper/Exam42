/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 07:22:54 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/10 07:45:06 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	ft_putchar(n + 48);
}

int		main(int ac, char **av)
{
	int	i;

	if (ac < 2)
	{
		write(1, "0\n", 2);
		return (1);
	}
	i = 0;
	while(av[i])
		i++;
	i--;
	ft_putnbr(i);
	write(1, "\n", 1);
	return (0);
}
