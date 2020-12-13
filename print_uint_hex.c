/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 20:54:37 by lhayward          #+#    #+#             */
/*   Updated: 2020/12/05 16:18:58 by lhayward         ###   ########.fr       */
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

void							print_uint(t_list *list, va_list ap)
{
	int						len;
	unsigned long long int	nb;
	char					*str;

	if (list->llhh != 0)
		nb = opred(list, ap);
	else
		nb = (unsigned long long int)va_arg(ap, unsigned int);
	str = itoa_base_mod(nb, 10, 'a');
	len = ft_strlen(str);
	if (nb == 0 && list->tochnost >= 0)
		len = 0;
	convert(list, len);
	if (list->minus == 1)
		left_print(list, str, len);
	else
		right_print(list, str, len);
	free(str);
}

void							print_hex(t_list *list, va_list ap, char c)
{
	char					*str;
	unsigned long long int	nb;
	int						len;

	if (list->grill == 1)
		print_hex_grill(list, ap, c);
	else
	{
		if (list->llhh != 0)
			nb = opred(list, ap);
		else
			nb = (unsigned long long int)va_arg(ap, unsigned int);
		str = itoa_base_mod(nb, 16, c);
		len = ft_strlen(str);
		if (nb == 0 && list->tochnost >= 0)
			len = 0;
		convert(list, len);
		if (list->minus == 1)
			left_print(list, str, len);
		else
			right_print(list, str, len);
		free(str);
	}
}
