/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_enemie.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 03:33:13 by zmoussam          #+#    #+#             */
/*   Updated: 2022/05/21 03:33:16 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
			{
				*bolean = 1;
				so->map[p.y][p.x - 1] = point;
				so->map[p.y][p.x] = 'C';
			}
			else if (so->map[p.y][p.x - 1] == '0')
			{
				*bolean = 0;
				so->map[p.y][p.x - 1] = point;
				so->map[p.y][p.x] = 'C';
			}
		}
		if (tmp == 0)
		{
			if (so->map[p.y][p.x - 1] == '0')
			{
				*bolean = 0;
				so->map[p.y][p.x - 1] = point;
				so->map[p.y][p.x] = '0';
			}
			else if (so->map[p.y][p.x - 1] == 'C')
			{
				*bolean = 1;
				so->map[p.y][p.x - 1] = point;
				so->map[p.y][p.x] = '0';
			}
		}
	}
	else if (so->map[p.y][p.x - 1] == 'P')
	{
		ft_printf("game over!!!\n");
		mlx_destroy_window(so->mlx, so->win);
		exit(0);
	}
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
			{
				*bolean = 1;
				so->map[p.y][p.x + 1] = point;
				so->map[p.y][p.x] = 'C';
			}
			else if (so->map[p.y][p.x + 1] == '0')
			{
				*bolean = 0;
				so->map[p.y][p.x + 1] = point;
				so->map[p.y][p.x] = 'C';
			}
		}
		if (tmp == 0)
		{
			if (so->map[p.y][p.x + 1] == '0')
			{
				*bolean = 0;
				so->map[p.y][p.x + 1] = point;
				so->map[p.y][p.x] = '0';
			}
			else if (so->map[p.y][p.x + 1] == 'C')
			{
				*bolean = 1;
				so->map[p.y][p.x + 1] = point;
				so->map[p.y][p.x] = '0';
			}
		}
	}
	else if (so->map[p.y][p.x + 1] == 'P')
	{
		ft_printf("game over!!!\n");
		mlx_destroy_window(so->mlx, so->win);
		exit(0);
	}
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
			{
				*bolean = 1;
				so->map[p.y - 1][p.x] = point;
				so->map[p.y][p.x] = 'C';
			}
			else if (so->map[p.y - 1][p.x] == '0')
			{
				*bolean = 0;
				so->map[p.y - 1][p.x] = point;
				so->map[p.y][p.x] = 'C';
			}
		}
		if (tmp == 0)
		{
			if (so->map[p.y - 1][p.x] == '0')
			{
				*bolean = 0;
				so->map[p.y - 1][p.x] = point;
				so->map[p.y][p.x] = '0';
			}
			else if (so->map[p.y - 1][p.x] == 'C')
			{
				*bolean = 1;
				so->map[p.y - 1][p.x] = point;
				so->map[p.y][p.x] = '0';
			}
		}
	}
	else if (so->map[p.y - 1][p.x] == 'P')
	{
		ft_printf("game over!!!\n");
		mlx_destroy_window(so->mlx, so->win);
		exit(0);
	}
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
			{
				*bolean = 1;
				so->map[p.y + 1][p.x] = point;
				so->map[p.y][p.x] = 'C';
			}
			else if (so->map[p.y + 1][p.x] == '0')
			{
				*bolean = 0;
				so->map[p.y + 1][p.x] = point;
				so->map[p.y][p.x] = 'C';
			}
		}
		if (tmp == 0)
		{
			if (so->map[p.y + 1][p.x] == '0')
			{
				*bolean = 0;
				so->map[p.y + 1][p.x] = point;
				so->map[p.y][p.x] = '0';
			}
			else if (so->map[p.y + 1][p.x] == 'C')
			{
				*bolean = 1;
				so->map[p.y + 1][p.x] = point;
				so->map[p.y][p.x] = '0';
			}
		}
	}
	else if (so->map[p.y + 1][p.x] == 'P')
	{
		ft_printf("game over!!!\n");
		mlx_destroy_window(so->mlx, so->win);
		exit(0);
	}
}