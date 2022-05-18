/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 22:17:13 by zmoussam          #+#    #+#             */
/*   Updated: 2022/05/18 21:37:23 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

size_t	ft_putchar(int c)
{
	size_t	len;

	len = write(1, &c, 1);
	return (len);
}

size_t	ft_putstr(char *s)
{
	size_t	len;
	int		i;

	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (len);
}

void	ft_putnbr(int d, int *count)
{
	long	i;

	i = d;
	if (i < 0)
	{
		ft_putchar('-');
		i = i * -1;
		(*count)++;
	}
	if (i <= 9)
	{
		ft_putchar(i + '0');
		(*count)++;
	}
	if (i >= 10)
	{
		ft_putnbr(i / 10, count);
		ft_putnbr(i % 10, count);
	}
}

void	ft_putnbr_u(unsigned int u, int *count)
{
	if (u <= 9)
	{
		ft_putchar(u + '0');
		*count += 1;
	}
	if (u >= 10)
	{
		ft_putnbr(u / 10, count);
		ft_putnbr(u % 10, count);
	}
}
