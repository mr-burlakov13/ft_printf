/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_proc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 20:49:57 by lhayward          #+#    #+#             */
/*   Updated: 2020/11/26 20:50:42 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_proc(t_list *list, char c)
{
	char *str;

	str = (char *)malloc(sizeof(char) * 2);
	str[0] = c;
	str[1] = '\0';
	convert(list, 1);
	if (list->minus == 1)
		left_print(list, str, 1);
	else
		right_print(list, str, 1);
	free(str);
}
