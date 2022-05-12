/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:50:59 by zmoussam          #+#    #+#             */
/*   Updated: 2022/05/12 18:42:29 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
 
int get_nbr_line(char *map_file)
{
    int     fd;
    int     count_map_line;
     
    fd = open(map_file, O_RDONLY);
    if(fd == -1)
        handel_error("open file");
    while(get_next_line(fd)) 
        count_map_line++;     
    if(count_map_line == 0)
        handel_error("empty map's file!!");
    close(fd);
    return(count_map_line);
}

char **read_map_file(char *map_file, int nbr_line)
{
    char **map;
    int i;
    int fd;
    fd = open(map_file, O_RDONLY);
    map = (char **)malloc(sizeof(char *) * (nbr_line + 1));
    if(!map)
        return(0);
    if(fd == -1)
        handel_error("open file");
    i = 0;
    while(i < nbr_line)
    { 
        map[i] = get_next_line(fd);
        i++;
    }
    return(map);
}

