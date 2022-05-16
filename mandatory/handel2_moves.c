/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel2_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 20:21:47 by zmoussam          #+#    #+#             */
/*   Updated: 2022/05/17 00:19:08 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void put_map_to_win(t_long *so_long,int keycode)
{
    int i;
    int j;
    i = 0;
     while(so_long->map[i])
    {
        j = 0;
        while(so_long->map[i][j])
        {
            if(so_long->map[i][j] == '1')
            {
                mlx_put_image_to_window(so_long->mlx,so_long->win,so_long->wall,  j * 60,i * 60);
            }
            if(so_long->map[i][j] == 'P')
            {
                if(keycode == 123)
                mlx_put_image_to_window(so_long->mlx,so_long->win,so_long->player_left,j * 60,i * 60);
                if(keycode == 124)
                mlx_put_image_to_window(so_long->mlx,so_long->win,so_long->player_right,j * 60,i * 60);
                if(keycode == 125)
                mlx_put_image_to_window(so_long->mlx,so_long->win,so_long->player_down,j * 60,i * 60);
                if(keycode == 126)
                mlx_put_image_to_window(so_long->mlx,so_long->win,so_long->player_up,j * 60,i * 60);
            }
            if(so_long->map[i][j] == 'C')
            {
                if((i == 8 && j == 13) || (i == 17 && j == 17))
                    mlx_put_image_to_window(so_long->mlx,so_long->win,so_long->heart_two,j * 60,i * 60);
                else if( (i == 15 && j == 3) || (i == 4 && j == 20))
                    mlx_put_image_to_window(so_long->mlx,so_long->win,so_long->heart,j * 60,i * 60);
                else 
                    mlx_put_image_to_window(so_long->mlx,so_long->win,so_long->collectabls,j * 60,i * 60);
            }
            if(so_long->map[i][j] == 'E')
            {
                if(so_long->number_of_c != 0)
                     mlx_put_image_to_window(so_long->mlx,so_long->win,so_long->exit_close,j * 60,i * 60);
                else
                    mlx_put_image_to_window(so_long->mlx,so_long->win,so_long->exit_open,j * 60,i * 60);
                
            }
            if(so_long->map[i][j] == '0')
            {
                mlx_put_image_to_window(so_long->mlx,so_long->win,so_long->black,j * 60,i * 60);
            }
            j++;
        }
        i++;
    }
}

t_cordinates get_cordinates(t_long *so_long,char point)
{
    t_cordinates cordinates;
    int i;
    int j;
    
    i = 1;
    while(so_long->map[i])
    {
        j = 1;
        while(so_long->map[i][j])
        {
            if(so_long->map[i][j] == point)
                {
                    cordinates.x = j;
                    cordinates.y = i;
                }
            j++;                
        } 
        i++;       
    }
    return(cordinates);
}
int key_hook(int keycode,t_long *so_long)
{
    t_cordinates E;
    t_cordinates P;
    
    E = get_cordinates(so_long,'E');
    P = get_cordinates(so_long,'P');
    printf(" x = %d y = %d\n",P.x,P.y);
    handel_moves(so_long,P.x,P.y,keycode);
    put_map_to_win(so_long,keycode);
    // int t;
    // t = 0; 
    // while(so_long->map[t])
    // {
    //     printf("%s",so_long->map[t]);
    //     // if(t == 5)
    //     //     printf("\n");
    //     t++;
    // }  
    return(1);
    
} 
