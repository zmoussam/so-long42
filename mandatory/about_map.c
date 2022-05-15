/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:50:59 by zmoussam          #+#    #+#             */
/*   Updated: 2022/05/15 22:34:04 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
 
int get_nbr_line(char *map_file)
{
    int     fd;
    int     count_map_line;
     
    fd = open(map_file, O_RDONLY);
    if(fd == -1)
        handel_error("open file\n");
    while(get_next_line(fd)) 
        count_map_line++;     
    if(count_map_line == 0)
        handel_error("empty map's file!!\n");
    close(fd);
    return(count_map_line);
}

char **read_map_file(char *map_file, int nbr_line)
{
    char **map;
    int i;
    int fd;
    fd = open(map_file, O_RDONLY);
    if(fd == -1)
        handel_error("open file\n");
    map = (char **)malloc(sizeof(char *) * (nbr_line + 1));
    if(!map)
        return(0);
    i = 0;
    while(i < nbr_line)
    { 
        map[i] = get_next_line(fd); 
        i++;
    }
    map[i] = NULL;
    return(map);
}

void check_extention(char *file_name)
{
    int start;
    char *extention;
    
    start = ft_strlen(file_name) - 4;
    extention = ft_substr(file_name,start,4);
    if (ft_strcmp(".ber", extention) != 0)
            handel_error("extention must be .ber\n");
}

void check_map_form(char **map, int count_map_line)
{
    size_t size_first_line;
    int i;
    
    i = 1;
    size_first_line = ft_strlen(map[0]);
    while(i < count_map_line - 1)
    {
        if(ft_strlen(map[i]) != size_first_line)
            handel_error("map form invalide\n");
        i++;
    }
    if(ft_strlen(map[i]) != size_first_line - 1) 
        handel_error("map form invalide\n");   
}

void check_map_wals(char **map, int count_map_line)
{
    int i;
    int j;
    
    i = 0;
    while(i < count_map_line)
    {
        j = 0;
        if(i == 0 || i == count_map_line - 1)
        {
            while(map[i][j] && j < ft_strlen(map[0]) - 1)
            {
                if(map[i][j] != '1')
                    handel_error("map's wals not valide!!\n");
                j++;
            }
        }
        j = 0;
        while(map[i][j] && j < ft_strlen(map[0]) - 1)
        {
            if(map[i][0] != '1' || map[i][ft_strlen(map[0]) - 2] != '1')
                handel_error("map's wals not valide!!\n");
            j++;
        } 
        i++;  
    }
} 