/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_float_plus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:36:19 by lhayward          #+#    #+#             */
/*   Updated: 2020/12/05 14:40:13 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	con_flag_float_shir_bon(t_list *list)
{
	int nb;

	nb = list->len + 1;
	if (list->shirina != 0)
	{
		if (list->plus == 1)
			list->shirina_2 = list->shirina - list->tochnost - nb - 1;
		else
			list->shirina_2 = list->shirina - list->tochnost - nb;
	}
}

void	left_print_float_bon(t_list *list, char *str)
{
	int tm;

	tm = list->len2;
	if (list->plus == 1)
		list->n_sim += write(1, "+", 1);
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

void	right_print_float_bon(t_list *list, char *str)
{
	while (list->shirina_2-- > 0)
		list->n_sim += write(1, " ", 1);
	if (list->plus == 1)
		list->n_sim += write(1, "+", 1);
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
