/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 11:39:27 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/24 16:55:52 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int			ft_isblank(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\r' || c == '\f')
		return (1);
	else if (c == '\0')
		return (-1);
	return (0);
}

int			count(char *str)
{
	int		flag;
	int		cw;

	flag = 0;
	cw = 0;
	while (*str)
	{
		if (flag == 0 && ft_isblank(*str) == 0)
		{
			flag = 1;
			cw++;
		}
		else if (flag == 1 && ft_isblank(*str) == 1)
			flag = 0;
		str++;
	}
	return (cw);
}

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (ft_isblank(*str) == 0)
	{
		i++;
		str++;
	}
	return (i);
}

char		**ft_split(char *str)
{
	char	**tab;
	int		cw;
	int		len;
	int		i;
	int		j;

	tab = NULL;
	cw = count(str);
	if (!(tab = (char **)malloc(sizeof(char *) * (cw + 1))))
		return (tab);
	tab[cw] = NULL;
	i = 0;
	while(cw-- > 0)
	{
		while (ft_isblank(*str) == 1)
			str++;
		if (ft_isblank(*str) == 0)
		{
			len = ft_strlen(str);
			if (!(tab[i] = (char *)malloc(sizeof(char) * (len + 1))))
				return (tab);
			tab[i][len] = '\0';
			j = 0;
			while (ft_isblank(*str) == 0)
			{
				tab[i][j] = *str;
				str++;
				j++;
			}
			i++;
		}
		str++;
	}

	return (tab);
}
