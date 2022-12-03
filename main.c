/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:45:45 by moninechan        #+#    #+#             */
/*   Updated: 2022/12/03 21:44:41 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

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

int main(void)
{
    t_prg   *v;
    int x;
    int y;
    
    x = 0;
    y = 0;
    v = malloc(sizeof(t_prg) * 1);
    v->data.mlx = mlx_init();
    v->data.mlx_win = mlx_new_window(v->data.mlx, 800, 500, "CUBE 3 D");
    v->data.img = mlx_new_image(v->data.mlx, 800, 500);
    v->data.addr = mlx_get_data_addr(v->data.img, &v->data.bits_per_pixel, &v->data.line_length,
								&v->data.endian);
    while (x < 800)
    {
        my_mlx_pixel_put(&v->data, x, 20, 0x00FF0000);
        x++;
    } 
    mlx_put_image_to_window(v->data.mlx, v->data.mlx_win,v->data.img, 0, 0);
    mlx_hook(v->data.mlx_win, 17, 0, ft_close_window, v);
    mlx_loop(v->data.mlx);
}