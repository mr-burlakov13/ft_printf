/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 20:13:08 by lhayward          #+#    #+#             */
/*   Updated: 2020/12/07 14:46:56 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags(char const *format, t_list *list)
{
	while (format[list->pos] == '0' || format[list->pos] == '-'
			|| format[list->pos] == '+' || format[list->pos] == ' '
			|| format[list->pos] == '#')
	{
		if (format[list->pos] == '0')
			list->zero = 1;
		else if (format[list->pos] == '-')
			list->minus = 1;
		else if (format[list->pos] == '+')
			list->plus = 1;
		else if (format[list->pos] == ' ')
			list->space = 1;
		else if (format[list->pos] == '#')
			list->grill = 1;
		list->pos++;
	}
}

void	shirina(char const *format, t_list *list, va_list ap)
{
	if (format[list->pos] >= '0' && format[list->pos] <= '9')
	{
		list->shirina = ft_atoi(&format[list->pos]);
		while (format[list->pos] >= '0' && format[list->pos] <= '9')
			list->pos++;
	}
	else if (format[list->pos] == '*')
	{
		list->shirina = (int)va_arg(ap, int);
		if (list->shirina < 0)
		{
			list->zero = 0;
			list->shirina *= -1;
			list->minus = 1;
		}
		list->pos++;
	}
}

void	tochnost(char const *format, t_list *list, va_list ap)
{
	if (format[list->pos] == '.')
	{
		list->pos++;
		if (format[list->pos] >= '0' && format[list->pos] <= '9')
		{
			list->tochnost = ft_atoi(&format[list->pos]);
			while (format[list->pos] >= '0' && format[list->pos] <= '9')
				list->pos++;
		}
		else if (format[list->pos] == '*')
		{
			list->tochnost = (int)va_arg(ap, int);
			if (list->tochnost < 0)
				list->tochnost = -1;
			list->pos++;
		}
		else
			list->tochnost = 0;
	}
}

void	mod_flags(char const *format, t_list *list, va_list ap)
{
	flags(format, list);
	shirina(format, list, ap);
	tochnost(format, list, ap);
}
