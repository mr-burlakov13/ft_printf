/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obnul.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 20:43:22 by lhayward          #+#    #+#             */
/*   Updated: 2020/12/05 15:19:44 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	obnul_list(t_list *list)
{
	list->null_p = 0;
	list->n_sim = 0;
	list->pos = 0;
	list->minus = 0;
	list->zero = 0;
	list->shirina = 0;
	list->tochnost = -1;
	list->shirina_2 = 0;
	list->tochnost_2 = 0;
	list->real_minus = 0;
	list->pointer = 0;
	list->plus = 0;
	list->space = 0;
	list->grill = 0;
	list->regist_grill = 0;
	list->tochn_float = 6;
	list->len = 0;
	list->len2 = 0;
	list->len3 = 0;
	list->okrug = 0;
	list->kontr = 0;
	list->zaza = 0;
	list->llhh = 0;
	list->bukva_b = 0;
	list->ost_b = 0;
}

void	obnul_flags(t_list *list)
{
	list->null_p = 0;
	list->minus = 0;
	list->zero = 0;
	list->shirina = 0;
	list->tochnost = -1;
	list->shirina_2 = 0;
	list->tochnost_2 = 0;
	list->real_minus = 0;
	list->pointer = 0;
	list->plus = 0;
	list->space = 0;
	list->grill = 0;
	list->regist_grill = 0;
	list->tochn_float = 6;
	list->len = 0;
	list->len2 = 0;
	list->len3 = 0;
	list->okrug = 1;
	list->kontr = 0;
	list->zaza = 0;
	list->llhh = 0;
	list->bukva_b = 0;
	list->ost_b = 0;
}
