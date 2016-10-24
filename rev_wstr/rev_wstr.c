/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 16:01:06 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/24 16:57:26 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		ft_isblank(char c)
{
	if (c == ' ' || c == '\t' || c == '\v')
		return (1);
	else if (c == '\0')
		return (-1);
	return (0);
}

int		count_words(char *str)
{
	int flag;
	int cw;

	flag = 0;
	cw = 0;
	while (*str)
	{
		if (flag == 0 && ft_isblank(*str) == 0)
		{
			flag = 1;
			cw ++;
		}
		if (flag == 1  && ft_isblank(*str) == 1)
			flag = 0;
		str++;
	}
	return (cw);
}

int 	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (ft_isblank(*str) == 0)
	{
		i++;
		str++;
	}
	return (i);
}

char	**ft_split(char *str)
{
	char	**tab;
	int		cw;
	int 	len;
	int		i;
	int		j;

	tab = NULL;
	cw = count_words(str);
	if (!(tab = (char **)malloc(sizeof(char *) * (cw + 1))))
		return (tab);
	tab[cw] = NULL;
	i = 0;
	len = 0;
	while (cw-- > 0)
	{
		while (ft_isblank(*str) == 1)
			str++;
		if (ft_isblank(*str) == 0)
		{
			j = 0;
			len = ft_strlen(str);
			if (!(tab[i] = (char *)malloc(sizeof(char) * (len + 1))))
				return (tab);
			tab[i][len] = '\0';
			while (ft_isblank(*str) == 0)
			{
				tab[i][j] = *str;
				j++;
				str++;
			}
		}
		i++;
		str++;
	}
	return (tab);
}

int		main(int ac, char **av)
{
	char	**str;
	int		i;
	int		j;

	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	str = ft_split(av[1]);
	i = count_words(av[1]);
	while (i-- > 0)
	{
		j = -1;
		while (str[i][++j])
			write(1, &str[i][j], 1);
		if (i > 0)
			write(1, " ", 1);
	}
	write(1, "\n", 1);
	while(tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}
