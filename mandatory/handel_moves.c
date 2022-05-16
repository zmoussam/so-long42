/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 23:43:51 by zmoussam          #+#    #+#             */
/*   Updated: 2022/05/17 00:22:30 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void moves_left(t_long *so_long,int x,int y)
{
    printf("left\n");
     if (so_long->map[y][x - 1] != '1' && so_long->map[y][x - 1] != 'E')
        {
            if(so_long->map[y][x - 1] == 'C')
                    so_long->number_of_c--;
            so_long->map[y][x - 1] = 'P';
            so_long->map[y][x] = '0';
        }
        if(so_long->map[y][x - 1] == 'E' && so_long->number_of_c == 0)
        {
             //so_long->map[y][x - 1] = 'P';
             so_long->map[y][x] = '0';
              printf("you won!!\n");
              mlx_destroy_window(so_long->mlx,so_long->win);
             exit(-1);
        }
}
void moves_right(t_long *so_long,int x,int y)
{
     printf("right\n");
      if (so_long->map[y][x + 1] != '1' && so_long->map[y][x + 1] != 'E')
        {
            if(so_long->map[y][x + 1] == 'C')
                    so_long->number_of_c--;
            so_long->map[y][x + 1] = 'P';
            so_long->map[y][x] = '0';
        }
        if(so_long->map[y][x + 1] == 'E' && so_long->number_of_c == 0)
        {
             //so_long->map[y][x + 1] = 'P';
             so_long->map[y][x] = '0';
              printf("you won!!\n");
              mlx_destroy_window(so_long->mlx,so_long->win);
             exit(-1);
        }
}
void moves_down(t_long *so_long,int x,int y)
{
     printf("down\n");
     if (so_long->map[y + 1][x] != '1' && so_long->map[y + 1][x] != 'E')
        {
            if(so_long->map[y + 1][x] == 'C')
                    so_long->number_of_c--;
            so_long->map[y + 1][x] = 'P';
            so_long->map[y][x] = '0';
        }
        if(so_long->map[y + 1][x] == 'E' && so_long->number_of_c == 0)
        {
            //  so_long->map[y + 1][x] = 'P';
             so_long->map[y][x] = '0';
              printf("you won!!\n");
              mlx_destroy_window(so_long->mlx,so_long->win);
              exit(-1);
            
        }
}
void moves_up(t_long *so_long,int x,int y)
{
     printf("up\n");
    if(so_long->map[y - 1][x] != '1' && so_long->map[y - 1][x] != 'E')
            {
                if(so_long->map[y - 1][x] == 'C')
                    so_long->number_of_c--;
                 so_long->map[y - 1][x] = 'P';
                 so_long->map[y][x] = '0';
            }
    if(so_long->map[y - 1][x] == 'E' && so_long->number_of_c == 0)
        {
             //so_long->map[y - 1][x] = 'P';
             so_long->map[y][x] = '0';
             printf("you won!!\n");
             mlx_destroy_window(so_long->mlx,so_long->win);
             exit(-1);
        }
}

void handel_moves(t_long *so_long, int x, int y,int keycode)
{
    if(keycode == 123)
        moves_left(so_long,x,y);
    if(keycode == 124)
        moves_right(so_long,x,y);
    if(keycode == 125)
        moves_down(so_long,x,y);
    if(keycode == 126)
        moves_up(so_long,x,y);
}