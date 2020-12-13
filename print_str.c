/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 20:50:57 by lhayward          #+#    #+#             */
/*   Updated: 2020/12/08 16:31:20 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	right_print_str(t_list *list, char *str, int len)
{
	while (list->shirina_2 > 0 && list->zero == 1)
	{
		list->n_sim += write(1, "0", 1);
		list->shirina_2--;
	}
	while (list->shirina_2 > 0 && list->zero != 1)
	{
		list->n_sim += write(1, " ", 1);
		list->shirina_2--;
	}
	while (len > 0)
	{
		list->n_sim += write(1, str, 1);
		str++;
		len--;
	}
}

void	left_print_str(t_list *list, char *str, int len)
{
	while (len > 0)
	{
		list->n_sim += write(1, str, 1);
		str++;
		len--;
	}
	while (list->shirina_2 > 0)
	{
		list->n_sim += write(1, " ", 1);
		list->shirina_2--;
	}
}

void	print_str(t_list *list, va_list ap)
{
	char	*str;
	int		len;

	str = (char *)va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (list->tochnost >= 0)
	{
		if (list->tochnost < len)
			len = list->tochnost;
	}
	list->shirina_2 = list->shirina - len;
	if (list->minus == 1)
		left_print_str(list, str, len);
	else
		right_print_str(list, str, len);
}
