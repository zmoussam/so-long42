/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:25:15 by zmoussam          #+#    #+#             */
/*   Updated: 2022/05/17 17:18:54 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' && s2[i] != '\0'))
		i++;
	return (s1[i] - s2[i]);
}

void get_data(t_long *so_long)
{
    int x;
    int y;

    x = 30;
    x = 30;
    so_long->black = mlx_xpm_file_to_image(so_long->mlx, "../assets/black.xpm",&x,&y);
    so_long->player_up = mlx_xpm_file_to_image(so_long->mlx, "../assets/player_up.xpm",&x,&y);
    so_long->player_down = mlx_xpm_file_to_image(so_long->mlx, "../assets/player_down.xpm",&x,&y);
    so_long->player_left = mlx_xpm_file_to_image(so_long->mlx, "../assets/player_left.xpm",&x,&y);
    so_long->player_right = mlx_xpm_file_to_image(so_long->mlx, "../assets/player_right.xpm",&x,&y);
    so_long->wall = mlx_xpm_file_to_image(so_long->mlx, "../assets/wall.xpm",&x,&y);
    so_long->heart = mlx_xpm_file_to_image(so_long->mlx, "../assets/heart.xpm",&x,&y);
    so_long->collectabls = mlx_xpm_file_to_image(so_long->mlx, "../assets/colectabls.xpm",&x,&y);
    so_long->exit_close = mlx_xpm_file_to_image(so_long->mlx, "../assets/exit_close.xpm",&x,&y);
    so_long->exit_open = mlx_xpm_file_to_image(so_long->mlx, "../assets/exit_open.xpm",&x,&y);
    so_long->heart_two = mlx_xpm_file_to_image(so_long->mlx, "../assets/heart2.xpm",&x,&y);
}