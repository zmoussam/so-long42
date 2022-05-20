/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 23:43:51 by zmoussam          #+#    #+#             */
/*   Updated: 2022/05/20 20:07:37 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	moves_left(t_long *so_long, t_cordinates p)
{
	if (so_long->map[p.y][p.x - 1] != '1' && so_long->map[p.y][p.x - 1] != 'E')
	{
		so_long->moves++;
		if (so_long->map[p.y][p.x - 1] == 'C' )
		{
			so_long->number_of_c--;
			so_long->map[p.y][p.x - 1] = 'P';
			so_long->map[p.y][p.x] = '0';
		}
		else if(so_long->map[p.y][p.x - 1] == '0')
		{
			so_long->map[p.y][p.x - 1] = 'P';
			so_long->map[p.y][p.x] = '0';
		}
		else if (so_long->map[p.y][p.x - 1] == 'G' || so_long->map[p.y][p.x - 1] == 'R')
		{
			ft_printf("game over!!!\n");
			mlx_destroy_window(so_long->mlx, so_long->win);
			exit(0);
		}
	}	
	if (so_long->map[p.y][p.x - 1] == 'E' && so_long->number_of_c == 0)
	{
		so_long->moves++;
		so_long->map[p.y][p.x] = '0';
		ft_printf("you won!!\n");
		mlx_destroy_window(so_long->mlx, so_long->win);
		exit(-1);
	}
}

void	moves_right(t_long *so_long, t_cordinates p)
{
	if (so_long->map[p.y][p.x + 1] != '1' && so_long->map[p.y][p.x + 1] != 'E')
	{
		so_long->moves++;
		if (so_long->map[p.y][p.x + 1] == 'C')
		{
		so_long->number_of_c--;
		so_long->map[p.y][p.x + 1] = 'P';
		so_long->map[p.y][p.x] = '0';	
		}
		else if(so_long->map[p.y][p.x + 1] == '0')
		{
			so_long->map[p.y][p.x + 1] = 'P';
			so_long->map[p.y][p.x] = '0';
		}
		else if (so_long->map[p.y][p.x + 1] == 'G' || so_long->map[p.y][p.x + 1] == 'R')
		{
			ft_printf("game over!!!\n");
			mlx_destroy_window(so_long->mlx, so_long->win);
			exit(0);
		}
	}
	else if (so_long->map[p.y][p.x + 1] == 'E' && so_long->number_of_c == 0)
	{
		so_long->moves++;
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
		so_long->moves++;
		if (so_long->map[p.y + 1][p.x] == 'C')
		{
			so_long->number_of_c--;
			so_long->map[p.y + 1][p.x] = 'P';
			so_long->map[p.y][p.x] = '0';	
		}
		else if(so_long->map[p.y + 1][p.x] == '0')
		{
			so_long->map[p.y + 1][p.x] = 'P';
			so_long->map[p.y][p.x] = '0';
		}
		else if (so_long->map[p.y + 1][p.x] == 'G' || so_long->map[p.y + 1][p.x] == 'R')
		{
			ft_printf("game over!!!\n");
			mlx_destroy_window(so_long->mlx, so_long->win);
			exit(0);
		}
	}
	else if (so_long->map[p.y + 1][p.x] == 'E' && so_long->number_of_c == 0)
	{
		so_long->moves++;
		so_long->map[p.y][p.x] = '0';
		ft_printf("you won!!\n");
		mlx_destroy_window(so_long->mlx, so_long->win);
		exit(-1);
	}
}

void	moves_up(t_long *so_long, t_cordinates p)
{
	if (so_long->map[p.y - 1][p.x] != '1' && so_long->map[p.y - 1][p.x] != 'E')
	{
		so_long->moves++;
		if (so_long->map[p.y - 1][p.x] == 'C')
		{
		so_long->number_of_c--;
		so_long->map[p.y - 1][p.x] = 'P';
		so_long->map[p.y][p.x] = '0';	
		}
		else if(so_long->map[p.y - 1][p.x] == '0')
		{
			so_long->map[p.y - 1][p.x] = 'P';
			so_long->map[p.y][p.x] = '0';
		}
		else if (so_long->map[p.y - 1][p.x] == 'G' || so_long->map[p.y - 1][p.x] == 'R')
		{
			ft_printf("game over!!!\n");
			mlx_destroy_window(so_long->mlx, so_long->win);
			exit(0);
		}
	}
	if (so_long->map[p.y - 1][p.x] == 'E' && so_long->number_of_c == 0)
	{
		so_long->moves++;
		so_long->map[p.y][p.x] = '0';
		ft_printf("you won!!\n");
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
		ft_printf("game over!!!\n");
		mlx_destroy_window(so_long->mlx, so_long->win);
		exit(-1);
	}
}
