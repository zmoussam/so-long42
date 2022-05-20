/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:40:29 by zmoussam          #+#    #+#             */
/*   Updated: 2022/05/20 18:37:05 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	animation(t_long *so_long,int keycode)
{
	t_cordinates e_g;
    t_cordinates e_r;
	int randd;
    int l;
    int u;
	l = 1;
    u = 2;
    randd = (rand() % (u - l + 1) + l);
	e_g = get_cordinates(so_long,'G');
    e_r = get_cordinates(so_long,'R');
	if (randd == 1)
		handel_enemie_moves(so_long,so_long->bolean_R,e_r);
	else if (randd == 2)
       	handel_enemie_moves(so_long,so_long->bolean_G,e_g);
	put_map_to_win(so_long,keycode);
	
	return (1);
}
int	main(int argc, char **argv)
{
	t_long	so;
	int bolean_R;
	int bolean_G;
	bolean_R = 0;
	bolean_G = 0;
	
	so.bolean_R = &bolean_R;
	so.bolean_G = &bolean_G;
	so.moves = 0; 
	so.count_map_line = 0;
	if (argc != 2)
		handel_error("invalide argument!!\n");
	check_extention(argv[1]);
	so.count_map_line = get_nbr_line(argv[1]);
	so.map = read_map_file(argv[1], so.count_map_line);
	check_map_form(so.map, so.count_map_line);
	check_map_wals(so.map, so.count_map_line);
	check_map_component(so.map, so.count_map_line);
	so.number_of_c = check_component_exist(so.map, so.count_map_line);
	so.mlx = mlx_init();
	so.win = mlx_new_window(so.mlx,
			ft_strlen(so.map[so.count_map_line - 1]) * 30,
			so.count_map_line * 30, "so_long");
	get_data(&so);
	put_map_to_win(&so, 2);
	mlx_loop_hook(so.mlx, animation, &so);
	mlx_hook(so.win, 2, 1L << 0, &key_hook, &so);
	mlx_hook(so.win, 17, 1L << 15, esc_hook, &so);
	mlx_loop(so.mlx);
}
