/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 20:19:07 by lhayward          #+#    #+#             */
/*   Updated: 2020/12/05 14:55:42 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	converse_parse_3(char const *format, t_list *list)
{
	if (format[list->pos] == 'h' && format[list->pos + 1] != 'h')
		list->llhh = 1;
	else if (format[list->pos] == 'h' && format[list->pos + 1] == 'h')
	{
		list->llhh = 2;
		list->pos++;
	}
	else if (format[list->pos] == 'l' && format[list->pos + 1] != 'l')
		list->llhh = 3;
	else if (format[list->pos] == 'l' && format[list->pos + 1] == 'l')
	{
		list->llhh = 4;
		list->pos++;
	}
	else
		return ;
	list->pos++;
}

void	converse_parse_2(char const *format, t_list *list, va_list ap)
{
	int *b;

	if (format[list->pos] == 'f')
		print_float(list, ap);
	else if (format[list->pos] == 'n')
	{
		b = va_arg(ap, int*);
		*b = list->n_sim;
	}
	else if (format[list->pos] == '%')
		print_proc(list, '%');
	else
		return ;
}

void	converse_parse(char const *format, t_list *list, va_list ap)
{
	if (format[list->pos] == 'd' || format[list->pos] == 'i')
		print_integer(list, ap);
	else if (format[list->pos] == 's')
		print_str(list, ap);
	else if (format[list->pos] == 'c')
		print_sym(list, ap);
	else if (format[list->pos] == 'p')
		print_point(list, ap);
	else if (format[list->pos] == 'u')
		print_uint(list, ap);
	else if (format[list->pos] == 'x')
		print_hex(list, ap, 'a');
	else if (format[list->pos] == 'X')
		print_hex(list, ap, 'A');
	else if (format[list->pos] == 'f' || format[list->pos] == 'n'
			|| format[list->pos] == '%' || format[list->pos] == 'g')
		converse_parse_2(format, list, ap);
	else
		return ;
	list->pos++;
}

int		main_parse(const char *format, t_list *list, va_list ap)
{
	while (format[list->pos])
	{
		if ((format[list->pos] != '%') && (format[list->pos]))
			list->n_sim += write(1, &format[list->pos++], 1);
		else if (format[list->pos] == '%')
		{
			list->pos++;
			if (!(ft_strchr(ALL_SYMBOLS, format[list->pos])))
				break ;
			mod_flags(format, list, ap);
			if (format[list->pos] == 'l' || format[list->pos] == 'h')
				converse_parse_3(format, list);
			converse_parse(format, list, ap);
			obnul_flags(list);
		}
	}
	return (list->n_sim);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			nb;
	t_list		*list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (0);
	obnul_list(list);
	va_start(ap, format);
	if ((!format[0]) || (format[0] == '%' && ft_strlen(format) == 1))
		return (0);
	else
		nb = main_parse(format, list, ap);
	va_end(ap);
	free(list);
	return (nb);
}
