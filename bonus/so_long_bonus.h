/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:42:07 by zmoussam          #+#    #+#             */
/*   Updated: 2022/05/21 04:55:24 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# define BUFFER_SIZE 1024
# include "../get_next_line/get_next_line.h"
# include "../printf/ft_printf.h"
# include <mlx.h>

typedef struct s_long{
	char	**map;
	void	*mlx;
	void	*win;
	size_t	count_map_line;
	int		number_of_c;
	void	*wall;
	void	*p_up;
	void	*p_do;
	void	*p_le;
	void	*p_ri;
	void	*col;
	void	*heart;
	void	*black;
	void	*e_cl;
	void	*e_op;
	void	*ceris;
	int		moves;
	void	*green_left;
	void	*heart_big;
	int		*bolean_r;
	int		*bolean_g;
	void	*red_left;
}t_long;

typedef struct s_cordinates
{
	int	x;
	int	y;
}t_cordinates;

typedef struct s_componente
{
	int	exit;
	int	colectabls;
	int	player;
	int	e_r;
	int	e_g;
}t_componente;

int				ft_strcmp(char *s1, char *s2);
void			handel_error(char *error_name);
int				get_nbr_line(char *map_file);
char			**read_map_file(char *map_file, int nbr_line);
void			check_extention(char *file_name);
void			check_map_form(char **map, size_t count_map_line);
void			check_map_wals(char **map, size_t count_map_line);
void			check_map_component(char **map, size_t count_map_line);
int				check_component_exist(char **map, size_t count_map_line);
t_cordinates	get_cordinates(t_long *so_long, char point);
void			handel_moves(t_long *so_long, t_cordinates p, int keycode);
void			moves_up(t_long *so_long, t_cordinates p);
void			moves_down(t_long *so_long, t_cordinates p);
void			moves_right(t_long *so_long, t_cordinates p);
void			moves_left(t_long *so_long, t_cordinates p);
int				key_hook(int keycode, t_long *so_long);
void			put_map_to_win(t_long *so_long, int keycode);
void			get_data(t_long *so_long);
void			check_number_of_component(t_componente all);
void			put_player(t_long *so_long, int keycode, int i, int j);
void			put_colectabls(t_long *so_long, int i, int j);
void			put_exit(t_long *so_long, int i, int j);
int				game_over(t_long *so);
void			handel_enemie_moves(t_long *so_long,
					int *bolean, t_cordinates p);
void			moves_enemie_green(t_long *so, t_cordinates e, int *bolean);
void			moves_enemie_red(t_long *so, t_cordinates e, int *bolean);
void			moves_enemie_down(t_long *so_long, char point,
					t_cordinates p, int *bolean);
void			moves_enemie_up(t_long *so_long, char point,
					t_cordinates p, int *bolean);
void			moves_enemie_right(t_long *so_long, char point,
					t_cordinates p, int *bolean);
void			moves_enemie_left(t_long *so_long, char point,
					t_cordinates p, int *bolean);
char			*ft_itoa(int l);
char			*ft_strjoin2( char *s1, char *s2);
int				animation(t_long *so_long, int keycode);
#endif
