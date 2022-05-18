/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel2_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 20:21:47 by zmoussam          #+#    #+#             */
/*   Updated: 2022/05/19 00:18:52 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	esc_hook(t_long *so)
{
	mlx_destroy_window(so->mlx,so->win);
	//free(so->map);
	exit(0);
}

t_cordinates	get_cordinates(t_long *so_long, char point)
{
	t_cordinates	cordinates;
	int				i;
	int				j;

	i = 0;
	while (so_long->map[++i])
	{
		j = 0;
		while (so_long->map[i][++j])
		{
			if (so_long->map[i][j] == point)
			{
				cordinates.x = j;
				cordinates.y = i;
			}
		}
	}
	return (cordinates);
}

int	key_hook(int keycode, t_long *so_long)
{
	t_cordinates	p;
	p = get_cordinates(so_long, 'P');
	handel_moves(so_long, p, keycode);
	put_map_to_win(so_long, keycode);
	// mlx_put_image_to_window(so_long->mlx,so->);
	return (1);
}
