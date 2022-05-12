/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_all_number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 22:17:22 by zmoussam          #+#    #+#             */
/*   Updated: 2021/12/18 22:35:27 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#define BASE1 "0123456789ABCDEF"
#define BASE "0123456789abcdef"

int	ft_putnbr_base_x(unsigned int nbr)
{
	int		r;

	r = 1;
	if (nbr >= 16)
	{
		r += ft_putnbr_base_x(nbr / 16);
		ft_putnbr_base_x(nbr % 16);
	}
	else
		ft_putchar(BASE[nbr]);
	return (r);
}

int	ft_putnbr_base(unsigned int nbr)
{
	int		r;

	r = 1;
	if (nbr >= 16)
	{
		r += ft_putnbr_base(nbr / 16);
		ft_putnbr_base(nbr % 16);
	}
	else
		ft_putchar(BASE1[nbr]);
	return (r);
}

int	ft_putnbr_base_p(unsigned long int nbr)
{
	int		r;

	r = 1;
	if (nbr >= 16)
	{
		r += ft_putnbr_base_p(nbr / 16);
		ft_putnbr_base_p(nbr % 16);
	}
	else
		ft_putchar(BASE[nbr]);
	return (r);
}
