/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 20:47:09 by lhayward          #+#    #+#             */
/*   Updated: 2020/12/07 14:40:48 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

size_t					ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

static long long int	opred(t_list *list, va_list ap)
{
	long long int nb;

	if (list->llhh == 1)
		nb = (long long int)(short int)va_arg(ap, int);
	if (list->llhh == 2)
		nb = (long long int)(char)va_arg(ap, int);
	if (list->llhh == 3)
		nb = (long long int)va_arg(ap, long int);
	if (list->llhh == 4)
		nb = va_arg(ap, long long int);
	return (nb);
}

static void				pop(t_list *list, char *str, int len)
{
	if (list->minus == 1)
		left_print_int(list, str, len);
	else
		right_print_int(list, str, len);
}

void					print_integer(t_list *list, va_list ap)
{
	long long int	nb;
	int				len;
	char			*str;

	if (list->plus == 1)
		print_bonus_plus(list, ap);
	else
	{
		if (list->llhh != 0)
			nb = opred(list, ap);
		else
			nb = (long long int)va_arg(ap, int);
		if (nb < 0)
		{
			nb = -nb;
			list->real_minus = 1;
		}
		str = itoa_base_mod(nb, 10, 'a');
		len = ft_strlen(str);
		if (nb == 0 && list->tochnost >= 0)
			len = 0;
		convert_int(list, len);
		pop(list, str, len);
		free(str);
	}
}
