/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 16:58:27 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/24 19:24:51 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_itoa_base(int value, int base)
{
	char	*str;
	char	tab[16] = "0123456789ABCDEF";
	int		cd;
	long	tmp2;
	long	tmp;
	int		flag;

	str = NULL;
	tmp = (long)value;
	flag = 0;
	cd = 1;
	if (tmp < 0)
	{
		tmp *= -1;
		if (base == 10)
		{
			flag = 1;
			cd++;
		}
	}
	tmp2 = tmp;
	while (tmp /= base)
		cd++;
	if (!(str = (char *)malloc(sizeof(char) * (cd + 1))))
		return (str);
	str[cd] = '\0';
	while (cd--)
	{
		str[cd] = tab[tmp2 % base];
		tmp2 /= base;
	}
	if (flag == 1)
		str[0] = '-';
	return (str);
}
