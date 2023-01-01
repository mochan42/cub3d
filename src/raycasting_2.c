/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 21:21:51 by moninechan        #+#    #+#             */
/*   Updated: 2022/12/31 23:37:06 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_graphics(t_prg *v)
{
	v->graphics.camera_x = 0;
	v->graphics.deltadist_x = 0;
	v->graphics.deltadist_y = 0;
	v->graphics.hit = 0;
	v->graphics.side = 0;
	v->graphics.wall_x = 0;
	v->tex.to_apply = 'N';
}

void	fill_ceiling(t_prg *v, int *row)
{
	int	col;

	while (*row < SCR_HEIGHT / 2)
	{
	col = 0;
		while (col < SCR_WIDTH)
		{
			my_mlx_pixel_put(&v->img, col, *row, v->tex.ceiling_color);
			col++;
		}
		*row += 1;
	}
}

void	fill_floor(t_prg *v, int *row)
{
	int	col;

	while (*row < SCR_HEIGHT)
	{
		col = 0;
		while (col < SCR_WIDTH)
		{
			my_mlx_pixel_put(&v->img, col, *row, v->tex.floor_color);
			col++;
		}
		*row += 1;
	}
}

void	fill_background(t_prg *v)
{
	int	row;

	row = 0;
	fill_ceiling(v, &row);
	fill_floor(v, &row);
}

void	init_raycasting(t_prg *v, int x)
{
	v->graphics.camera_x = 2 * x / (double)SCR_WIDTH - 1;
	v->graphics.raydir_x = v->player.dir_x + v->camera.plane_x * \
		v->graphics.camera_x;
	v->graphics.raydir_y = v->player.dir_y + v->camera.plane_y * \
		v->graphics.camera_x;
	v->graphics.map_x = (int)v->player.pos_x;
	v->graphics.map_y = (int)v->player.pos_y;
	if (v->graphics.raydir_x == 0)
		v->graphics.deltadist_x = 1e30;
	else
		v->graphics.deltadist_x = fabs(1 / v->graphics.raydir_x);
	if (v->graphics.raydir_y == 0)
		v->graphics.deltadist_y = 1e30;
	else
		v->graphics.deltadist_y = fabs(1 / v->graphics.raydir_y);
}
