/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 14:17:31 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/10 15:09:58 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>


static int		ft_count_parts(char const *s, char c)
{
	int		cmpt;
	int		var;
	int		i;

	cmpt = 0;
	var = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (var == 0 && s[i] != c)
		{
			var = 1;
			cmpt++;
		}
		if (var == 1 && s[i] == c)
			var = 0;
		i++;
	}
	return (cmpt);
}

static size_t	ft_wordslength(char const *s, char c)
{
	size_t	length;
	int		i;

	length = 0;
	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		length++;
		i++;
	}
	return (length);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if ((ptr = (char *)malloc(sizeof(char) * len)) != NULL)
	{
		while (i < len)
		{
			ptr[i] = s[start + i];
			i++;
		}
		return (ptr);
	}
	return (NULL);
}

char			**ft_split(const *s)
{
	char	**tab;
	size_t	wd_len;
	int		wd_nb;
	int		i;
	int		j;

	i = 0;
	j = 0;
	wd_nb = ft_count_parts(s, ' ');
	if ((tab = (char **)malloc(sizeof(char *) * wd_nb + 1)) == NULL)
		return (NULL);
	tab[wd_nb] = NULL;
	while (wd_nb-- > 0)
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		wd_len = ft_wordslength(s + i, ' ');
		if (wd_len > 0)
		{
			if (!(tab[j++] = ft_strsub(s, i, wd_len)))
				return (NULL);
		}
		i = i + wd_len;
	}
	return (tab);
}
