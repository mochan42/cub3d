/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:56:11 by moninechan        #+#    #+#             */
/*   Updated: 2022/12/31 23:37:06 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	move_forward(t_prg *v)
{
	if (v->map[(int)v->player.pos_y][(int)(v->player.pos_x + v->player.dir_x * \
		(double)MOVE_SPEED)] == '0')
		v->player.pos_x += v->player.dir_x * (double)MOVE_SPEED;
	if (v->map[(int)(v->player.pos_y + v->player.dir_y * (double)MOVE_SPEED)] \
		[(int)(v->player.pos_x)] == '0')
		v->player.pos_y += v->player.dir_y * (double)MOVE_SPEED;
}

void	move_backwards(t_prg *v)
{
	if (v->map[(int)v->player.pos_y][(int)(v->player.pos_x - v->player.dir_x * \
		(double)MOVE_SPEED)] != '1')
		v->player.pos_x -= v->player.dir_x * (double)MOVE_SPEED;
	if (v->map[(int)(v->player.pos_y - v->player.dir_y * (double)MOVE_SPEED)] \
		[(int)(v->player.pos_x)] != '1')
		v->player.pos_y -= v->player.dir_y * (double)MOVE_SPEED;
}

void	rotate_left(t_prg *v)
{
	v->player.olddir_x = v->player.dir_x;
	v->player.dir_x = v->player.dir_x * cos(-(double)ROT_SPEED) - \
		v->player.dir_y * sin(-(double)ROT_SPEED);
	v->player.dir_y = v->player.olddir_x * sin(-(double)ROT_SPEED) + \
		v->player.dir_y * cos(-(double)ROT_SPEED);
	v->camera.oldplane_x = v->camera.plane_x;
	v->camera.plane_x = v->camera.plane_x * cos(-(double)ROT_SPEED) - \
		v->camera.plane_y * sin(-(double)ROT_SPEED);
	v->camera.plane_y = v->camera.oldplane_x * sin(-(double)ROT_SPEED) + \
		v->camera.plane_y * cos(-(double)ROT_SPEED);
}

void	rotate_right(t_prg *v)
{
	v->player.olddir_x = v->player.dir_x;
	v->player.dir_x = v->player.dir_x * cos((double)ROT_SPEED) - \
		v->player.dir_y * sin((double)ROT_SPEED);
	v->player.dir_y = v->player.olddir_x * sin((double)ROT_SPEED) + \
		v->player.dir_y * cos((double)ROT_SPEED);
	v->camera.oldplane_x = v->camera.plane_x;
	v->camera.plane_x = v->camera.plane_x * cos((double)ROT_SPEED) - \
		v->camera.plane_y * sin((double)ROT_SPEED);
	v->camera.plane_y = v->camera.oldplane_x * sin((double)ROT_SPEED) + \
		v->camera.plane_y * cos((double)ROT_SPEED);
}
