/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 22:58:02 by lhayward          #+#    #+#             */
/*   Updated: 2020/11/26 20:36:46 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (0);
		s = &s[i + 1];
	}
	return ((char *)s);
}
