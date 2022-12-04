/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 23:57:45 by fakouyat          #+#    #+#             */
/*   Updated: 2022/09/22 23:57:45 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* INCLUDES */
/* ########################################################################## */
#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/inc/libft.h"
# include "../gnl/inc/get_next_line.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include <math.h>
#endif

/* ########################################################################## */
/* STRUCTURES */

typedef struct	s_data {
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_camera {
	char		initial_camera_direction;
	double		planeX;
	double		planeY;
}				t_camera;

typedef struct s_player {
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	int			player_angle;
}				t_player;

typedef struct s_prg {
	t_data		data;
	t_player	player;
	t_camera	camera;
	char		*map_path;
	int			row;
	int			col;
	char		**map;
	int			nb_arg;
}				t_prg;

/* ########################################################################## */
/* CONSTANTS */

# define SCR_WIDTH			1200
# define SCR_HEIGHT			600

/* ########################################################################## */
/* FUNCTIONS */

/* camera.c */
void    init_camera_pos(t_prg *v);
void	init_camera_dir(t_prg *v);

/* map.c */
int		count_nb_col(char *map_path);
int		count_nb_row(char *map_path);
void    init_player_pos(t_prg *v);
void    print_map(t_prg *v);
char	**store_map(t_prg *v);

/* player.c */
void    init_player_dir(t_prg *v);
void    init_player_pos(t_prg *v);
