/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:45:45 by moninechan        #+#    #+#             */
/*   Updated: 2022/12/11 11:28:15 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/cub3d.h"

void    init_prg(t_prg *v)
{
    v->row = count_nb_row(v->map_path);
    printf("nb of rows = %d\n", v->row);
    v->map = store_map(v);
    print_map(v);
    find_player_pos(v);
    printf("posX = %f\n", v->player.posX);
    printf("posY = %f\n", v->player.posY);
    init_camera_pos(v);
    init_player_dir(v);
    init_camera_dir(v);
    init_graphics(v);
}

int	ft_close_window(t_prg *v)
{
    mlx_destroy_window(v->data.mlx, v->data.mlx_win);
	printf("exit cub3D\n");
	exit (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(int ac, char **av)
{
    t_prg   *v;

    if (ac != 2)
        exit(0);
    v = malloc(sizeof(t_prg) * 1);
    v->map_path = ft_strdup(av[1]);
    printf("path :%s\n", v->map_path);
    init_prg(v);
    v->data.mlx = mlx_init();
    v->data.mlx_win = mlx_new_window(v->data.mlx, SCR_WIDTH, SCR_HEIGHT, "cub3D");
    v->data.img = mlx_new_image(v->data.mlx, SCR_WIDTH, SCR_HEIGHT);
    v->data.addr = mlx_get_data_addr(v->data.img, &v->data.bits_per_pixel, &v->data.line_length,
								&v->data.endian);
    raycasting(v);
    mlx_hook(v->data.mlx_win, 2, 1L << 0, key_hook, v);
    mlx_hook(v->data.mlx_win, 17, 0, ft_close_window, v);
    mlx_loop(v->data.mlx);
    return (0);
}
