/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_enemie.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 03:33:13 by zmoussam          #+#    #+#             */
/*   Updated: 2022/05/21 05:55:17 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void move_enemie(t_long *so, int x, int y, int tmp, int *bolean, char point, char c, int direction)
{
	*bolean = tmp;
	so->map[y][x] = point;
	if (direction == 1)
		so->map[y][x + 1] = c;
	if (direction == 2)
		so->map[y][x - 1] = c;
	if (direction == 3)
		so->map[y + 1][x] = c;
	if (direction == 4)
		so->map[y - 1][x] = c;
}

void	moves_enemie_left(t_long *so, char point,
		t_cordinates p, int *bolean)
{
	int	tmp;

	tmp = *bolean;
	if (so->map[p.y][p.x - 1] != '1' && so->map[p.y][p.x - 1] != 'E' &&
			so->map[p.y][p.x - 1] != 'P')
	{
		if (tmp == 1)
		{
			if (so->map[p.y][p.x - 1] == 'C')
				move_enemie(so, p.x - 1, p.y, 1, bolean, point, 'C', 1);
			else if (so->map[p.y][p.x - 1] == '0')
				move_enemie(so, p.x - 1, p.y, 0, bolean, point, 'C', 1);
		}
		if (tmp == 0)
		{
			if (so->map[p.y][p.x - 1] == '0')
				move_enemie(so, p.x - 1, p.y, 0, bolean, point, '0', 1);
			else if (so->map[p.y][p.x - 1] == 'C')
				move_enemie(so, p.x - 1, p.y, 1, bolean, point, '0', 1);
		}
	}
	else if (so->map[p.y][p.x - 1] == 'P')
		game_over(so);
}

void	moves_enemie_right(t_long *so, char point,
		t_cordinates p, int *bolean)
{
	int	tmp;

	tmp = *bolean;
	if (so->map[p.y][p.x + 1] != '1' && so->map[p.y][p.x + 1] != 'E' &&
			so->map[p.y][p.x + 1] != 'P')
	{
		if (tmp == 1)
		{
			if (so->map[p.y][p.x + 1] == 'C')
				move_enemie(so, p.x + 1, p.y, 1, bolean, point, 'C', 2);
			else if (so->map[p.y][p.x + 1] == '0')
				move_enemie(so, p.x + 1, p.y, 0, bolean, point, 'C', 2);
		}
		if (tmp == 0)
		{
			if (so->map[p.y][p.x + 1] == '0')
				move_enemie(so, p.x + 1, p.y, 0, bolean, point, '0', 2);
			else if (so->map[p.y][p.x + 1] == 'C')
				move_enemie(so, p.x + 1, p.y, 1, bolean, point, '0', 2);
		}
	}
	else if (so->map[p.y][p.x + 1] == 'P')
		game_over(so);
}

void	moves_enemie_up(t_long *so, char point,
		t_cordinates p, int *bolean)
{
	int	tmp;

	tmp = *bolean;
	if (so->map[p.y - 1][p.x] != '1' && so->map[p.y - 1][p.x] != 'E' &&
			so->map[p.y - 1][p.x] != 'P')
	{
		if (tmp == 1)
		{
			if (so->map[p.y - 1][p.x] == 'C')
				move_enemie(so, p.x, p.y - 1, 1, bolean, point, 'C', 3);
			else if (so->map[p.y - 1][p.x] == '0')
				move_enemie(so, p.x, p.y - 1, 0, bolean, point, 'C', 3);
		}
		if (tmp == 0)
		{
			if (so->map[p.y - 1][p.x] == '0')
				move_enemie(so, p.x, p.y - 1, 0, bolean, point, '0', 3);
			else if (so->map[p.y - 1][p.x] == 'C')
				move_enemie(so, p.x, p.y - 1, 1, bolean, point, '0', 3);
		}
	}
	else if (so->map[p.y - 1][p.x] == 'P')
		game_over(so);
}

void	moves_enemie_down(t_long *so, char point,
		t_cordinates p, int *bolean)
{
	int	tmp;

	tmp = *bolean;
	if (so->map[p.y + 1][p.x] != '1' && so->map[p.y + 1][p.x] != 'E' &&
			so->map[p.y + 1][p.x] != 'P')
	{
		if (tmp == 1)
		{
			if (so->map[p.y + 1][p.x] == 'C')
				move_enemie(so, p.x, p.y + 1, 1, bolean, point, 'C', 4);
			else if (so->map[p.y + 1][p.x] == '0')
				move_enemie(so, p.x, p.y + 1, 0, bolean, point, 'C', 4);
		}
		if (tmp == 0)
		{
			if (so->map[p.y + 1][p.x] == '0')
				move_enemie(so, p.x, p.y + 1, 0, bolean, point, '0', 4);
			else if (so->map[p.y + 1][p.x] == 'C')
				move_enemie(so, p.x, p.y + 1, 1, bolean, point, '0', 4);
		}
	}
	else if (so->map[p.y + 1][p.x] == 'P')
		game_over(so);
}
