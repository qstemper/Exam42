/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 15:55:04 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/11 07:45:01 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char const *s)
{
	write(1, s, ft_strlen((char *)s));
}

void	ft_putnbr(int n)
{
	if (n >= 0)
	{
		if (n >= 10)
		{
			ft_putnbr(n / 10);
			ft_putnbr(n % 10);
		}
		else
			ft_putchar(n + 48);
	}
	else
	{
		ft_putchar('-');
		n = -n;
		ft_putnbr(n);
	}
}

int	ft_atoi(const char *str)
{
	int res;
	int i;
	int c;

	res = 0;
	i = 0;
	c = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == ' ' || str[i] == '\r' || \
			str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] > 47 && str[i] < 58)
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
}

int		main(int ac, char **av)
{
	int	i;
	int a;
	int res;

	if (ac != 2)
	{
		ft_putstr("\n");
		return (-1);
	}
	i = 1;
	res = 0;
	while (i < 10)
	{
		ft_putnbr(i);
		ft_putstr(" x ");
		a = ft_atoi(av[1]);
		ft_putnbr(a);
		ft_putstr(" = ");
		res = i * a;
		ft_putnbr(res);
		ft_putstr("\n");
		i++;
	}
}
