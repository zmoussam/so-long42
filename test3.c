/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:19:25 by zmoussam          #+#    #+#             */
/*   Updated: 2022/05/14 16:32:05 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<mlx.h>
#include<stdio.h>

typedef struct s_vars {
	void *mlx;
	void *win;
}  t_vars;

int key_hook()
{
	printf("hello from key_hook!\n");
	return (0);
}

int mouse_hook()
{
	printf("hello from mouse!\n");
	return(0);
}

int main()
{
	t_vars vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "hello world!");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
}
