/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:20:36 by zmoussam          #+#    #+#             */
/*   Updated: 2022/05/23 19:13:57 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_number_of_component(t_component all)
{
	if (all.exit == 0)
		handel_error("number of exit invalid !!!\n");
	if (all.player != 1)
		handel_error("number of player invalid !!!\n");
	if (all.colectabls == 0)
		handel_error("you need collectable !!!\n");
	if (all.e_r == 0)
		handel_error("you need red enemie !!!\n");
	if (all.e_g == 0)
		handel_error("you need green enemie !!!\n");
}

void	handel_error(char *error_name)
{
	perror(error_name);
	exit(-1);
}

void	check_map_component(char **map, size_t count_map_line)
{
	size_t	i;
	size_t	j;

	j = 1;
	i = 1;
	while (i < count_map_line - 1)
	{
		j = 1;
		while (j < ft_strlen(map[0]) - 2)
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'E'
					&& map[i][j] != 'P' && map[i][j] != 'C' && map[i][j] != 'X'
					&& map[i][j] != 'G' && map[i][j] != 'R')
				handel_error("map contains some intruders characters!!\n");
			j++;
		}
		i++;
	}
}

int	check_component_exist(char **map, size_t count_map_line)
{
	t_component	all;
	size_t		i;
	size_t		j;

	i = 0;
	initialize_all(&all);
	while (++i < count_map_line - 1)
	{
		j = -1;
		while (++j < ft_strlen(map[0]) - 2)
		{
			if (map[i][j] == 'E')
				all.exit++;
			if (map[i][j] == 'P')
				all.player++;
			if (map[i][j] == 'C')
				all.colectabls++;
			if (map[i][j] == 'R')
				all.e_r++;
			if (map[i][j] == 'G')
				all.e_g++;
		}
	}
	check_number_of_component(all);
	return (all.colectabls);
}
