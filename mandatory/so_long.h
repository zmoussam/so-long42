/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:42:07 by zmoussam          #+#    #+#             */
/*   Updated: 2022/05/12 18:44:50 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef SO_LONG
# define SO_LONG
#define BUFFER_SIZE 1024
#include "../get_next_line/get_next_line.h"
#include "../printf/ft_printf.h"

void handel_error(char *error_name);
int get_nbr_line(char *map_file);
char **read_map_file(char *map_file, int nbr_line);

#endif