/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 20:44:33 by lhayward          #+#    #+#             */
/*   Updated: 2020/11/26 20:46:57 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_point(t_list *list, int len)
{
	if (list->minus > 0)
		list->zero = 0;
	if (list->tochnost > len)
		list->tochnost_2 = list->tochnost - len;
	if (list->shirina >= len + list->tochnost_2)
		list->shirina_2 = list->shirina - len - 2;
}

void	print_point(t_list *list, va_list ap)
{
	char				*str;
	unsigned long long	point;
	int					len;

	list->pointer = 1;
	point = (unsigned long long)va_arg(ap, void*);
	str = itoa_base_mod(point, 16, 'a');
	len = ft_strlen(str);
	if (point == 0 && list->tochnost >= 0)
	{
		list->null_p = 1;
		len--;
	}
	convert_point(list, len);
	if (list->minus == 1)
		left_print(list, str, len);
	else
		right_print(list, str, len);
	free(str);
}
