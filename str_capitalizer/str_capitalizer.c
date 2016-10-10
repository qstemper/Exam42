/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 07:52:43 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/10 08:28:53 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_isblank(char c)
{
	if (c == '\t' || c == ' ' || c == '\r' || c == '\f' || c == '\v')
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	int	i;
	int	j;

	if (ac < 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	i = 1;
	while (av[i])
	{
		j = -1;
		while(av[i][++j] != '\0')
		{
			if (j == 0 && av[i][j] > 96 && av[i][j] < 123)
				av[i][j] -= 32;
			else if (j != 0 && av[i][j] > 96 && av[i][j] < 123 && ft_isblank(av[i][j - 1]) == 1)
				av[i][j] -= 32;
			else if (j != 0 && av[i][j] > 65 && av[i][j] < 91 && ft_isblank(av[i][j - 1]) == 0)
				av[i][j] += 32;
			write(1, &av[i][j], 1);
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
