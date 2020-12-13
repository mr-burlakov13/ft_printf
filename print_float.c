/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 15:29:26 by lhayward          #+#    #+#             */
/*   Updated: 2020/12/05 15:31:19 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	print_float(t_list *list, va_list ap)
{
	long double	nb;
	char		*str;

	if (list->plus == 1)
		print_float_plus(list, ap);
	else
	{
		if (list->llhh == 3)
			nb = (long double)va_arg(ap, double);
		else
			nb = (double)va_arg(ap, double);
		if (nb < 0)
		{
			nb = -nb;
			list->real_minus = 1;
		}
		con_flag_float(list);
		str = itoa_float(nb, list);
		con_flag_float_shirina(list);
		if (list->minus == 1)
			left_print_float(list, str);
		else
			right_print_float(list, str);
		free(str);
	}
}
