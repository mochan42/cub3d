/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:45:45 by moninechan        #+#    #+#             */
/*   Updated: 2022/12/17 17:54:11 by moninechan       ###   ########.fr       */
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
    // free_cub3d(v);
    mlx_destroy_window(v->mlx, v->mlx_win);
	printf("exit cub3D\n");
	exit (0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
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
    v->mlx = mlx_init();
    v->mlx_win = mlx_new_window(v->mlx, SCR_WIDTH, SCR_HEIGHT, "cub3D");
    v->img.img = mlx_new_image(v->mlx, SCR_WIDTH, SCR_HEIGHT);
    v->img.addr = mlx_get_data_addr(v->img.img, &v->img.bits_per_pixel, &v->img.line_length,
								&v->img.endian);
    raycasting(v);
    mlx_hook(v->mlx_win, 2, 1L << 0, key_hook, v);
    mlx_hook(v->mlx_win, 17, 0, ft_close_window, v);
    mlx_loop(v->mlx);
    return (0);
}
