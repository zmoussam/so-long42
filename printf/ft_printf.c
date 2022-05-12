/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 18:11:19 by zmoussam          #+#    #+#             */
/*   Updated: 2022/01/03 19:07:03 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static void	ft_check_arg(char c, va_list args, int *count)
{
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), count);
	if (c == 'c')
		*count += ft_putchar(va_arg(args, int));
	if (c == 's')
		*count += ft_putstr(va_arg(args, char *));
	if (c == 'x')
		*count += ft_putnbr_base_x(va_arg(args, unsigned int));
	if (c == 'X')
		*count += ft_putnbr_base(va_arg(args, unsigned int));
	if (c == 'u')
		ft_putnbr_u(va_arg(args, unsigned int), count);
	if (c == 'p')
	{
		*count += ft_putstr("0x");
		*count += ft_putnbr_base_p(va_arg(args, unsigned long int));
	}
	if (c == '%')
		*count += write(1, "%%", 1);
}

static void	if_flag1(char c, va_list args, int *count )
{
	unsigned int	x;

	x = va_arg(args, unsigned int);
	if (x == 0)
		*count += ft_putchar('0');
	else if (c == 'x')
	{
		*count += ft_putstr("0x");
		*count += ft_putnbr_base_x(x);
	}
	else if (c == 'X')
	{
		*count += ft_putstr("0X");
		*count += ft_putnbr_base(x);
	}
}

static void	if_flag2(char const *s, va_list args, int *count, int *l)
{
	int	count2;
	int	i;
	int	j;

	i = -1;
	while (s[++i] == ' ')
		*l += 1;
	if (s[i] == 'd' || s[i] == 'i')
	{
		j = va_arg(args, int);
		if (j < 0)
			ft_putnbr(j, count);
		else
		{
			*count += ft_putchar(' ');
			ft_putnbr(j, count);
		}
	}
	count2 = count_nbr(&s[i], l, &i);
	if (s[i] == 's')
		if_s(args, count, count2);
}

static void	ft_check_flags(char const *str, va_list args, int *count, int *l)
{
	int	x;

	if (str[0] == '#')
		if_flag1(str[1], args, count);
	if (str[0] == ' ')
		if_flag2(&str[1], args, count, l);
	if (str[0] == '+')
	{
		if (str[1] == 'd' || str[1] == 'i')
		{
			x = va_arg(args, int);
			if (x >= 0)
				*count += ft_putchar('+');
			ft_putnbr(x, count);
		}
	}
}

int	ft_printf(const char *str,...)
{
	int		i;
	va_list	args;
	int		count;

	va_start(args, str);
	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '#' || str[i] == ' ' || str[i] == '+')
			{
				ft_check_flags(&str[i], args, &count, &i);
				i++;
			}
			else
				ft_check_arg(str[i], args, &count);
		}
		else
			count += ft_putchar(str[i]);
	}
	va_end(args);
	return (count);
}
// int main()
// {
// 	unsigned int *x  = -255;
// 	printf("%p\n",x);
//    ft_printf("%x\n", -215);
// 	   printf("%x\n", -215);
// } 