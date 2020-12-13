/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_printf_plus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:25:50 by lhayward          #+#    #+#             */
/*   Updated: 2020/12/07 14:41:42 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long int	opred(t_list *list, va_list ap)
{
	long long int nb;

	if (list->llhh == 1)
		nb = (long long int)(short int)va_arg(ap, int);
	if (list->llhh == 2)
		nb = (long long int)(signed char)va_arg(ap, int);
	if (list->llhh == 3)
		nb = (long long int)va_arg(ap, long int);
	if (list->llhh == 4)
		nb = va_arg(ap, long long int);
	return (nb);
}

void					print_bonus_plus(t_list *list, va_list ap)
{
	long long int	nb;
	int				len;
	char			*str;

	if (list->llhh != 0)
		nb = opred(list, ap);
	else
		nb = (long long int)va_arg(ap, int);
	if (nb < 0)
	{
		nb = -nb;
		list->real_minus = 1;
		list->plus = 0;
	}
	str = itoa_base_mod(nb, 10, 'a');
	len = ft_strlen(str);
	if (nb == 0 && list->tochnost >= 0)
		len = 0;
	convert_plus(list, len);
	if (list->minus == 1)
		left_print_plus(list, str, len);
	else
		right_print_plus(list, str, len);
	free(str);
}
