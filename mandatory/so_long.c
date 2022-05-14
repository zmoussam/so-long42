/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:40:29 by zmoussam          #+#    #+#             */
/*   Updated: 2022/05/14 22:20:45 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

int main(int argc, char **argv)
{
    t_long so_long;
    int fd;
    int i;
    int j;
    
    so_long.count_map_line = 0;
    i = 0;
    j = 0;
    so_long.mlx = mlx_init();
    so_long.win = mlx_new_window(so_long.mlx, 500,500,"so_long");
    if(argc != 2)
        handel_error("invalide argument!!\n");
    check_extention(argv[1]);
    so_long.count_map_line = get_nbr_line(argv[1]);
    so_long.map = read_map_file(argv[1],so_long.count_map_line);
    check_map_form(so_long.map,so_long.count_map_line);
    check_map_wals(so_long.map,so_long.count_map_line);
    check_map_component(so_long.map, so_long.count_map_line);
    so_long.number_of_c = check_component_exist(so_long.map, so_long.count_map_line);
    mlx_key_hook(so_long.win,key_hook,&so_long);
    mlx_loop(so_long.mlx);
    close(fd);
}