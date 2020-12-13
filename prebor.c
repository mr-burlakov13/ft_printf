/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prebor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 15:20:15 by lhayward          #+#    #+#             */
/*   Updated: 2020/12/05 15:28:28 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*prebor3(t_list *list, int b2, char *str)
{
	int pr;
	int b3;

	b3 = b2;
	if (list->okrug == 1 && list->zaza != 1 && list->len != 14)
	{
		b2 += 1;
		if (b2 % 10 == 0)
		{
			b2 /= 10;
			pr = b2 % 10;
			str[list->len3 - 1] = pr + '0';
			b2 *= 10;
		}
		str[list->len3] = b2 % 10 + '0';
	}
	return (str);
}

char	*prebor2(char *str, long long int a, int len)
{
	str[len] = '.';
	while (len--)
	{
		str[len] = a % 10 + '0';
		a /= 10;
	}
	return (str);
}

char	*prebor(t_list *list, long long int a, long long int b)
{
	char	*str;
	int		len;
	int		len2;
	int		tmp;
	int		b2;

	len = list->len;
	len2 = list->tochnost - len_2(list, b);
	tmp = list->len2;
	list->len2 = len2;
	while (tmp--)
		b /= 10;
	if (!(str = (char *)malloc(sizeof(char) * (len + len2 + 1))))
		return (NULL);
	b2 = b;
	list->len3 = len + len2;
	str[len2 + len + 1] = '\0';
	while (len2--)
	{
		str[len2 + len + 1] = b % 10 + '0';
		b /= 10;
	}
	str = prebor2(str, a, len);
	return (prebor3(list, b2, str));
}
