/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:40:29 by zmoussam          #+#    #+#             */
/*   Updated: 2022/05/16 23:47:59 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

int main(int argc, char **argv)
{
    t_long so_long;
    int fd;
    int i;
    int j;
    int x = 60;
    int y = 60;
    
    so_long.count_map_line = 0;
    if(argc != 2)
        handel_error("invalide argument!!\n");
    so_long.mlx = mlx_init();
    check_extention(argv[1]);
    so_long.count_map_line = get_nbr_line(argv[1]);
    so_long.map = read_map_file(argv[1],so_long.count_map_line);
    check_map_form(so_long.map,so_long.count_map_line);
    check_map_wals(so_long.map,so_long.count_map_line);
    check_map_component(so_long.map, so_long.count_map_line);
    so_long.number_of_c = check_component_exist(so_long.map, so_long.count_map_line);
    so_long.win = mlx_new_window(so_long.mlx, ft_strlen(so_long.map[so_long.count_map_line - 1]) * 60,  so_long.count_map_line * 60, "so_long");
    so_long.black = mlx_xpm_file_to_image(so_long.mlx, "../assets/black.xpm",&x,&y);
    so_long.player_up = mlx_xpm_file_to_image(so_long.mlx, "../assets/player_up.xpm",&x,&y);
    so_long.player_down = mlx_xpm_file_to_image(so_long.mlx, "../assets/player_down.xpm",&x,&y);
    so_long.player_left = mlx_xpm_file_to_image(so_long.mlx, "../assets/player_left.xpm",&x,&y);
    so_long.player_right = mlx_xpm_file_to_image(so_long.mlx, "../assets/player_right.xpm",&x,&y);
    so_long.wall = mlx_xpm_file_to_image(so_long.mlx, "../assets/wall.xpm",&x,&y);
    so_long.heart = mlx_xpm_file_to_image(so_long.mlx, "../assets/heart.xpm",&x,&y);
    so_long.collectabls = mlx_xpm_file_to_image(so_long.mlx, "../assets/colectabls.xpm",&x,&y);
    so_long.exit_close = mlx_xpm_file_to_image(so_long.mlx, "../assets/exit_close.xpm",&x,&y);
    so_long.exit_open = mlx_xpm_file_to_image(so_long.mlx, "../assets/exit_open.xpm",&x,&y);
    so_long.heart_two = mlx_xpm_file_to_image(so_long.mlx, "../assets/heart2.xpm",&x,&y);
    mlx_key_hook(so_long.win,key_hook,&so_long);
    put_map_to_win(&so_long,124);
    mlx_loop(so_long.mlx);
    close(fd);
}