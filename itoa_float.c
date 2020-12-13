/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 15:01:40 by lhayward          #+#    #+#             */
/*   Updated: 2020/12/05 15:08:21 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		len_2(t_list *list, long long int b)
{
	if (b == 0)
		return (list->len2);
	while (b % 10 == 0)
	{
		b /= 10;
		list->len2++;
	}
	return (list->len2);
}

void	okrug2(long long int a, int b, int len, t_list *list)
{
	int b2;

	b2 = a % 10;
	while (a > 0)
	{
		a /= 10;
		len++;
		list->kontr++;
	}
	if (len - list->tochnost <= 2 && b > 4 && b2 > 4)
		list->okrug = 1;
}

void	okrug(double tm, t_list *list)
{
	int				len;
	int				q;
	long long int	a;
	int				b;
	long long int	s;

	s = 1;
	len = 0;
	q = list->tochnost + 1;
	while (q--)
		s *= 10;
	a = tm * s;
	b = a % 10;
	if (a % 2 != 0 && a % 10 != 9)
		a += 1;
	while (a % 10 == 0)
	{
		a /= 10;
		if (a / 10 == 0)
			break ;
		list->kontr++;
		list->bukva_b++;
	}
	okrug2(a, b, len, list);
}

char	*itoa_float2(long long int a, long long int b, t_list *list)
{
	long long int tmp;

	if ((b % 10 == 0 && b > 0 && list->kontr - list->tochnost <= 1 &&
				list->bukva_b == list->tochnost)
			|| (list->bukva_b < list->tochnost && b % 10 == 9
					&& ((list->kontr - list->bukva_b) >= list->tochnost)))
	{
		b += 1;
		list->zaza = 1;
	}
	tmp = a;
	while (tmp > 0)
	{
		list->len++;
		tmp /= 10;
	}
	if (list->len == 0)
		list->len = 1;
	return (prebor(list, a, b));
}

char	*itoa_float(double i, t_list *list)
{
	long long int	a;
	long long int	b;
	long long int	s;
	double			tm;
	int				q;

	s = 1;
	a = (long long int)i;
	tm = (i - a);
	okrug(tm, list);
	q = list->tochnost;
	while (q--)
		s *= 10;
	tm = tm * s;
	b = (long long int)tm;
	return (itoa_float2(a, b, list));
}
