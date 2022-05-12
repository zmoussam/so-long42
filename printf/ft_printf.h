/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:45:52 by zmoussam          #+#    #+#             */
/*   Updated: 2021/12/19 15:53:42 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

size_t	ft_strlen(const char *str);
size_t	ft_putchar(int c);
size_t	ft_putstr(char *s);
void	ft_putnbr(int d, int *count);
void	ft_putnbr_u(unsigned int u, int *count);
int		ft_putnbr_base_x(unsigned int nbr);
int		ft_putnbr_base(unsigned int nbr);
int		ft_putnbr_base_p(unsigned long int nbr);
int		ft_printf(const char *str, ...);
int		count_nbr(const char *s, int *l, int *i);
void	if_s(va_list args, int *count, int count2);
#endif
