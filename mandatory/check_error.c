/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:20:36 by zmoussam          #+#    #+#             */
/*   Updated: 2022/05/17 20:26:11 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	int	e;
	int	p;
	int	c;
	int	i;
	int	j;

	e = 0;
	p = 0;
	c = 0;
	i = 1;
	while (i < count_map_line - 1)
	{
		j = 0;
		while (j < ft_strlen(map[0]) - 2)
		{
			if (map[i][j] == 'E')
				e++;
			if (map[i][j] == 'P')
				p++;
			if (map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	if (e == 0)
		handel_error("there is more than one exit !!!\n");
	if (p != 1)
		handel_error("there is more than one player !!!\n");
	if (c == 0)
		handel_error("you need collectable !!!\n");
	return (c);
}
