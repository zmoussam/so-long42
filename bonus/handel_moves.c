/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 23:43:51 by zmoussam          #+#    #+#             */
/*   Updated: 2022/05/23 19:19:56 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	moves_left(t_long *so, t_cordinates p)
{
	if (so->map[p.y][p.x - 1] != '1' && so->map[p.y][p.x - 1] != 'E')
	{
		so->moves++;
		if (so->map[p.y][p.x - 1] == 'C' )
		{
			so->number_of_c--;
			so->map[p.y][p.x - 1] = 'P';
			so->map[p.y][p.x] = '0';
		}
		else if (so->map[p.y][p.x - 1] == '0')
		{
			so->map[p.y][p.x - 1] = 'P';
			so->map[p.y][p.x] = '0';
		}
		else if (so->map[p.y][p.x - 1] == 'G' || so->map[p.y][p.x - 1] == 'R')
			game_over(so);
	}	
	if (so->map[p.y][p.x - 1] == 'E' && so->number_of_c == 0)
	{
		so->moves++;
		so->map[p.y][p.x] = '0';
		ft_printf("you win!!\n");
		mlx_destroy_window(so->mlx, so->win);
		exit(1);
	}
}

void	moves_right(t_long *so, t_cordinates p)
{
	if (so->map[p.y][p.x + 1] != '1' && so->map[p.y][p.x + 1] != 'E')
	{
		so->moves++;
		if (so->map[p.y][p.x + 1] == 'C')
		{
			so->number_of_c--;
			so->map[p.y][p.x + 1] = 'P';
			so->map[p.y][p.x] = '0';
		}
		else if (so->map[p.y][p.x + 1] == '0')
		{
			so->map[p.y][p.x + 1] = 'P';
			so->map[p.y][p.x] = '0';
		}
		else if (so->map[p.y][p.x + 1] == 'G' || so->map[p.y][p.x + 1] == 'R')
			game_over(so);
	}
	else if (so->map[p.y][p.x + 1] == 'E' && so->number_of_c == 0)
	{
		so->moves++;
		so->map[p.y][p.x] = '0';
		ft_printf("you win!!\n");
		mlx_destroy_window(so->mlx, so->win);
		exit(1);
	}
}

void	moves_down(t_long *so, t_cordinates p)
{
	if (so->map[p.y + 1][p.x] != '1' && so->map[p.y + 1][p.x] != 'E')
	{
		so->moves++;
		if (so->map[p.y + 1][p.x] == 'C')
		{
			so->number_of_c--;
			so->map[p.y + 1][p.x] = 'P';
			so->map[p.y][p.x] = '0';
		}
		else if (so->map[p.y + 1][p.x] == '0')
		{
			so->map[p.y + 1][p.x] = 'P';
			so->map[p.y][p.x] = '0';
		}
		else if (so->map[p.y + 1][p.x] == 'G' || so->map[p.y + 1][p.x] == 'R')
			game_over(so);
	}
	else if (so->map[p.y + 1][p.x] == 'E' && so->number_of_c == 0)
	{
		so->moves++;
		so->map[p.y][p.x] = '0';
		ft_printf("you win!!\n");
		mlx_destroy_window(so->mlx, so->win);
		exit(1);
	}
}

void	moves_up(t_long *so, t_cordinates p)
{
	if (so->map[p.y - 1][p.x] != '1' && so->map[p.y - 1][p.x] != 'E')
	{
		so->moves++;
		if (so->map[p.y - 1][p.x] == 'C')
		{
			so->number_of_c--;
			so->map[p.y - 1][p.x] = 'P';
			so->map[p.y][p.x] = '0';
		}
		else if (so->map[p.y - 1][p.x] == '0')
		{
			so->map[p.y - 1][p.x] = 'P';
			so->map[p.y][p.x] = '0';
		}
		else if (so->map[p.y - 1][p.x] == 'G' || so->map[p.y - 1][p.x] == 'R')
			game_over(so);
	}
	if (so->map[p.y - 1][p.x] == 'E' && so->number_of_c == 0)
	{
		so->moves++;
		so->map[p.y][p.x] = '0';
		ft_printf("you win!!\n");
		mlx_destroy_window(so->mlx, so->win);
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
		game_over(so_long);
}
