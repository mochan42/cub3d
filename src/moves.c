/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:56:11 by moninechan        #+#    #+#             */
/*   Updated: 2022/12/27 22:58:41 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void    move_forward(t_prg *v)
{
	// printf("move forward\n");
	// printf("\tposX (before)= %f\n", v->player.posX);
    // printf("\tposY (before)= %f\n", v->player.posY);
    if(v->map[(int)v->player.posY][(int)(v->player.posX + v->player.dirX * (double)MOVE_SPEED)] != '1')
		v->player.posX += v->player.dirX * (double)MOVE_SPEED;
    if(v->map[(int)(v->player.posY + v->player.dirY * (double)MOVE_SPEED)][(int)(v->player.posX)] != '1')
		v->player.posY += v->player.dirY * (double)MOVE_SPEED;
	// printf("\tposX (after)= %f\n", v->player.posX);
    // printf("\tposY (after)= %f\n", v->player.posY);
}

void    move_backwards(t_prg *v)
{
	// printf("move backwards\n");
	// printf("\tposX (before)= %f\n", v->player.posX);
    // printf("\tposY (before)= %f\n", v->player.posY);
    if(v->map[(int)v->player.posY][(int)(v->player.posX - v->player.dirX * (double)MOVE_SPEED)] != '1')
		v->player.posX -= v->player.dirX * (double)MOVE_SPEED;
    if(v->map[(int)(v->player.posY - v->player.dirY * (double)MOVE_SPEED)][(int)(v->player.posX)] != '1')
		v->player.posY -= v->player.dirY * (double)MOVE_SPEED;
	// printf("\tposX (after)= %f\n", v->player.posX);
    // printf("\tposY (after)= %f\n", v->player.posY);
}

void    move_left(t_prg *v)
{
	// printf("move left\n");
	// printf("\tposX (before)= %f\n", v->player.posX);
    // printf("\tposY (before)= %f\n", v->player.posY);
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
	// printf("\tposX (after)= %f\n", v->player.posX);
    // printf("\tposY (after)= %f\n", v->player.posY);
}

void    move_right(t_prg *v)
{
	// printf("move right\n");
	// printf("\tposX (before)= %f\n", v->player.posX);
    // printf("\tposY (before)= %f\n", v->player.posY);
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
	// printf("\tposX (after)= %f\n", v->player.posX);
    // printf("\tposY (after)= %f\n", v->player.posY);
}

void	rotate_left(t_prg *v)
{
	v->player.oldDirX = v->player.dirX;
    v->player.dirX = v->player.dirX * cos(-(double)ROT_SPEED) - v->player.dirY * sin(-(double)ROT_SPEED);
    v->player.dirY = v->player.oldDirX * sin(-(double)ROT_SPEED) + v->player.dirY * cos(-(double)ROT_SPEED);
    
	v->camera.oldPlaneX = v->camera.planeX;
    v->camera.planeX = v->camera.planeX * cos(-(double)ROT_SPEED) - v->camera.planeY * sin(-(double)ROT_SPEED);
    v->camera.planeY = v->camera.oldPlaneX * sin(-(double)ROT_SPEED) + v->camera.planeY * cos(-(double)ROT_SPEED);	
}

void	rotate_right(t_prg *v)
{
	v->player.oldDirX = v->player.dirX;
    v->player.dirX = v->player.dirX * cos((double)ROT_SPEED) - v->player.dirY * sin((double)ROT_SPEED);
    v->player.dirY = v->player.oldDirX * sin((double)ROT_SPEED) + v->player.dirY * cos((double)ROT_SPEED);
    v->camera.oldPlaneX = v->camera.planeX;
    v->camera.planeX = v->camera.planeX * cos((double)ROT_SPEED) - v->camera.planeY * sin((double)ROT_SPEED);
    v->camera.planeY = v->camera.oldPlaneX * sin((double)ROT_SPEED) + v->camera.planeY * cos((double)ROT_SPEED);
}
