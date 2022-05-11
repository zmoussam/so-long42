/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:33:43 by zmoussam          #+#    #+#             */
/*   Updated: 2022/05/11 12:52:59 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<mlx.h>

typedef struct s_vars {
	void	*mlx;
	void	*win;
} t_vars;

int close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return(0);
}

int main()
{
	t_vars vars;
	vars.mlx = mlx_init();

	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "hello world!");
		mlx_hook(vars->win, 53, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);

}
