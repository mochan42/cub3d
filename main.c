/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:45:45 by moninechan        #+#    #+#             */
/*   Updated: 2023/01/01 02:02:57 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/cub3d.h"

void	init_prg(t_prg *v)
{
	v->row = count_nb_row(v->map_path);
	v->map = store_map(v);
	v->map_i = 0;
	v->tex.path_no = NULL;
	v->tex.path_so = NULL;
	v->tex.path_ea = NULL;
	v->tex.path_we = NULL;
}

void	update_prog(t_prg *v)
{
	find_player_pos(v);
	init_camera_pos(v);
	init_player_dir(v);
	init_camera_dir(v);
	init_graphics(v);
}

void	init_mlx(t_prg *v)
{
	v->mlx = mlx_init();
	v->mlx_win = mlx_new_window(v->mlx, SCR_WIDTH, SCR_HEIGHT, "cub3D");
	v->img.img = mlx_new_image(v->mlx, SCR_WIDTH, SCR_HEIGHT);
	v->img.addr = mlx_get_data_addr(v->img.img, &v->img.bits_per_pixel, \
		&v->img.line_length, &v->img.endian);
}

int	check_if_continue(t_prg *v, int validator)
{
	if (validator == 1)
	{
		free_cub3d(v);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_prg	*v;
	int		validator;

	if (ac != 2)
		exit(0);
	v = malloc(sizeof(t_prg) * 1);
	v->map_path = ft_strdup(av[1]);
	init_prg(v);
	parsing(v, &validator);
	if (check_if_continue(v, validator) == 1)
		return (0);
	skipe_empty_line(v);
	copy_cub_file(v);
	update_prog(v);
	init_mlx(v);
	raycasting(v);
	mlx_hook(v->mlx_win, 2, 1L << 0, key_hook, v);
	mlx_hook(v->mlx_win, 17, 0, ft_close_window, v);
	mlx_loop(v->mlx);
	return (0);
}
