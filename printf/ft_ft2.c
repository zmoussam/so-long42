/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:57:13 by zmoussam          #+#    #+#             */
/*   Updated: 2021/12/19 13:56:30 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_nbr(const char *s, int *l, int *i)
{
	int	j;
	int	count;

	count = 0;
	j = 0;
	while (s[j] <= '9' && s[j] >= '0')
	{
		count *= 10;
		count = count + (int)(s[j] - '0');
		j++;
		*l += 1;
		*i += 1;
	}
	return (count);
}

void	if_s(va_list args, int *count, int count2)
{
	char	*str;
	int		j;
	int		k;

	k = 0;
	str = va_arg(args, char *);
	j = ft_strlen(str);
	while (k + j < count2)
		k += ft_putchar(' ');
	*count += ft_putstr(str) + k;
}
