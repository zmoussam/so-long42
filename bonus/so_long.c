/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:40:29 by zmoussam          #+#    #+#             */
/*   Updated: 2022/05/18 20:34:22 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	esc_hook(int keycode,t_long *so)
{
	(void)keycode;
	exit(0);
	return 0;
}
int	main(int argc, char **argv)
{
	t_long	so;
	int		fd;
	int		i;
	int		j;

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
	mlx_hook(so.win, 2, 1L << 0, &key_hook, &so);
	mlx_hook(so.win, 17, 0, &esc_hook, &so);
	mlx_loop(so.mlx);
}
