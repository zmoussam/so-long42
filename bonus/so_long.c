/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:40:29 by zmoussam          #+#    #+#             */
/*   Updated: 2022/05/23 21:34:05 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	initialize_all(t_component *all)
{
	all->colectabls = 0;
	all->player = 0;
	all->exit = 0;
	all->e_r = 0;
	all->e_g = 0;
}

void	put_e_b_w(t_long *so, int i, int j, char e)
{
	if (e == 'G')
		mlx_put_image_to_window(so->mlx, so->win,
			so->green_left, j * 30, i * 30);
	if (e == 'R')
		mlx_put_image_to_window(so->mlx, so->win,
			so->red_left, j * 30, i * 30);
	if (e == '0')
		mlx_put_image_to_window(so->mlx, so->win,
			so->black, j * 30, i * 30);
	if (e == '1')
		mlx_put_image_to_window(so->mlx, so->win,
			so->wall, j * 30, i * 30);
}

void	lets_play(t_long *so)
{
	so->mlx = mlx_init();
	so->win = mlx_new_window(so->mlx,
			ft_strlen(so->map[so->count_map_line - 1]) * 30,
			so->count_map_line * 30, "so_long");
	get_data(so);
	put_map_to_win(so, 2);
	mlx_loop_hook(so->mlx, animation, so);
	mlx_hook(so->win, 2, 1L << 0, &key_hook, so);
	mlx_hook(so->win, 17, 1L << 15, game_over, so);
	mlx_loop(so->mlx);
}

int	main(int argc, char **argv)
{
	t_long	so;
	int		bolean_r;
	int		bolean_g;

	bolean_r = 0;
	bolean_g = 0;
	so.bolean_r = &bolean_r;
	so.bolean_g = &bolean_g;
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
	lets_play(&so);
}
