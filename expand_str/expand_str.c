/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 09:59:15 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/10 11:06:28 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			ft_isblank(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

int			main(int ac, char **av)
{
	int		i;
	int		j;

	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	j = 0;
	while(av[1][i])
		i++;
	i--;
	while (ft_isblank(av[1][i]) == 1)
		i--;
	j = i;
	i = 0;
	while (i < j)
	{
		while(ft_isblank(av[1][i]) == 1 && av[1][i] != '\0')
			i++;
		while(ft_isblank(av[1][i]) == 0 && av[1][i] != '\0')
		{
			write(1, &av[1][i], 1);
			i++;
		}
		i--;
		if (i != j)
			write(1, "   ", 3);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
