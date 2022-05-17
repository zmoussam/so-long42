/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel2_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 20:21:47 by zmoussam          #+#    #+#             */
/*   Updated: 2022/05/17 20:44:59 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_map_to_win(t_long *so_long, int keycode)
{
	int	i;
	int	j;

	i = 0;
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j])
		{
			if (so_long->map[i][j] == '1')
				mlx_put_image_to_window(so_long->mlx, so_long->win, so_long->wall, j * 30, i * 30);
			if (so_long->map[i][j] == 'P')
			{
				if (keycode == 0)
					mlx_put_image_to_window(so_long->mlx, so_long->win, so_long->player_left, j * 30, i * 30);
				if (keycode == 2)
					mlx_put_image_to_window(so_long->mlx, so_long->win, so_long->player_right, j * 30, i * 30);
				if (keycode == 1)
					mlx_put_image_to_window(so_long->mlx, so_long->win, so_long->player_down, j * 30, i * 30);
				if (keycode == 13)
					mlx_put_image_to_window(so_long->mlx, so_long->win, so_long->player_up, j * 30, i * 30);
			}
			if (so_long->map[i][j] == 'C')
			{
				if ((i == 8 && j == 13) || (i == 17 && j == 17))
					mlx_put_image_to_window(so_long->mlx, so_long->win, so_long->heart_two, j * 30, i * 30);
				else if ((i == 15 && j == 3) || (i == 4 && j == 20))
					mlx_put_image_to_window(so_long->mlx, so_long->win, so_long->heart, j * 30, i * 30);
				else
					mlx_put_image_to_window(so_long->mlx, so_long->win, so_long->collectabls, j * 30, i * 30);
			}
			if (so_long->map[i][j] == 'E')
			{
				if (so_long->number_of_c != 0)
					mlx_put_image_to_window(so_long->mlx, so_long->win, so_long->exit_close, j * 30, i * 30);
				else
					mlx_put_image_to_window(so_long->mlx, so_long->win, so_long->exit_open, j * 30, i * 30);
			}
			if (so_long->map[i][j] == '0')
				mlx_put_image_to_window(so_long->mlx, so_long->win, so_long->black, j * 30, i * 30);
			j++;
		}
		i++;
	}
}

t_cordinates	get_cordinates(t_long *so_long, char point)
{
	t_cordinates	cordinates;
	int				i;
	int				j;

	i = 1;
	while (so_long->map[i])
	{
		j = 1;
		while (so_long->map[i][j])
		{
			if (so_long->map[i][j] == point)
			{
				cordinates.x = j;
				cordinates.y = i;
			}
			j++;
		}
		i++;
	}
	return (cordinates);
}

int	key_hook(int keycode, t_long *so_long)
{
	t_cordinates	p;

	p = get_cordinates(so_long, 'P');
	handel_moves(so_long, p, keycode);
	put_map_to_win(so_long, keycode);
	return (1);
}
