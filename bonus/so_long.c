/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:40:29 by zmoussam          #+#    #+#             */
/*   Updated: 2022/05/19 00:37:45 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	animation(t_long *so)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while(so->map[i])
	{
		j = 0;
		while (so->map[i][j])
		{
			if(so->map[i][j] == 'C' )
			{
				mlx_put_image_to_window(so->mlx, so->win, so->green_right, j * 30, i * 30);
				 usleep(5000);
			}
			else if (so->map[i][j] == 'C')
			{
				mlx_put_image_to_window(so->mlx, so->win, so->green_left, j * 30, i * 30);
				usleep(5000);
			}
			
			j++;
		}
		i++;
		
	}
		return 1 ;
}
int	main(int argc, char **argv)
{
	t_long	so;
	int		fd;
	int		i;
	int		j;
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
	mlx_hook(so.win, 2, 1L << 0, &key_hook, &so);
	mlx_hook(so.win, 17, 1L, esc_hook, &so);
	mlx_loop_hook(so.mlx, animation, &so);
	mlx_loop(so.mlx);
}
