/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:40:29 by zmoussam          #+#    #+#             */
/*   Updated: 2022/05/18 00:27:50 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_long	so_long;
    int		fd;
    int		i;
    int		j;

	so_long.count_map_line = 0;
	if (argc != 2)
		handel_error("invalide argument!!\n");
	check_extention(argv[1]);
    so_long.count_map_line = get_nbr_line(argv[1]);
	so_long.map = read_map_file(argv[1], so_long.count_map_line);
	check_map_form(so_long.map, so_long.count_map_line);
	check_map_wals(so_long.map, so_long.count_map_line);
	check_map_component(so_long.map, so_long.count_map_line);
	so_long.number_of_c = check_component_exist(so_long.map, so_long.count_map_line);
	so_long.mlx = mlx_init();
	so_long.win = mlx_new_window(so_long.mlx, ft_strlen(so_long.map[so_long.count_map_line - 1]) * 30, so_long.count_map_line * 30, "so_long");
	get_data(&so_long);
	put_map_to_win(&so_long, 2);
	mlx_hook(so_long.win, 2, 1L << 0, key_hook, &so_long);
	mlx_loop(so_long.mlx);
	close(fd);
}
