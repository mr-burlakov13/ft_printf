/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sym.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 20:53:47 by lhayward          #+#    #+#             */
/*   Updated: 2020/11/26 20:54:17 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_sym(t_list *list, va_list ap)
{
	char *str;
	char c;

	c = (char)va_arg(ap, char*);
	str = &c;
	convert(list, 1);
	if (list->minus == 1)
		left_print(list, str, 1);
	else
		right_print(list, str, 1);
}
