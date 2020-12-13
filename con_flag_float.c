/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_flag_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:29:48 by lhayward          #+#    #+#             */
/*   Updated: 2020/12/08 16:33:06 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	con_flag_float(t_list *list)
{
	if (list->tochnost >= 0)
		list->zero = 0;
	if (list->minus > 0)
		list->zero = 0;
	if (list->tochnost > 0 && list->tochnost <= 18)
		list->tochnost = list->tochnost;
	else if (list->tochnost == -1)
		list->tochnost = list->tochn_float;
}

void	con_flag_float_shirina(t_list *list)
{
	int	nb;

	nb = list->len + 1;
	if (list->shirina != 0)
	{
		if (list->real_minus == 1 || list->space == 1)
			list->shirina_2 = list->shirina - list->tochnost - nb - 1;
		else
			list->shirina_2 = list->shirina - list->tochnost - nb;
	}
}

void	left_print_float(t_list *list, char *str)
{
	int tm;

	tm = list->len2;
	if (list->real_minus == 1)
		list->n_sim += write(1, "-", 1);
	if (list->real_minus != 1 && list->space == 1)
		list->n_sim += write(1, " ", 1);
	while (list->len--)
	{
		list->n_sim += write(1, str, 1);
		str++;
	}
	if (list->tochnost != 0)
		list->n_sim += write(1, str++, 1);
	while (list->tochnost > 0 && list->len2 > 0)
	{
		list->n_sim += write(1, str, 1);
		list->tochnost_2--;
		str++;
		list->len2--;
	}
	while (list->tochnost-- - tm)
		list->n_sim += write(1, "0", 1);
	while (list->shirina_2-- > 0)
		list->n_sim += write(1, " ", 1);
}

void	right_print_float(t_list *list, char *str)
{
	if (list->zero == 1)
		while (list->shirina_2-- > 0)
			list->n_sim += write(1, "0", 1);
	if (list->zero == 0)
		while (list->shirina_2-- > 0)
			list->n_sim += write(1, " ", 1);
	if (list->real_minus == 1)
		list->n_sim += write(1, "-", 1);
	if (list->real_minus != 1 && list->space == 1)
		list->n_sim += write(1, " ", 1);
	while (list->len--)
		list->n_sim += write(1, str++, 1);
	if (list->tochnost != 0)
		list->n_sim += write(1, str++, 1);
	while (list->tochnost > 0 && list->len2 > 0)
	{
		list->n_sim += write(1, str++, 1);
		list->tochnost--;
		list->len2--;
	}
	if (list->tochnost < 0)
		return ;
	if (list->tochnost > list->len2)
		while (list->tochnost--)
			list->n_sim += write(1, "0", 1);
}
