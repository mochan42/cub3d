/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 22:45:31 by moninechan        #+#    #+#             */
/*   Updated: 2023/01/01 01:20:53 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	move_right_dir_x_pos_and_dir_y_neg(t_prg *v)
{
	if ((v->player.dir_x >= 0 && v->player.dir_y < 0) && \
		v->map[(int)v->player.pos_y][(int)v->player.pos_x] == '0')
	{
		if (v->map[(int)(v->player.pos_y + fabs(v->player.dir_x) * \
			(double)MOVE_SPEED)] && v->map[(int)(v->player.pos_y + \
			fabs(v->player.dir_x) * (double)MOVE_SPEED)] \
			[(int)(v->player.pos_x + fabs(v->player.dir_y) * \
			(double)MOVE_SPEED)] == '0')
		{
			v->player.pos_x += fabs(v->player.dir_y) * (double)MOVE_SPEED;
			v->player.pos_y += fabs(v->player.dir_x) * (double)MOVE_SPEED;
		}
	}	
}

void	move_right_dir_x_pos_and_dir_y_pos(t_prg *v)
{
	if ((v->player.dir_x >= 0 && v->player.dir_y >= 0) && \
		v->map[(int)v->player.pos_y][(int)v->player.pos_x] == '0')
	{
		if (v->map[(int)(v->player.pos_y + fabs(v->player.dir_x) * \
			(double)MOVE_SPEED)] && v->map[(int)(v->player.pos_y + \
			fabs(v->player.dir_x) * (double)MOVE_SPEED)] \
			[(int)(v->player.pos_x - fabs(v->player.dir_y) * \
			(double)MOVE_SPEED)] == '0')
		{
			v->player.pos_x -= fabs(v->player.dir_y) * (double)MOVE_SPEED;
			v->player.pos_y += fabs(v->player.dir_x) * (double)MOVE_SPEED;
		}
	}
}

void	move_right_dir_x_neg_and_dir_y_neg(t_prg *v)
{
	if ((v->player.dir_x < 0 && v->player.dir_y < 0) && \
		v->map[(int)v->player.pos_y][(int)v->player.pos_x] == '0')
	{
		if (v->map[(int)(v->player.pos_y - fabs(v->player.dir_x) * \
			(double)MOVE_SPEED)] && v->map[(int)(v->player.pos_y - \
			fabs(v->player.dir_x) * (double)MOVE_SPEED)] \
			[(int)(v->player.pos_x + fabs(v->player.dir_y) * \
			(double)MOVE_SPEED)] == '0')
		{
			v->player.pos_x += fabs(v->player.dir_y) * (double)MOVE_SPEED;
			v->player.pos_y -= fabs(v->player.dir_x) * (double)MOVE_SPEED;
		}
	}	
}

void	move_right_dir_x_neg_and_dir_y_pos(t_prg *v)
{
	if ((v->player.dir_x < 0 && v->player.dir_y >= 0) && \
		v->map[(int)v->player.pos_y][(int)v->player.pos_x] == '0')
	{
		if (v->map[(int)(v->player.pos_y - fabs(v->player.dir_x) * \
			(double)MOVE_SPEED)] && v->map[(int)(v->player.pos_y - \
			fabs(v->player.dir_x) * (double)MOVE_SPEED)] \
			[(int)(v->player.pos_x - fabs(v->player.dir_y) * \
			(double)MOVE_SPEED)] == '0')
		{
			v->player.pos_x -= fabs(v->player.dir_y) * (double)MOVE_SPEED;
			v->player.pos_y -= fabs(v->player.dir_x) * (double)MOVE_SPEED;
		}
	}	
}

void	move_right(t_prg *v)
{
	move_right_dir_x_pos_and_dir_y_neg(v);
	move_right_dir_x_pos_and_dir_y_pos(v);
	move_right_dir_x_neg_and_dir_y_neg(v);
	move_right_dir_x_neg_and_dir_y_pos(v);
}
