/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 14:17:31 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/16 11:36:49 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_isblank(char c)
{
	if  (c == ' ' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int			cw(char *str)
{
	int		count;
	int		flag;

	count = 0;
	flag = 0;
	while (*str)
	{
		if (flag == 0 && ft_isblank(*str) == 0)
		{
			flag = 1;
			count++;
		}
		if (flag == 1 && ft_isblank(*str) == 1)
			flag = 0;
		str++;
	}
	return (count);
}

int			wlen(char *str)
{
	int		len;

	len = 0;
	while (*str && ft_isblank(*str) == 0)
	{
		len++;
		str++;
	}
	return (len);
}

char		**ft_split(char *str)
{
	char	**tab;
	int		count;
	int		len;
	int		i;
	int		j;
	int		k;

	tab = NULL;
	if (!str)
		return (tab);
	i = 0;
	j = 0;
	count = cw(str);
	if (!(tab = (char **)malloc(sizeof(char *) * (count + 1))))
		return (tab);
	tab[count] = NULL;
	while (count-- > 0)
	{
		while (str[i] != '\0' && ft_isblank(str[i]) == 1)
			i++;
		len = wlen(str + i);
		if (len > 0)
		{
			if (!(tab[j] = (char *)malloc(sizeof(char) * (len + 1))))
				return (tab);
			k = -1;
			tab[j][len] = '\0';
			while (++k < len)
			{
				tab[j][k] = str[i];
				i++;
			}
			j++;
		}
	}
	return (tab);
}
