/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_bon_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:45:49 by lhayward          #+#    #+#             */
/*   Updated: 2020/12/07 16:30:20 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_bon_hex(t_list *list, int len)
{
	if (list->tochnost >= 0)
		list->zero = 0;
	if (list->minus > 0)
		list->zero = 0;
	if (list->tochnost > len)
		list->tochnost_2 = list->tochnost - len;
	if (list->shirina != 0)
	{
		if (list->real_minus == 1)
			list->shirina_2 = list->shirina - list->tochnost_2 - len - 3;
		else
			list->shirina_2 = list->shirina - list->tochnost_2 - len - 2;
	}
}

void	left_pri_grill(t_list *list, char *str, int len)
{
	if (list->regist_grill == 1)
		list->n_sim += write(1, "0X", 2);
	else
		list->n_sim += write(1, "0x", 2);
	if (list->real_minus == 1)
		list->n_sim += write(1, "-", 1);
	while (list->tochnost_2 > 0)
	{
		list->n_sim += write(1, "0", 1);
		list->tochnost_2--;
	}
	while (len-- > 0)
	{
		list->n_sim += write(1, str, 1);
		str++;
	}
	while (list->shirina_2 > 0)
	{
		if (list->zero == 0)
			list->n_sim += write(1, " ", 1);
		else
			list->n_sim += write(1, "0", 1);
		list->shirina_2--;
	}
}

void	right_pri_grill(t_list *list, char *str, int len)
{
	if (list->real_minus == 1 && list->zero == 1)
		list->n_sim += write(1, "-", 1);
	if (list->regist_grill == 1 && list->zero != 0)
		list->n_sim += write(1, "0X", 2);
	else if (list->regist_grill == 0 && list->zero != 0)
		list->n_sim += write(1, "0x", 2);
	while (list->shirina_2 > 0)
	{
		list->n_sim += (list->zero == 0) ? write(1, " ", 1) : write(1, "0", 1);
		list->shirina_2--;
	}
	if (list->real_minus == 1 && list->zero == 0)
		list->n_sim += write(1, "-", 1);
	if (list->regist_grill == 1 && list->zero == 0)
		list->n_sim += write(1, "0X", 2);
	else if (list->regist_grill == 0 && list->zero == 0)
		list->n_sim += write(1, "0x", 2);
	while (list->tochnost_2 > 0)
	{
		list->n_sim += write(1, "0", 1);
		list->tochnost_2--;
	}
	while (len-- > 0)
		list->n_sim += write(1, str++, 1);
}
