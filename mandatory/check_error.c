/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:20:36 by zmoussam          #+#    #+#             */
/*   Updated: 2022/05/15 15:31:29 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void handel_error(char *error_name)
{
    perror(error_name);
    exit(-1);   
}

void check_map_component(char **map, int count_map_line)
{
    int i;
    int j;
    j = 1;
    i = 1;
    while(i < count_map_line - 1)
    {
        j = 1;
           while(j < ft_strlen(map[0]) - 2)
           {
               if(map[i][j] != '1' && map[i][j] != '0' 
               && map[i][j] != 'E' && map[i][j] != 'P' && map[i][j] != 'C')
                handel_error("map contains some intruders characters!!");
               j++;
           }
           i++;
    }
}

int check_component_exist(char **map, int count_map_line)
{
    int E;
    int P;
    int C;
    int i;
    int j;
    
    E = 0;
    P = 0;
    C = 0;
    i = 1;
    while(i < count_map_line - 1)
    {
        j = 0;
        while(j < ft_strlen(map[0]) - 2)
        {
            if(map[i][j] == 'E')
                E++;
            if(map[i][j] == 'P')
                P++;
            if(map[i][j] == 'C')
                C++;
            j++;
        }
        i++;
    }
    if(E == 0)
        handel_error("there is more than one exit !!!\n");
    if(P != 1)
        handel_error("there is more than one player !!!\n");
    if(C == 0)
        handel_error("you need collectable !!!\n");
    return(C);
}
