/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel2_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 20:21:47 by zmoussam          #+#    #+#             */
/*   Updated: 2022/05/14 22:20:32 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
    // int t;
    // t = 0; 
    // while(so_long->map[t])
    // {
    //     printf("%s",so_long->map[t]);
    //     if(t == 5)
    //         printf("\n");
    //     t++;
    // }  
    return(1);
    
} 
