/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoiki.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 20:37:03 by lhayward          #+#    #+#             */
/*   Updated: 2020/12/05 15:11:09 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_chet(size_t i, size_t j, size_t k, const char *mas)
{
	int q;

	q = 1;
	while (mas[i] == ' ' || (mas[i] >= 9 && mas[i] <= 13))
		i++;
	if (mas[i] == '+' || mas[i] == '-')
	{
		if (mas[i] == '-')
			q = -q;
		i++;
	}
	while (mas[i] >= '0' && mas[i] <= '9')
	{
		if (j == k && mas[i] > '7' && q == 1)
			return (-1);
		else if (j > k && mas[i] >= '0' && q == 1)
			return (-1);
		else if (j == k && mas[i] > '8' && q == -1)
			return (0);
		else if (j > k && mas[i] >= '0' && q == -1)
			return (0);
		j = j * 10 + mas[i++] - '0';
	}
	return ((int)(j * q));
}

int		ft_atoi(const char *mas)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	j = 0;
	k = 214748364;
	return (ft_chet(i, j, k, mas));
}

char	*itoa_base_mod(unsigned long long int i, unsigned long long b, char c)
{
	unsigned long long int	tmp;
	int						len;
	char					*str;

	len = 1;
	tmp = i;
	while ((tmp /= b) >= 1)
		len++;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		if (i % b < 10)
			str[len] = i % b + '0';
		else
			str[len] = i % b + c - 10;
		i /= b;
	}
	return (str);
}
