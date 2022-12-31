/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:21:47 by moninechan        #+#    #+#             */
/*   Updated: 2022/12/31 21:41:38 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	calculate_ray(t_prg *v)
{
	if (v->graphics.rayDirX < 0)
	{
		v->graphics.stepX = -1;
		v->graphics.sideDistX = (v->player.posX - v->graphics.mapX) * \
			v->graphics.deltaDistX;
	}
	else
	{
		v->graphics.stepX = 1;
		v->graphics.sideDistX = (v->graphics.mapX + 1.0 - v->player.posX) * \
			v->graphics.deltaDistX;
	}
	if (v->graphics.rayDirY < 0)
	{
		v->graphics.stepY = -1;
		v->graphics.sideDistY = (v->player.posY - v->graphics.mapY) * \
			v->graphics.deltaDistY;
	}
	else
	{
		v->graphics.stepY = 1;
		v->graphics.sideDistY = (v->graphics.mapY + 1.0 - v->player.posY) * \
			v->graphics.deltaDistY;
	}
}

void	check_if_ray_hits_wall(t_prg *v)
{
	int	hit_counter;

	hit_counter = 0;
	v->graphics.hit = 0;
	while (v->graphics.hit == 0)
	{
		if (v->graphics.sideDistX < v->graphics.sideDistY)
		{
			v->graphics.sideDistX += v->graphics.deltaDistX;
			v->graphics.mapX += v->graphics.stepX;
			v->graphics.side = 0;
		}
		else
		{
			v->graphics.sideDistY += v->graphics.deltaDistY;
			v->graphics.mapY += v->graphics.stepY;
			v->graphics.side = 1;
		}
		if (v->map[v->graphics.mapY][v->graphics.mapX] == '1')
			v->graphics.hit = 1;
		hit_counter++;
	}
}

void	compute_vertical_stripe(t_prg *v)
{
	if (v->graphics.side == 0)
		v->graphics.perpWallDist = (v->graphics.sideDistX - \
			v->graphics.deltaDistX);
	else
		v->graphics.perpWallDist = (v->graphics.sideDistY - \
			v->graphics.deltaDistY);
	if (v->graphics.perpWallDist == 0)
		v->graphics.lineHeight = (int)SCR_HEIGHT;
	else
		v->graphics.lineHeight = (int)(SCR_HEIGHT / v->graphics.perpWallDist);
	v->graphics.drawStart = v->graphics.lineHeight * (-1) / 2 + SCR_HEIGHT / 2;
	if (v->graphics.drawStart < 0)
		v->graphics.drawStart = 0;
	v->graphics.drawEnd = v->graphics.lineHeight / 2 + SCR_HEIGHT / 2;
	if (v->graphics.drawEnd >= SCR_HEIGHT)
		v->graphics.drawEnd = SCR_HEIGHT - 1;
}

void	raycasting(t_prg *v)
{
	int	x;

	fill_background(v);
	init_textures(v);
	x = 0;
	while (x < SCR_WIDTH)
	{
		init_raycasting(v, x);
		calculate_ray(v);
		check_if_ray_hits_wall(v);
		compute_vertical_stripe(v);
		apply_wall_tex(v, &v->graphics);
		add_texture(v, get_wall_tex(&v->tex), x);
		x++;
	}
	mlx_put_image_to_window(v->mlx, v->mlx_win, v->img.img, 0, 0);
}
