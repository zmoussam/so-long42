/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_enemie.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 03:33:13 by zmoussam          #+#    #+#             */
/*   Updated: 2022/05/23 19:00:46 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_enemie(t_long *so, t_cordinates p, int tmp, char c)
{
	*(so->bolean) = tmp;
	so->map[p.y][p.x] = c;
	if (so->direction == 1)
		so->map[p.y][p.x - 1] = so->enemie_color;
	if (so->direction == 2)
		so->map[p.y][p.x + 1] = so->enemie_color;
	if (so->direction == 3)
		so->map[p.y - 1][p.x] = so->enemie_color;
	if (so->direction == 4)
		so->map[p.y + 1][p.x] = so->enemie_color;
}

void	moves_enemie_left(t_long *so, char point,
		t_cordinates p)
{
	int	tmp;

	so->direction = 1;
	so->enemie_color = point;
	tmp = *(so->bolean);
	if (so->map[p.y][p.x - 1] != '1' && so->map[p.y][p.x - 1] != 'E' &&
			so->map[p.y][p.x - 1] != 'P')
	{
		if (tmp == 1)
		{
			if (so->map[p.y][p.x - 1] == 'C')
				move_enemie(so, p, 1, 'C');
			else if (so->map[p.y][p.x - 1] == '0')
				move_enemie(so, p, 0, 'C');
		}
		if (tmp == 0)
		{
			if (so->map[p.y][p.x - 1] == '0')
				move_enemie(so, p, 0, '0');
			else if (so->map[p.y][p.x - 1] == 'C')
				move_enemie(so, p, 1, '0');
		}
	}
	else if (so->map[p.y][p.x - 1] == 'P')
		game_over(so);
}

void	moves_enemie_right(t_long *so, char point,
		t_cordinates p)
{
	int	tmp;

	so->direction = 2;
	so->enemie_color = point;
	tmp = *(so->bolean);
	if (so->map[p.y][p.x + 1] != '1' && so->map[p.y][p.x + 1] != 'E' &&
			so->map[p.y][p.x + 1] != 'P')
	{
		if (tmp == 1)
		{
			if (so->map[p.y][p.x + 1] == 'C')
				move_enemie(so, p, 1, 'C');
			else if (so->map[p.y][p.x + 1] == '0')
				move_enemie(so, p, 0, 'C');
		}
		if (tmp == 0)
		{
			if (so->map[p.y][p.x + 1] == '0')
				move_enemie(so, p, 0, '0');
			else if (so->map[p.y][p.x + 1] == 'C')
				move_enemie(so, p, 1, '0');
		}
	}
	else if (so->map[p.y][p.x + 1] == 'P')
		game_over(so);
}

void	moves_enemie_up(t_long *so, char point,
		t_cordinates p)
{
	int	tmp;

	so->direction = 3;
	so->enemie_color = point;
	tmp = *(so->bolean);
	if (so->map[p.y - 1][p.x] != '1' && so->map[p.y - 1][p.x] != 'E' &&
			so->map[p.y - 1][p.x] != 'P')
	{
		if (tmp == 1)
		{
			if (so->map[p.y - 1][p.x] == 'C')
				move_enemie(so, p, 1, 'C');
			else if (so->map[p.y - 1][p.x] == '0')
				move_enemie(so, p, 0, 'C');
		}
		if (tmp == 0)
		{
			if (so->map[p.y - 1][p.x] == '0')
				move_enemie(so, p, 0, '0');
			else if (so->map[p.y - 1][p.x] == 'C')
				move_enemie(so, p, 1, '0');
		}
	}
	else if (so->map[p.y - 1][p.x] == 'P')
		game_over(so);
}

void	moves_enemie_down(t_long *so, char point,
		t_cordinates p)
{
	int	tmp;

	so->direction = 4;
	so->enemie_color = point;
	tmp = *(so->bolean);
	if (so->map[p.y + 1][p.x] != '1' && so->map[p.y + 1][p.x] != 'E' &&
			so->map[p.y + 1][p.x] != 'P')
	{
		if (tmp == 1)
		{
			if (so->map[p.y + 1][p.x] == 'C')
				move_enemie(so, p, 1, 'C');
			else if (so->map[p.y + 1][p.x] == '0')
				move_enemie(so, p, 0, 'C');
		}
		if (tmp == 0)
		{
			if (so->map[p.y + 1][p.x] == '0')
				move_enemie(so, p, 0, '0');
			else if (so->map[p.y + 1][p.x] == 'C')
				move_enemie(so, p, 1, '0');
		}
	}
	else if (so->map[p.y + 1][p.x] == 'P')
		game_over(so);
}
