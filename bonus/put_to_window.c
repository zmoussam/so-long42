/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:26:04 by zmoussam          #+#    #+#             */
/*   Updated: 2022/05/21 03:07:05 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_exit(t_long *so, int i, int j)
{
	if (so->number_of_c != 0)
		mlx_put_image_to_window(so->mlx, so->win, so->e_cl, j * 30, i * 30);
	else
		mlx_put_image_to_window(so->mlx, so->win, so->e_op, j * 30, i * 30);
}

void	put_player(t_long *so, int keycode, int i, int j)
{
	if (keycode == 0)
		mlx_put_image_to_window(so->mlx, so->win, so->p_le, j * 30, i * 30);
	if (keycode == 2)
		mlx_put_image_to_window(so->mlx, so->win, so->p_ri, j * 30, i * 30);
	if (keycode == 1)
		mlx_put_image_to_window(so->mlx, so->win, so->p_do, j * 30, i * 30);
	if (keycode == 13)
		mlx_put_image_to_window(so->mlx, so->win, so->p_up, j * 30, i * 30);
	mlx_string_put(so->mlx, so->win, 0, 0, 0xFFFF00,
		ft_strjoin2("moves = ", ft_itoa(so->moves)));
}

void	put_colectabls(t_long *so, int i, int j)
{
	static int	r;

	r++;
	if ((i == 8 && j == 13) || (i == 17 && j == 17) || (i == 3 && j == 15))
		mlx_put_image_to_window(so->mlx, so->win, so->ceris, j * 30, i * 30);
	else if ((i == 15 && j == 3) || (i == 4 && j == 20) || (i == 3 && j == 18))
	{
		if (r < 5000)
			mlx_put_image_to_window(so->mlx, so->win,
				so->heart, j * 30, i * 30);
		else if (r > 5000)
			mlx_put_image_to_window(so->mlx, so->win,
				so->heart_big, j * 30, i * 30);
	}
	else
		mlx_put_image_to_window(so->mlx, so->win, so->col, j * 30, i * 30);
	if (r == 10000)
		r = 0;
}

void	put_map_to_win(t_long *so, int keycode)
{
	int	i;
	int	j;

	i = -1;
	while (so->map[++i])
	{
		j = -1;
		while (so->map[i][++j])
		{
			if (so->map[i][j] == '1')
				mlx_put_image_to_window(so->mlx, so->win,
					so->wall, j * 30, i * 30);
			else if (so->map[i][j] == 'P')
				put_player(so, keycode, i, j);
			else if (so->map[i][j] == 'C')
				put_colectabls(so, i, j);
			else if (so->map[i][j] == 'E')
				put_exit(so, i, j);
			else if (so->map[i][j] == '0')
				mlx_put_image_to_window(so->mlx, so->win,
					so->black, j * 30, i * 30);
			else if (so->map[i][j] == 'G')
				mlx_put_image_to_window(so->mlx, so->win,
					so->green_left, j * 30, i * 30);
			else if (so->map[i][j] == 'R')
				mlx_put_image_to_window(so->mlx, so->win,
					so->red_left, j * 30, i * 30);
		}
	}
}

int	animation(t_long *so_long, int keycode)
{
	t_cordinates	e_g;
	t_cordinates	e_r;
	int				randd;
	int				l;
	int				u;

	l = 1;
	u = 2;
	randd = (rand() % (u - l + 1) + l);
	e_g = get_cordinates(so_long, 'G');
	e_r = get_cordinates(so_long, 'R');
	if (randd == 1)
		handel_enemie_moves(so_long, so_long->bolean_r, e_r);
	else if (randd == 2)
		handel_enemie_moves(so_long, so_long->bolean_g, e_g);
	put_map_to_win(so_long, keycode);
	return (1);
}
