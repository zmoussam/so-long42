/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:25:15 by zmoussam          #+#    #+#             */
/*   Updated: 2022/05/20 02:24:12 by zmoussam         ###   ########.fr       */
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
	so->black = mlx_xpm_file_to_image(so->mlx, "../assets/black.xpm", &x, &y);
	so->p_up = mlx_xpm_file_to_image(so->mlx, "../assets/p_up.xpm", &x, &y);
	so->p_do = mlx_xpm_file_to_image(so->mlx, "../assets/p_do.xpm", &x, &y);
	so->p_le = mlx_xpm_file_to_image(so->mlx, "../assets/p_le.xpm", &x, &y);
	so->p_ri = mlx_xpm_file_to_image(so->mlx, "../assets/p_ri.xpm", &x, &y);
	so->wall = mlx_xpm_file_to_image(so->mlx, "../assets/wall.xpm", &x, &y);
	so->heart = mlx_xpm_file_to_image(so->mlx, "../assets/heart.xpm", &x, &y);
	so->col = mlx_xpm_file_to_image(so->mlx, "../assets/col.xpm", &x, &y);
	so->e_cl = mlx_xpm_file_to_image(so->mlx, "../assets/e_cl.xpm", &x, &y);
	so->e_op = mlx_xpm_file_to_image(so->mlx, "../assets/e_op.xpm", &x, &y);
	so->ceris = mlx_xpm_file_to_image(so->mlx, "../assets/cer.xpm", &x, &y);
	so->d = mlx_xpm_file_to_image(so->mlx, "../assets/disque_jaune.xpm",&x,&y);
	so->green_left = mlx_xpm_file_to_image(so->mlx, "../assets/green_left.xpm",&x,&y);
	so->green_right = mlx_xpm_file_to_image(so->mlx, "../assets/green_right.xpm",&x,&y);
	so->heart_big = mlx_xpm_file_to_image(so->mlx, "../assets/heart_big.xpm",&x,&y);
	so->heart_small = mlx_xpm_file_to_image(so->mlx, "../assets/heart_small.xpm",&x,&y);
	so->red_left = mlx_xpm_file_to_image(so->mlx, "../assets/red_left.xpm",&x,&y);
}
