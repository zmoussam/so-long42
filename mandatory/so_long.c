/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:40:29 by zmoussam          #+#    #+#             */
/*   Updated: 2022/05/12 18:49:58 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

int main(int argc, char **argv)
{
    int fd;
    int i;
    int j;
    int count_map_line;
    char **map;
    
    count_map_line = 0;
    i = 0;
    j = 0;
    if(argc != 2)
        handel_error("invalide argument!!");
    count_map_line = get_nbr_line(argv[1]);
    map = read_map_file(argv[1],count_map_line);
    while(j < count_map_line)
    {
        printf("%s",map[j]);
        j++;
    }
    close(fd);
    
}