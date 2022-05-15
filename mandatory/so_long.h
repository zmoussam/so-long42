/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:42:07 by zmoussam          #+#    #+#             */
/*   Updated: 2022/05/15 21:13:23 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef SO_LONG
# define SO_LONG
#define BUFFER_SIZE 1024
#include "../get_next_line/get_next_line.h"
#include "../printf/ft_printf.h"
#include <mlx.h>

typedef struct s_long{
    char **map;
    void *mlx;
    void *win;
    int count_map_line;
    int number_of_c;
    void *wall;
    void *player_up;
    void *player_down;
    void *player_left;
    void *player_right;
    void *collectabls;
    void *heart;
    void *black;
}t_long;

typedef struct s_cordinates
{
    int x;
    int y;
}t_cordinates;


int	ft_strcmp(char *s1, char *s2);
void handel_error(char *error_name);
int get_nbr_line(char *map_file);
char **read_map_file(char *map_file, int nbr_line);
void check_extention(char *file_name);
void check_map_form(char **map, int count_map_line);
void check_map_wals(char **map, int count_map_line);
void check_map_component(char **map, int count_map_line);
int check_component_exist(char **map, int count_map_line);
t_cordinates get_cordinates(t_long *so_long,char point);
void handel_moves(t_long *so_long, int x, int y,int keycode);
void moves_up(t_long *so_long,int x,int y);
void moves_down(t_long *so_long,int x,int y);
void moves_right(t_long *so_long,int x,int y);
void moves_left(t_long *so_long,int x,int y);
int key_hook(int keycode,t_long *so_long);

#endif