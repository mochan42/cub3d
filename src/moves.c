/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:56:11 by moninechan        #+#    #+#             */
/*   Updated: 2022/12/11 19:51:54 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void    move_forward(t_prg *v)
{
	// printf("move forward\n");
    if(v->map[(int)v->player.posY][(int)(v->player.posX + v->player.dirX * (double)MOVE_SPEED)] != '1')
		v->player.posX += v->player.dirX * (double)MOVE_SPEED;
    if(v->map[(int)(v->player.posY + v->player.dirY * (double)MOVE_SPEED)][(int)(v->player.posX)] != '1')
		v->player.posY += v->player.dirY * (double)MOVE_SPEED;
	printf("posX (after)= %f\n", v->player.posX);
    printf("posY (after)= %f\n", v->player.posY);
}

void    move_backwards(t_prg *v)
{
	// printf("move backwards\n");
    if(v->map[(int)v->player.posY][(int)(v->player.posX - v->player.dirX * (double)MOVE_SPEED)] != '1')
		v->player.posX -= v->player.dirX * (double)MOVE_SPEED;
    if(v->map[(int)(v->player.posY - v->player.dirY * (double)MOVE_SPEED)][(int)(v->player.posX)] != '1')
		v->player.posY -= v->player.dirY * (double)MOVE_SPEED;
	printf("posX (after)= %f\n", v->player.posX);
    printf("posY (after)= %f\n", v->player.posY);
}

void    move_left(t_prg *v)
{
	printf("move left\n");

    if(v->player.dirX >= 0 && v->player.dirY < 0 && \
		v->map[(int)v->player.posY][(int)v->player.posX] == '0')
	{
		v->player.posX -= fabs(v->player.dirY) * (double)MOVE_SPEED;
		v->player.posY += fabs(v->player.dirX) * (double)MOVE_SPEED;
	}
	if(v->player.dirX >= 0 && v->player.dirY >= 0 && \
		v->map[(int)v->player.posY][(int)v->player.posX] == '0')
	{
		v->player.posX += fabs(v->player.dirY) * (double)MOVE_SPEED;
		v->player.posY -= fabs(v->player.dirX) * (double)MOVE_SPEED;
	}
	if(v->player.dirX < 0 && v->player.dirY < 0 && \
		v->map[(int)v->player.posY][(int)v->player.posX] == '0')
	{
		v->player.posX -= fabs(v->player.dirY) * (double)MOVE_SPEED;
		v->player.posY -= fabs(v->player.dirX) * (double)MOVE_SPEED;
	}	
    if(v->player.dirX < 0 && v->player.dirY >= 0 && \
		v->map[(int)v->player.posY][(int)v->player.posX] == '0')
	{
		v->player.posX += fabs(v->player.dirY) * (double)MOVE_SPEED;
		v->player.posY += fabs(v->player.dirX) * (double)MOVE_SPEED;
	}
	printf("posX (after)= %f\n", v->player.posX);
    printf("posY (after)= %f\n", v->player.posY);
}


void    move_right(t_prg *v)
{
	printf("move right\n");

    if(v->player.dirX >= 0 && v->player.dirY < 0 && \
		v->map[(int)v->player.posY][(int)v->player.posX] == '0')
	{
		v->player.posX += fabs(v->player.dirY) * (double)MOVE_SPEED;
		v->player.posY -= fabs(v->player.dirX) * (double)MOVE_SPEED;
	}
	if(v->player.dirX >= 0 && v->player.dirY >= 0 && \
		v->map[(int)v->player.posY][(int)v->player.posX] == '0')
	{
		v->player.posX -= fabs(v->player.dirY) * (double)MOVE_SPEED;
		v->player.posY += fabs(v->player.dirX) * (double)MOVE_SPEED;
	}
	if(v->player.dirX < 0 && v->player.dirY < 0 && \
		v->map[(int)v->player.posY][(int)v->player.posX] == '0')
	{
		v->player.posX += fabs(v->player.dirY) * (double)MOVE_SPEED;
		v->player.posY += fabs(v->player.dirX) * (double)MOVE_SPEED;
	}	
    if(v->player.dirX < 0 && v->player.dirY >= 0 && \
		v->map[(int)v->player.posY][(int)v->player.posX] == '0')
	{
		v->player.posX -= fabs(v->player.dirY) * (double)MOVE_SPEED;
		v->player.posY -= fabs(v->player.dirX) * (double)MOVE_SPEED;
	}
	printf("posX (after)= %f\n", v->player.posX);
    printf("posY (after)= %f\n", v->player.posY);
}