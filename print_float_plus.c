/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float_plus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 15:31:27 by lhayward          #+#    #+#             */
/*   Updated: 2020/12/05 15:33:15 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_float_plus(t_list *list, va_list ap)
{
	long double	nb;
	char		*str;

	if (list->llhh == 3)
		nb = (long double)va_arg(ap, double);
	else
		nb = (double)va_arg(ap, double);
	if (nb < 0)
	{
		nb = -nb;
		list->real_minus = 1;
		list->plus = 0;
	}
	con_flag_float(list);
	str = itoa_float(nb, list);
	con_flag_float_shir_bon(list);
	if (list->minus == 1)
		left_print_float_bon(list, str);
	else
		right_print_float_bon(list, str);
	free(str);
}
