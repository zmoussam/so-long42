/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:42:07 by zmoussam          #+#    #+#             */
/*   Updated: 2022/05/13 20:05:42 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef SO_LONG
# define SO_LONG
#define BUFFER_SIZE 1024
#include "../get_next_line/get_next_line.h"
#include "../printf/ft_printf.h"

int	ft_strcmp(char *s1, char *s2);
void handel_error(char *error_name);
int get_nbr_line(char *map_file);
char **read_map_file(char *map_file, int nbr_line);
void check_extention(char *file_name);
void check_map_form(char **map, int count_map_line);
void check_map_wals(char **map, int count_map_line);
void check_map_component(char **map, int count_map_line);
void check_component_exist(char **map, int count_map_line);

#endif