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

typedef struct s_graphics {
	double		cameraX;
	double		rayDirX;
	double		rayDirY;
	int			mapX;
	int			mapY;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	double		perpWallDist;
	int			stepX;
	int			stepY;
	int			hit;
	int			side;
	int			lineHeight;
	int			drawStart;
	int			drawEnd;
	double		color;
}				t_graphics;

typedef struct s_player {
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		player_angle;
}				t_player;

typedef struct s_prg {
	t_data		data;
	t_player	player;
	t_camera	camera;
	t_graphics	graphics;
	char		*map_path;
	int			row;
	int			col;
	char		**map;
	int			nb_arg;
}				t_prg;

/* ########################################################################## */
/* CONSTANTS */

# define SCR_WIDTH			300
# define SCR_HEIGHT			300
# define RGB_RED			0x00FF0000
# define RGB_GREEN			0x0000FF00
# define RGB_YELLOW			0x00FFFF00
# define RGB_BLUE			0x000000FF

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

/* main.c */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

/* player.c */
void    init_player_dir(t_prg *v);
void    init_player_pos(t_prg *v);

/* raycasting.c */
void    init_graphics(t_prg *v);
void    raycasting(t_prg *v);
