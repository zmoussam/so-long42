/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:25:15 by zmoussam          #+#    #+#             */
/*   Updated: 2022/05/23 22:16:25 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' && s2[i] != '\0'))
		i++;
	return (s1[i] - s2[i]);
}

void	get_data(t_long *so)
{
	int	x;
	int	y;

	x = 30;
	y = 30;
	so->black = mlx_xpm_file_to_image(so->mlx, "./assets/black.xpm", &x, &y);
	so->p_up = mlx_xpm_file_to_image(so->mlx, "./assets/p_up.xpm", &x, &y);
	so->p_do = mlx_xpm_file_to_image(so->mlx, "./assets/p_do.xpm", &x, &y);
	so->p_le = mlx_xpm_file_to_image(so->mlx, "./assets/p_le.xpm", &x, &y);
	so->p_ri = mlx_xpm_file_to_image(so->mlx, "./assets/p_ri.xpm", &x, &y);
	so->wall = mlx_xpm_file_to_image(so->mlx, "./assets/wall.xpm", &x, &y);
	so->heart = mlx_xpm_file_to_image(so->mlx, "./assets/heart.xpm", &x, &y);
	so->col = mlx_xpm_file_to_image(so->mlx, "./assets/col.xpm", &x, &y);
	so->e_cl = mlx_xpm_file_to_image(so->mlx, "./assets/e_cl.xpm", &x, &y);
	so->e_op = mlx_xpm_file_to_image(so->mlx, "./assets/e_op.xpm", &x, &y);
	so->ceris = mlx_xpm_file_to_image(so->mlx, "./assets/cer.xpm", &x, &y);
	so->green_left = mlx_xpm_file_to_image(so->mlx,
			"./assets/green_left.xpm", &x, &y);
	so->heart_big = mlx_xpm_file_to_image(so->mlx,
			"./assets/heart_big.xpm", &x, &y);
	so->red_left = mlx_xpm_file_to_image(so->mlx,
			"./assets/red_left.xpm", &x, &y);
}

static int	nbr_len(int nbr)
{
	int	size;
	int	n;

	size = 0;
	n = nbr;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		size++;
	}
	size = size + (n <= 0);
	return (size);
}

char	*ft_itoa(int l)
{
	char	*str;
	long	n;
	int		p;
	int		len_nbr;

	n = l;
	len_nbr = nbr_len(n);
	str = (char *)malloc((len_nbr + 1) * sizeof(char));
	if (!str)
		return (str);
	p = 0;
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		p = 1;
	}
	str[len_nbr] = '\0';
	while (--len_nbr >= p)
	{
		str[len_nbr] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*new_str;
	size_t	len_s1;
	size_t	len_s2;
	size_t	j;
	size_t	i;

	if (!s1)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new_str = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		new_str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new_str[j++] = s2[i++];
	new_str[j] = '\0';
	return (new_str);
}
