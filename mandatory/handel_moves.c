/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 23:43:51 by zmoussam          #+#    #+#             */
/*   Updated: 2022/05/18 23:19:10 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moves_left(t_long *so_long, t_cordinates p)
{
	if (so_long->map[p.y][p.x - 1] != '1' && so_long->map[p.y][p.x - 1] != 'E')
	{
		if (so_long->map[p.y][p.x - 1] == 'C')
			so_long->number_of_c--;
		so_long->map[p.y][p.x - 1] = 'P';
		so_long->map[p.y][p.x] = '0';
		so_long->moves++;
		ft_printf("moves = %d\n",so_long->moves);
	}
	if (so_long->map[p.y][p.x - 1] == 'E' && so_long->number_of_c == 0)
	{
		so_long->moves++;
		ft_printf("moves = %d\n",so_long->moves);
		so_long->map[p.y][p.x] = '0';
		mlx_destroy_window(so_long->mlx, so_long->win);
		exit(-1);
	}
}

void	moves_right(t_long *so_long, t_cordinates p)
{
	if (so_long->map[p.y][p.x + 1] != '1' && so_long->map[p.y][p.x + 1] != 'E')
	{
		if (so_long->map[p.y][p.x + 1] == 'C')
			so_long->number_of_c--;
		so_long->map[p.y][p.x + 1] = 'P';
		so_long->map[p.y][p.x] = '0';
		so_long->moves++;
		ft_printf("moves = %d\n",so_long->moves);
	}
	if (so_long->map[p.y][p.x + 1] == 'E' && so_long->number_of_c == 0)
	{
		so_long->moves++;
		ft_printf("moves = %d\n",so_long->moves);
		so_long->map[p.y][p.x] = '0';
		ft_printf("you won!!\n");
		mlx_destroy_window(so_long->mlx, so_long->win);
		exit(-1);
	}
}

void	moves_down(t_long *so_long, t_cordinates p)
{
	if (so_long->map[p.y + 1][p.x] != '1' && so_long->map[p.y + 1][p.x] != 'E')
	{
		if (so_long->map[p.y + 1][p.x] == 'C')
			so_long->number_of_c--;
		so_long->map[p.y + 1][p.x] = 'P';
		so_long->map[p.y][p.x] = '0';
		so_long->moves++;
		ft_printf("moves = %d\n",so_long->moves);
	}
	if (so_long->map[p.y + 1][p.x] == 'E' && so_long->number_of_c == 0)
	{
		so_long->moves++;
		ft_printf("moves = %d\n",so_long->moves);
		so_long->map[p.y][p.x] = '0';
		mlx_destroy_window(so_long->mlx, so_long->win);
		exit(-1);
	}
}

void	moves_up(t_long *so_long, t_cordinates p)
{
	if (so_long->map[p.y - 1][p.x] != '1' && so_long->map[p.y - 1][p.x] != 'E')
	{
		if (so_long->map[p.y - 1][p.x] == 'C')
			so_long->number_of_c--;
		so_long->map[p.y - 1][p.x] = 'P';
		so_long->map[p.y][p.x] = '0';
		so_long->moves++;
		ft_printf("moves = %d\n",so_long->moves);
	}
	if (so_long->map[p.y - 1][p.x] == 'E' && so_long->number_of_c == 0)
	{
		so_long->moves++;
		ft_printf("moves = %d\n",so_long->moves);
		so_long->map[p.y][p.x] = '0';
		mlx_destroy_window(so_long->mlx, so_long->win);
		exit(-1);
	}
}

void	handel_moves(t_long *so_long, t_cordinates p, int keycode)
{
	if (keycode == 0)
		moves_left(so_long, p);
	if (keycode == 2)
		moves_right(so_long, p);
	if (keycode == 1)
		moves_down(so_long, p);
	if (keycode == 13)
		moves_up(so_long, p);
	if (keycode == 53)
	{
		mlx_destroy_window(so_long->mlx, so_long->win);
		exit(-1);
	}
}
