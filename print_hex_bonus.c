/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 12:29:00 by lhayward          #+#    #+#             */
/*   Updated: 2020/12/07 16:27:32 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long long int	opred(t_list *list, va_list ap)
{
	unsigned long long int nb;

	if (list->llhh == 1)
		nb = (unsigned long long int)
			(unsigned short int)va_arg(ap, unsigned int);
	if (list->llhh == 2)
		nb = (unsigned long long int)(unsigned char)va_arg(ap, unsigned int);
	if (list->llhh == 3)
		nb = (unsigned long long int)va_arg(ap, unsigned long int);
	if (list->llhh == 4)
		nb = va_arg(ap, unsigned long long int);
	return (nb);
}

static void						rasp_1(t_list *list, char *str, int len)
{
	if (list->minus == 1)
		left_print(list, str, len);
	else
		right_print(list, str, len);
	free(str);
}

static void						rasp_2(t_list *list, char *str, int len)
{
	if (list->minus == 1)
		left_pri_grill(list, str, len);
	else
		right_pri_grill(list, str, len);
	free(str);
}

void							print_hex_grill(t_list *list,
		va_list ap, char c)
{
	char					*str;
	unsigned long long int	nb;
	int						len;

	if (c == 'A')
		list->regist_grill = 1;
	if (list->llhh != 0)
		nb = opred(list, ap);
	else
		nb = (unsigned long long int)va_arg(ap, unsigned int);
	str = itoa_base_mod(nb, 16, c);
	len = ft_strlen(str);
	if (nb == 0 && list->tochnost >= 0)
		len = 0;
	if (nb == 0)
	{
		convert(list, len);
		rasp_1(list, str, len);
	}
	else
	{
		convert_bon_hex(list, len);
		rasp_2(list, str, len);
	}
}
