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

typedef struct	s_img {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			height;
	int			width;
}				t_img;

typedef	struct s_textures {
	t_img		no;
	t_img		so;
	t_img		ea;
	t_img		we;
	char		*path_no;
	char		*path_so;
	char		*path_ea;
	char		*path_we;
	char		toApply;
	int			ceiling_color;
	int			floor_color;
}				t_textures;

typedef struct s_camera {
	char		initial_camera_direction;
	double		planeX;
	double		planeY;
	double		oldPlaneX;
	double		oldPlaneY;
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
	int			tex_x;
	double		tex_y;
	double		tex_y_step;
	// double		tex_pos;
	double		wallX;
}				t_graphics;

typedef struct s_player {
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		oldDirX;
	double		oldDirY;
	double		player_angle;
}				t_player;

typedef struct s_prg {
	void		*mlx;
	void		*mlx_win;
	t_img		img;
	t_textures	tex;
	t_player	player;
	t_camera	camera;
	t_graphics	graphics;
	char		*map_path;
	int			row;
	int			col;
	char		**map;
	int			nb_arg;
	int			map_i;
	int			rgb[3];
	int			nb_rgb[2];
}				t_prg;

/* ########################################################################## */
/* CONSTANTS */

# define SCR_WIDTH			1200
# define SCR_HEIGHT			600
# define RGB_RED			0x00FF0000
# define RGB_GREEN			0x0000FF00
# define RGB_YELLOW			0x00FFFF00
# define RGB_BLUE			0x000000FF
# define KEY_ESC			53
# define KEY_UP				13
# define KEY_DOWN			1	
# define KEY_LEFT			0
# define KEY_RIGHT			2
# define KEY_ROT_LEFT		123
# define KEY_ROT_RIGHT		124
# define MOVE_SPEED			0.4
# define ROT_SPEED			0.3

/* ########################################################################## */
/* FUNCTIONS */

/* camera.c */
void	init_camera_dir(t_prg *v);
void    init_camera_pos(t_prg *v);

/* hooks.c */
int		key_hook(int keycode, t_prg *v);

/* map.c */
int		count_nb_col(char *map_path);
int		count_nb_row(char *map_path);
void    init_player_pos(t_prg *v);
// void    print_map(t_prg *v);
char	**store_map(t_prg *v);

/* main.c */
int		ft_close_window(t_prg *v);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

/* moves.c */
void	move_backwards(t_prg *v);
void	move_forward(t_prg *v);
void	move_left_dirXPos_dirYNeg(t_prg *v);
void	move_left_dirXPos_dirYPos(t_prg *v);
void	move_left_dirXNeg_dirYNeg(t_prg *v);
void	move_left_dirXNeg_dirYPos(t_prg *v);
void    move_left(t_prg *v);
void	move_right_dirXPos_dirYNeg(t_prg *v);
void	move_right_dirXPos_dirYPos(t_prg *v);
void	move_right_dirXNeg_dirYNeg(t_prg *v);
void	move_right_dirXNeg_dirYPos(t_prg *v);
void    move_right(t_prg *v);
void	rotate_left(t_prg *v);
void	rotate_right(t_prg *v);

/* player.c */
void    find_player_pos(t_prg *v);
void    init_player_dir(t_prg *v);

/* raycasting_1.c */
void	calculate_ray(t_prg *v);
void	check_if_ray_hits_wall(t_prg *v);
void	compute_vertical_stripe(t_prg *v);
void	raycasting(t_prg *v);

/* raycasting_2.c */
void	fill_background(t_prg *v);
void	fill_ceiling(t_prg *v, int *row);
void	fill_floor(t_prg *v, int *row);
void	init_graphics(t_prg *v);
void	init_raycasting(t_prg *v, int x);

/* textures_1.c*/
void    add_texture(t_prg *v, t_img *wall_tex, int x);
void    apply_wall_tex(t_prg *v, t_graphics *graphics);
void    find_texture_coord(t_prg *v, t_img *wall_tex);
t_img   *get_wall_tex(t_textures *tex);
void    init_textures(t_prg *v);

/* textures_2.c*/
void    create_texture_images(t_prg *v);
void	get_texture_params(t_prg *v);

/* utils_1.c */
int		empty_or_valid_char(t_prg *v, int i, int j, int *validator);
int		check_map_content(t_prg *v, int *validator, int *isPos);
void    parsing(t_prg *v, int *validator);

/* utils_2.c */
int		create_trgb(int t, int r, int g, int b);
void    free_cub3d(t_prg *v);
void    init_card_pt(int card_pt[4]);
void	loop_card_points(t_prg *v, int i, int *j);
void    skipe_empty_line(t_prg *v);

/* utils_3.c */
int		assign_path_to_texture(t_prg *v, int texture, char *path);
int		is_valid_card_points(t_prg *v, int card_pt[4], int *validator, int i);
int		is_valid_len_points(int j, int *validator);
int		is_valid_textures_paths(t_prg *v, int i, int *j, int *validator);
void	skype_spaces(t_prg *v, int i, int *j);

/* utils_4.c */
int		is_allowed_char(char c);
int		check_direction(t_prg *v, int *validator);
int		check_process_path_texture(t_prg *v, int *i, int j, int path[2]);
int		is_init_player_pos(char c);
int		process_path_texture(t_prg *v, int *i, int j, int path[2]);

/* utils_5.c */
void	get_color_value(int *red, char *str_color);
int		is_allowed_space_x(t_prg *v, int i, int j, int sens);
int		is_allowed_space_y(t_prg *v, int i, int j, int sens);
int		is_comma_respected(t_prg *v, int i, int j, int *validator);
void	reading_color_num_value(t_prg *v, int i, int *j, int nb[2]);

/* utils_6.c */
int		find_floor_ceilling(t_prg *v, int *j, int *validator, int checker);
int		floor_ceilling_color(t_prg *v, int *j, int *validator);
int		is_color_def_valid(t_prg *v, int nb[2], int j, int *validator);
int		is_color_valid(t_prg *v, int *validator);
int		is_comma2_respected(t_prg *v, int *j, int *validator);

/* utils_7.c */
int		check_ceil_and_floor_color(t_prg *v, int *validator);
int		is_empty_line(t_prg *v, int i, int *validator);
int		is_valid_char(t_prg *v, int i, int j, int *validator);
int		is_valid_map_extension(t_prg *v, int *p_len, int *validator, int *isPos);
void	valid_init_position(int isPos, int *validator);

/* utils_8.c */
int		is_zero_close(t_prg *v, int i, int j, int *validator);
int		is_zero_close_down(t_prg *v, int i, int j, int *validator);
int		is_zero_close_left(t_prg *v, int i, int j, int *validator);
int		is_zero_close_right(t_prg *v, int i, int j, int *validator);
int		is_zero_close_to_top(t_prg *v, int i, int j, int *validator);
