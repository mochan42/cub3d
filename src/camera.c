/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:00:44 by moninechan        #+#    #+#             */
/*   Updated: 2022/12/31 23:36:34 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_camera_pos(t_prg *v)
{
	v->camera.initial_camera_direction = v->map[(int)v->player.pos_y] \
		[(int)v->player.pos_x];
	v->map[(int)v->player.pos_y][(int)v->player.pos_x] = '0';
}

void	init_camera_dir(t_prg *v)
{
	if (v->camera.initial_camera_direction == 'N')
	{
		v->camera.plane_x = 0.66;
		v->camera.plane_y = 0;
	}
	if (v->camera.initial_camera_direction == 'S')
	{
		v->camera.plane_x = -0.66;
		v->camera.plane_y = 0;
	}
	if (v->camera.initial_camera_direction == 'W')
	{
		v->camera.plane_x = 0;
		v->camera.plane_y = -0.66;
	}
	if (v->camera.initial_camera_direction == 'E')
	{
		v->camera.plane_x = 0;
		v->camera.plane_y = 0.66;
	}
}
