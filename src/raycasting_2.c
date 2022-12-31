/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 21:21:51 by moninechan        #+#    #+#             */
/*   Updated: 2022/12/31 21:26:44 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_graphics(t_prg *v)
{
	v->graphics.cameraX = 0;
	v->graphics.deltaDistX = 0;
	v->graphics.deltaDistY = 0;
	v->graphics.hit = 0;
	v->graphics.side = 0;
	v->graphics.wallX = 0;
	v->tex.toApply = 'N';
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
	v->graphics.cameraX = 2 * x / (double)SCR_WIDTH - 1;
	v->graphics.rayDirX = v->player.dirX + v->camera.planeX * \
		v->graphics.cameraX;
	v->graphics.rayDirY = v->player.dirY + v->camera.planeY * \
		v->graphics.cameraX;
	v->graphics.mapX = (int)v->player.posX;
	v->graphics.mapY = (int)v->player.posY;
	v->graphics.deltaDistX = (v->graphics.rayDirX == 0) ? 1e30 : \
		fabs(1/v->graphics.rayDirX);
	v->graphics.deltaDistY = (v->graphics.rayDirY == 0) ? 1e30 : \
		fabs(1/v->graphics.rayDirY);
}
