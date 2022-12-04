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
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_prg {
	t_data  data;
	char	*map_path;
	int		row;
	int		col;
	char	**map;
	int		nb_arg;
	int		posX;
	int		posY;
}				t_prg;


/* ########################################################################## */
/* CONSTANTS */



/* ########################################################################## */
/* FUNCTIONS */

/* map.c */
int		count_nb_col(char *map_path);
int		count_nb_row(char *map_path);
char	**store_map(t_prg *v);
void    print_map(t_prg *v);
void    init_player_pos(t_prg *v);