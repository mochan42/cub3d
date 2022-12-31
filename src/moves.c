/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:56:11 by moninechan        #+#    #+#             */
/*   Updated: 2022/12/31 19:01:43 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void    move_forward(t_prg *v)
{
    if(v->map[(int)v->player.posY][(int)(v->player.posX + v->player.dirX * \
		(double)MOVE_SPEED)] == '0')
		v->player.posX += v->player.dirX * (double)MOVE_SPEED;
    if(v->map[(int)(v->player.posY + v->player.dirY * (double)MOVE_SPEED)]\
		[(int)(v->player.posX)] == '0')
		v->player.posY += v->player.dirY * (double)MOVE_SPEED;
}

void    move_backwards(t_prg *v)
{
    if(v->map[(int)v->player.posY][(int)(v->player.posX - v->player.dirX * \
		(double)MOVE_SPEED)] != '1')
		v->player.posX -= v->player.dirX * (double)MOVE_SPEED;
    if(v->map[(int)(v->player.posY - v->player.dirY * (double)MOVE_SPEED)]\
		[(int)(v->player.posX)] != '1')
		v->player.posY -= v->player.dirY * (double)MOVE_SPEED;
}

void	move_left_dirXPos_dirYNeg(t_prg *v)
{
    if((v->player.dirX >= 0 && v->player.dirY < 0) && \
		v->map[(int)v->player.posY][(int)v->player.posX] == '0')
	{
		if (v->map[(int)(v->player.posY - fabs(v->player.dirX) * \
			(double)MOVE_SPEED)] && v->map[(int)(v->player.posY - \
			fabs(v->player.dirX) * (double)MOVE_SPEED)]\
			[(int)(v->player.posX - fabs(v->player.dirY) * \
			(double)MOVE_SPEED)] == '0')
		{
			v->player.posX -= fabs(v->player.dirY) * (double)MOVE_SPEED;
			v->player.posY -= fabs(v->player.dirX) * (double)MOVE_SPEED;
		}
	}
}

void	move_left_dirXPos_dirYPos(t_prg *v)
{
	if((v->player.dirX >= 0 && v->player.dirY >= 0) && \
		v->map[(int)v->player.posY][(int)v->player.posX] == '0')
	{
		if (v->map[(int)(v->player.posY - fabs(v->player.dirX) * \
			(double)MOVE_SPEED)] && v->map[(int)(v->player.posY - \
			fabs(v->player.dirX) * (double)MOVE_SPEED)]\
			[(int)(v->player.posX + fabs(v->player.dirY) * \
			(double)MOVE_SPEED)] == '0')
		{
			v->player.posX += fabs(v->player.dirY) * (double)MOVE_SPEED;
			v->player.posY -= fabs(v->player.dirX) * (double)MOVE_SPEED;
		}
	}
}

void	move_left_dirXNeg_dirYNeg(t_prg *v)
{
	if((v->player.dirX < 0 && v->player.dirY < 0) && \
		v->map[(int)v->player.posY][(int)v->player.posX] == '0')
	{
		if (v->map[(int)(v->player.posX - fabs(v->player.dirY) * \
			(double)MOVE_SPEED)] && v->map[(int)(v->player.posY + \
			fabs(v->player.dirX) * (double)MOVE_SPEED)]\
			[(int)(v->player.posX - fabs(v->player.dirY) * \
			(double)MOVE_SPEED)] == '0')
		{
			v->player.posX -= fabs(v->player.dirY) * (double)MOVE_SPEED;
			v->player.posY += fabs(v->player.dirX) * (double)MOVE_SPEED;
		}
	}	
}

void	move_left_dirXNeg_dirYPos(t_prg *v)
{
	if((v->player.dirX < 0 && v->player.dirY >= 0) && \
		v->map[(int)v->player.posY][(int)v->player.posX] == '0')
	{
		if (v->map[(int)(v->player.posY + fabs(v->player.dirX) * \
			(double)MOVE_SPEED)] && v->map[(int)(v->player.posY + \
			fabs(v->player.dirX) * (double)MOVE_SPEED)]\
			[(int)(v->player.posX + fabs(v->player.dirY) * \
			(double)MOVE_SPEED)] == '0')
		{
			v->player.posX += fabs(v->player.dirY) * (double)MOVE_SPEED;
			v->player.posY += fabs(v->player.dirX) * (double)MOVE_SPEED;
		}
	}
}

void    move_left(t_prg *v)
{
	move_left_dirXPos_dirYNeg(v);
	move_left_dirXPos_dirYPos(v);
	move_left_dirXNeg_dirYNeg(v);
	move_left_dirXNeg_dirYPos(v);
}

void	move_right_dirXPos_dirYNeg(t_prg *v)
{
    if((v->player.dirX >= 0 && v->player.dirY < 0) && \
		v->map[(int)v->player.posY][(int)v->player.posX] == '0')
	{
		printf("1st if\n");
		if (v->map[(int)(v->player.posY + fabs(v->player.dirX) *\
			(double)MOVE_SPEED)] && v->map[(int)(v->player.posY +\
			fabs(v->player.dirX) * (double)MOVE_SPEED)]\
			[(int)(v->player.posX + fabs(v->player.dirY)*\
			(double)MOVE_SPEED)] == '0')
		{
			printf("2nd if\n");
			v->player.posX += fabs(v->player.dirY) * (double)MOVE_SPEED;
			v->player.posY += fabs(v->player.dirX) * (double)MOVE_SPEED;
		}
	}	
}

void	move_right_dirXPos_dirYPos(t_prg *v)
{
	if((v->player.dirX >= 0 && v->player.dirY >= 0) && \
		v->map[(int)v->player.posY][(int)v->player.posX] == '0')
	{
		if(v->map[(int)(v->player.posY + fabs(v->player.dirX) *\
			(double)MOVE_SPEED)] && v->map[(int)(v->player.posY +\
			fabs(v->player.dirX) * (double)MOVE_SPEED)]\
			[(int)(v->player.posX - fabs(v->player.dirY) *\
			(double)MOVE_SPEED)] == '0')
		{
			v->player.posX -= fabs(v->player.dirY) * (double)MOVE_SPEED;
			v->player.posY += fabs(v->player.dirX) * (double)MOVE_SPEED;
		}
	}
}

void	move_right_dirXNeg_dirYNeg(t_prg *v)
{
	if((v->player.dirX < 0 && v->player.dirY < 0) && \
		v->map[(int)v->player.posY][(int)v->player.posX] == '0')
	{
		if (v->map[(int)(v->player.posY - fabs(v->player.dirX) *\
			(double)MOVE_SPEED)] && v->map[(int)(v->player.posY - \
			fabs(v->player.dirX) * (double)MOVE_SPEED)]\
			[(int)(v->player.posX + fabs(v->player.dirY) *\
			(double)MOVE_SPEED)] == '0')
		{
			v->player.posX += fabs(v->player.dirY) * (double)MOVE_SPEED;
			v->player.posY -= fabs(v->player.dirX) * (double)MOVE_SPEED;
		}
	}	
}

void	move_right_dirXNeg_dirYPos(t_prg *v)
{
    if((v->player.dirX < 0 && v->player.dirY >= 0) && \
		v->map[(int)v->player.posY][(int)v->player.posX] == '0')
	{
		if(v->map[(int)(v->player.posY - fabs(v->player.dirX) *\
			(double)MOVE_SPEED)] && v->map[(int)(v->player.posY -\
			fabs(v->player.dirX) * (double)MOVE_SPEED)]\
			[(int)(v->player.posX - fabs(v->player.dirY) *\
			(double)MOVE_SPEED)] == '0')
		{
			v->player.posX -= fabs(v->player.dirY) * (double)MOVE_SPEED;
			v->player.posY -= fabs(v->player.dirX) * (double)MOVE_SPEED;
		}
	}	
}

void    move_right(t_prg *v)
{
	move_right_dirXPos_dirYNeg(v);
	move_right_dirXPos_dirYPos(v);
	move_right_dirXNeg_dirYNeg(v);
	move_right_dirXNeg_dirYPos(v);
}

void	rotate_left(t_prg *v)
{
	v->player.oldDirX = v->player.dirX;
    v->player.dirX = v->player.dirX * cos(-(double)ROT_SPEED) -\
		v->player.dirY * sin(-(double)ROT_SPEED);
    v->player.dirY = v->player.oldDirX * sin(-(double)ROT_SPEED) +\
		v->player.dirY * cos(-(double)ROT_SPEED);
    
	v->camera.oldPlaneX = v->camera.planeX;
    v->camera.planeX = v->camera.planeX * cos(-(double)ROT_SPEED) -\
		v->camera.planeY * sin(-(double)ROT_SPEED);
    v->camera.planeY = v->camera.oldPlaneX * sin(-(double)ROT_SPEED) +\
		v->camera.planeY * cos(-(double)ROT_SPEED);
}

void	rotate_right(t_prg *v)
{
	v->player.oldDirX = v->player.dirX;
    v->player.dirX = v->player.dirX * cos((double)ROT_SPEED) -\
		v->player.dirY * sin((double)ROT_SPEED);
    v->player.dirY = v->player.oldDirX * sin((double)ROT_SPEED) +\
		v->player.dirY * cos((double)ROT_SPEED);
    v->camera.oldPlaneX = v->camera.planeX;
    v->camera.planeX = v->camera.planeX * cos((double)ROT_SPEED) -\
		v->camera.planeY * sin((double)ROT_SPEED);
    v->camera.planeY = v->camera.oldPlaneX * sin((double)ROT_SPEED) +\
		v->camera.planeY * cos((double)ROT_SPEED);
}
