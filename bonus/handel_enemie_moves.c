/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_enemie_moves.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:52:27 by zmoussam          #+#    #+#             */
/*   Updated: 2022/05/21 03:33:43 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	moves_enemie_red(t_long *so, t_cordinates e, int *bolean)
{
	int	randd;
	int	r;
	int	l;
	int	u;

	l = 1;
	u = 4;
	r = (rand() % (u - l + 1) + l);
	randd = (rand() % (u - l + 1) + l);
	if (randd == 1 && r == 1)
		moves_enemie_left(so, 'R', e, bolean);
	if (randd == 2 && r == 2)
		moves_enemie_down(so, 'R', e, bolean);
	if (randd == 3 && r == 3)
		moves_enemie_right(so, 'R', e, bolean);
	if (randd == 4 && r == 4)
		moves_enemie_up(so, 'R', e, bolean);
}

void	moves_enemie_green(t_long *so, t_cordinates e, int *bolean)
{
	int	randd;
	int	r;
	int	l;
	int	u;

	l = 1;
	u = 4;
	r = (rand() % (u - l + 1) + l);
	randd = (rand() % (u - l + 1) + l);
	if (randd == 1 && r == 1)
		moves_enemie_left(so, 'G', e, bolean);
	else if (randd == 2 && r == 2)
		moves_enemie_down(so, 'G', e, bolean);
	else if (randd == 3 && r == 3)
		moves_enemie_right(so, 'G', e, bolean);
	else if (randd == 4 && r == 4)
		moves_enemie_up(so, 'G', e, bolean);
}

void	handel_enemie_moves(t_long *so_long, int *bolean, t_cordinates p)
{
	if (so_long->map[p.y][p.x] == 'R')
		moves_enemie_red(so_long, p, bolean);
	if (so_long->map[p.y][p.x] == 'G')
		moves_enemie_green(so_long, p, bolean);
}
