/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:21:47 by moninechan        #+#    #+#             */
/*   Updated: 2022/12/31 23:36:34 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	calculate_ray(t_prg *v)
{
	if (v->graphics.raydir_x < 0)
	{
		v->graphics.step_x = -1;
		v->graphics.sidedist_x = (v->player.pos_x - v->graphics.map_x) * \
			v->graphics.deltadist_x;
	}
	else
	{
		v->graphics.step_x = 1;
		v->graphics.sidedist_x = (v->graphics.map_x + 1.0 - v->player.pos_x) * \
			v->graphics.deltadist_x;
	}
	if (v->graphics.raydir_y < 0)
	{
		v->graphics.step_y = -1;
		v->graphics.sidedist_y = (v->player.pos_y - v->graphics.map_y) * \
			v->graphics.deltadist_y;
	}
	else
	{
		v->graphics.step_y = 1;
		v->graphics.sidedist_y = (v->graphics.map_y + 1.0 - v->player.pos_y) * \
			v->graphics.deltadist_y;
	}
}

void	check_if_ray_hits_wall(t_prg *v)
{
	int	hit_counter;

	hit_counter = 0;
	v->graphics.hit = 0;
	while (v->graphics.hit == 0)
	{
		if (v->graphics.sidedist_x < v->graphics.sidedist_y)
		{
			v->graphics.sidedist_x += v->graphics.deltadist_x;
			v->graphics.map_x += v->graphics.step_x;
			v->graphics.side = 0;
		}
		else
		{
			v->graphics.sidedist_y += v->graphics.deltadist_y;
			v->graphics.map_y += v->graphics.step_y;
			v->graphics.side = 1;
		}
		if (v->map[v->graphics.map_y][v->graphics.map_x] == '1')
			v->graphics.hit = 1;
		hit_counter++;
	}
}

void	compute_vertical_stripe(t_prg *v)
{
	if (v->graphics.side == 0)
		v->graphics.perpwalldist = (v->graphics.sidedist_x - \
			v->graphics.deltadist_x);
	else
		v->graphics.perpwalldist = (v->graphics.sidedist_y - \
			v->graphics.deltadist_y);
	if (v->graphics.perpwalldist == 0)
		v->graphics.line_height = (int)SCR_HEIGHT;
	else
		v->graphics.line_height = (int)(SCR_HEIGHT / v->graphics.perpwalldist);
	v->graphics.draw_start = \
		v->graphics.line_height * (-1) / 2 + SCR_HEIGHT / 2;
	if (v->graphics.draw_start < 0)
		v->graphics.draw_start = 0;
	v->graphics.draw_end = v->graphics.line_height / 2 + SCR_HEIGHT / 2;
	if (v->graphics.draw_end >= SCR_HEIGHT)
		v->graphics.draw_end = SCR_HEIGHT - 1;
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
