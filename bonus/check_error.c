/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:20:36 by zmoussam          #+#    #+#             */
/*   Updated: 2022/05/19 00:01:39 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_number_of_component(t_componente all)
{
	if (all.exit == 0)
		handel_error("number of exit invalid !!!\n");
	if (all.player != 1)
		handel_error("number of player invalid !!!\n");
	if (all.colectabls == 0)
		handel_error("you need collectable !!!\n");
}

void	handel_error(char *error_name)
{
	perror(error_name);
	exit(-1);
}

void	check_map_component(char **map, int count_map_line)
{
	int	i;
	int	j;

	j = 1;
	i = 1;
	while (i < count_map_line - 1)
	{
		j = 1;
		while (j < ft_strlen(map[0]) - 2)
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'E'
					&& map[i][j] != 'P' && map[i][j] != 'C')
				handel_error("map contains some intruders characters!!");
			j++;
		}
		i++;
	}
}

int	check_component_exist(char **map, int count_map_line)
{
	t_componente	all;
	int				i;
	int				j;

	i = 0;
	all.colectabls = 0;
	all.player = 0;
	all.exit = 0;
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
		}
	}
	check_number_of_component(all);
	return (all.colectabls);
}
