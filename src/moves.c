/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:56:11 by moninechan        #+#    #+#             */
/*   Updated: 2022/12/28 17:46:5918 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void    move_forward(t_prg *v)
{
	printf("move forward\n");
	// printf("\tposX (before)= %f\n", v->player.posX);
    // printf("\tposY (before)= %f\n", v->player.posY);
    if(v->map[(int)v->player.posY][(int)(v->player.posX + v->player.dirX * (double)MOVE_SPEED)] == '0')
		v->player.posX += v->player.dirX * (double)MOVE_SPEED;
    if(v->map[(int)(v->player.posY + v->player.dirY * (double)MOVE_SPEED)][(int)(v->player.posX)] == '0')
		v->player.posY += v->player.dirY * (double)MOVE_SPEED;
	printf("\tposX (after)= %f\n", v->player.posX);
    printf("\tposY (after)= %f\n", v->player.posY);
	printf("\t(int)posX (after)= %d\n", (int)v->player.posX);
    printf("\t(int)posY (after)= %d\n", (int)v->player.posY);
	printf("CONTENT : %c\n", v->map[(int)v->player.posY][(int)v->player.posX]);
}

void    move_backwards(t_prg *v)
{
	printf("move backwards\n");
	// printf("\tposX (before)= %f\n", v->player.posX);
    // printf("\tposY (before)= %f\n", v->player.posY);
    if(v->map[(int)v->player.posY][(int)(v->player.posX - v->player.dirX * (double)MOVE_SPEED)] != '1')
		v->player.posX -= v->player.dirX * (double)MOVE_SPEED;
    if(v->map[(int)(v->player.posY - v->player.dirY * (double)MOVE_SPEED)][(int)(v->player.posX)] != '1')
		v->player.posY -= v->player.dirY * (double)MOVE_SPEED;
	printf("\tposX (after)= %f\n", v->player.posX);
    printf("\tposY (after)= %f\n", v->player.posY);
	printf("\t(int)posX (after)= %d\n", (int)v->player.posX);
    printf("\t(int)posY (after)= %d\n", (int)v->player.posY);
	printf("CONTENT : %c\n", v->map[(int)v->player.posY][(int)v->player.posX]);
}



// void    move_forward(t_prg *v)
// {
// 	int tp1_i;
// 	int tp1_j;
// 	int tp2_i;
// 	int tp2_j;
// 	printf("move forward\n");
// 	printf("\tposX (before)= %f\n", v->player.posX);
//     printf("\tposY (before)= %f\n", v->player.posY);
// 	tp1_i = (int)v->player.posY;
// 	tp2_j = (int)v->player.posX + v->player.dirX * (double)MOVE_SPEED;
//     if((v->map[tp1_i] && v->map[tp1_i][tp2_j]) && (v->map[tp1_i][tp2_j]!= '1' && v->map[tp1_i][tp2_j] != '\n'))
// 		v->player.posX += v->player.dirX * (double)MOVE_SPEED;
// 	tp2_i = (int)v->player.posY + v->player.dirY * (double)MOVE_SPEED;
// 	tp1_j = (int)v->player.posX;
//     if((v->map[tp2_i] && v->map[tp2_i][tp1_j]) && (v->map[tp2_i][tp1_j] != '1' && v->map[tp2_i][tp1_j] != '\n'))
// 		v->player.posY += v->player.dirY * (double)MOVE_SPEED;
// 	printf("\tposX (after)= %f\n", v->player.posX);
//     printf("\tposY (after)= %f\n", v->player.posY);
// 	printf("\ttp1_i (after)= %d\n", tp1_i);
//     printf("\ttp2_j (after)= %d\n", tp2_j);
// 	printf("\ttp2_i (after)= %d\n", tp2_i);
//     printf("\ttp1_j (after)= %d\n", tp1_j);
// }

// void    move_backwards(t_prg *v)
// {
// 	int tp1_i;
// 	int tp1_j;
// 	int tp2_i;
// 	int tp2_j;
// 	// printf("move backwards\n");
// 	// printf("\tposX (before)= %f\n", v->player.posX);
//     // printf("\tposY (before)= %f\n", v->player.posY);
// 	tp1_i = (int)v->player.posY;
// 	tp2_j = (int)v->player.posX - v->player.dirX * (double)MOVE_SPEED;
// 	if((v->map[tp1_i] && v->map[tp1_i][tp2_j]) && (v->map[tp1_i][tp2_j]!= '1' && v->map[tp1_i][tp2_j]!= '\n'))
//     // if(v->map[(int)v->player.posY][(int)(v->player.posX - v->player.dirX * (double)MOVE_SPEED)] != '1')
// 		v->player.posX -= v->player.dirX * (double)MOVE_SPEED;
// 	tp2_i = (int)v->player.posY - v->player.dirY * (double)MOVE_SPEED;
// 	tp1_j = (int)v->player.posX;
//     if((v->map[tp2_i] && v->map[tp2_i][tp1_j]) && (v->map[tp2_i][tp1_j] != '1' && v->map[tp2_i][tp1_j] != '\n'))
//     // if(v->map[(int)(v->player.posY - v->player.dirY * (double)MOVE_SPEED)][(int)(v->player.posX)] != '1')
// 		v->player.posY -= v->player.dirY * (double)MOVE_SPEED;
// 	// printf("\tposX (after)= %f\n", v->player.posX);
//     // printf("\tposY (after)= %f\n", v->player.posY);
// }

void    move_left(t_prg *v)
{
	printf("move left\n");
	// printf("\tposX (before)= %f\n", v->player.posX);
    // printf("\tposY (before)= %f\n", v->player.posY);
    if((v->player.dirX >= 0 && v->player.dirY < 0) && \
		v->map[(int)v->player.posY][(int)v->player.posX] == '0')
	{
		if (v->map[(int)(v->player.posY - fabs(v->player.dirX) * (double)MOVE_SPEED)]
			&& v->map[(int)(v->player.posY - fabs(v->player.dirX) * (double)MOVE_SPEED)][(int)(v->player.posX - fabs(v->player.dirY) * (double)MOVE_SPEED)] == '0')
		{
			v->player.posX -= fabs(v->player.dirY) * (double)MOVE_SPEED;
			v->player.posY -= fabs(v->player.dirX) * (double)MOVE_SPEED;
		}
		// v->player.posY += fabs(v->player.dirX) * (double)MOVE_SPEED;
	}
	if((v->player.dirX >= 0 && v->player.dirY >= 0) && \
		v->map[(int)v->player.posY][(int)v->player.posX] == '0')
	{
		if (v->map[(int)(v->player.posY - fabs(v->player.dirX) * (double)MOVE_SPEED)]
			&& v->map[(int)(v->player.posY -fabs(v->player.dirX) * (double)MOVE_SPEED)][(int)(v->player.posX + fabs(v->player.dirY) * (double)MOVE_SPEED)] == '0')
		{
			v->player.posX += fabs(v->player.dirY) * (double)MOVE_SPEED;
			v->player.posY -= fabs(v->player.dirX) * (double)MOVE_SPEED;
		}
	}
	if((v->player.dirX < 0 && v->player.dirY < 0) && \
		v->map[(int)v->player.posY][(int)v->player.posX] == '0')
	{
		if (v->map[(int)(v->player.posX - fabs(v->player.dirY) * (double)MOVE_SPEED)]
			&& v->map[(int)(v->player.posY + fabs(v->player.dirX) * (double)MOVE_SPEED)][(int)(v->player.posX - fabs(v->player.dirY) * (double)MOVE_SPEED)] == '0')
		{
			v->player.posX -= fabs(v->player.dirY) * (double)MOVE_SPEED;
			v->player.posY += fabs(v->player.dirX) * (double)MOVE_SPEED;
		}
	}	
    if((v->player.dirX < 0 && v->player.dirY >= 0) && \
		v->map[(int)v->player.posY][(int)v->player.posX] == '0')
	{
		if (v->map[(int)(v->player.posY + fabs(v->player.dirX) * (double)MOVE_SPEED)]
			&& v->map[(int)(v->player.posY + fabs(v->player.dirX) * (double)MOVE_SPEED)][(int)(v->player.posX + fabs(v->player.dirY) * (double)MOVE_SPEED)] == '0')
		{
			v->player.posX += fabs(v->player.dirY) * (double)MOVE_SPEED;
			v->player.posY += fabs(v->player.dirX) * (double)MOVE_SPEED;
		}
	}
	printf("\tposX (after)= %f\n", v->player.posX);
    printf("\tposY (after)= %f\n", v->player.posY);
	printf("\t(int)posX (after)= %d\n", (int)v->player.posX);
    printf("\t(int)posY (after)= %d\n", (int)v->player.posY);
	printf("CONTENT : %c\n", v->map[(int)v->player.posY][(int)v->player.posX]);
}

void    move_right(t_prg *v)
{
	printf("move right\n");
	// printf("\tposX (before)= %f\n", v->player.posX);
    // printf("\tposY (before)= %f\n", v->player.posY);
	printf("\tdirX (before)= %f\n", v->player.dirX);
	printf("\tdirY (before)= %f\n", v->player.dirY);
    if((v->player.dirX >= 0 && v->player.dirY < 0) && \
		v->map[(int)v->player.posY][(int)v->player.posX] == '0')
	{
		if (v->map[(int)(v->player.posY + fabs(v->player.dirX) * (double)MOVE_SPEED)]
			&& v->map[(int)(v->player.posY + fabs(v->player.dirX) * (double)MOVE_SPEED)][(int)(v->player.posX + fabs(v->player.dirY)* (double)MOVE_SPEED)] == '0')
		{
			v->player.posX += fabs(v->player.dirY) * (double)MOVE_SPEED;
			v->player.posY += fabs(v->player.dirX) * (double)MOVE_SPEED;
		}
	}
	if((v->player.dirX >= 0 && v->player.dirY >= 0) && \
		v->map[(int)v->player.posY][(int)v->player.posX] == '0')
	{
		if(v->map[(int)(v->player.posY + fabs(v->player.dirX) * (double)MOVE_SPEED)]
			&& v->map[(int)(v->player.posY + fabs(v->player.dirX) * (double)MOVE_SPEED)][(int)(v->player.posX - fabs(v->player.dirY) * (double)MOVE_SPEED)] == '0')
		{
			v->player.posX -= fabs(v->player.dirY) * (double)MOVE_SPEED;
			v->player.posY += fabs(v->player.dirX) * (double)MOVE_SPEED;
		}
	}
	if((v->player.dirX < 0 && v->player.dirY < 0) && \
		v->map[(int)v->player.posY][(int)v->player.posX] == '0')
	{
		if (v->map[(int)(v->player.posY - fabs(v->player.dirX) * (double)MOVE_SPEED)]
			&& v->map[(int)(v->player.posY - fabs(v->player.dirX) * (double)MOVE_SPEED)][(int)(v->player.posX + fabs(v->player.dirY) * (double)MOVE_SPEED)] == '0')
		{
			v->player.posX += fabs(v->player.dirY) * (double)MOVE_SPEED;
			v->player.posY -= fabs(v->player.dirX) * (double)MOVE_SPEED;
		}
	}	
    if((v->player.dirX < 0 && v->player.dirY >= 0) && \
		v->map[(int)v->player.posY][(int)v->player.posX] == '0')
	{
		if(v->map[(int)(v->player.posY - fabs(v->player.dirX) * (double)MOVE_SPEED)]
			&& v->map[(int)(v->player.posY - fabs(v->player.dirX) * (double)MOVE_SPEED)][(int)(v->player.posX - fabs(v->player.dirY) * (double)MOVE_SPEED) == '0'])
		{
			v->player.posX -= fabs(v->player.dirY) * (double)MOVE_SPEED;
			v->player.posY -= fabs(v->player.dirX) * (double)MOVE_SPEED;
		}
	}
	printf("\tposX (after)= %f\n", v->player.posX);
    printf("\tposY (after)= %f\n", v->player.posY);
	printf("\t(int)posX (after)= %d\n", (int)v->player.posX);
    printf("\t(int)posY (after)= %d\n", (int)v->player.posY);
	printf("CONTENT : %c\n", v->map[(int)v->player.posY][(int)v->player.posX]);
}

void	rotate_left(t_prg *v)
{
	printf("rotate left\n");
	v->player.oldDirX = v->player.dirX;
    v->player.dirX = v->player.dirX * cos(-(double)ROT_SPEED) - v->player.dirY * sin(-(double)ROT_SPEED);
    v->player.dirY = v->player.oldDirX * sin(-(double)ROT_SPEED) + v->player.dirY * cos(-(double)ROT_SPEED);
    
	v->camera.oldPlaneX = v->camera.planeX;
    v->camera.planeX = v->camera.planeX * cos(-(double)ROT_SPEED) - v->camera.planeY * sin(-(double)ROT_SPEED);
    v->camera.planeY = v->camera.oldPlaneX * sin(-(double)ROT_SPEED) + v->camera.planeY * cos(-(double)ROT_SPEED);	
	printf("\tposX (after)= %f\n", v->player.posX);
    printf("\tposY (after)= %f\n", v->player.posY);
	printf("\t(int)posX (after)= %d\n", (int)v->player.posX);
    printf("\t(int)posY (after)= %d\n", (int)v->player.posY);
	printf("CONTENT : %c\n", v->map[(int)v->player.posY][(int)v->player.posX]);
}

void	rotate_right(t_prg *v)
{
	printf("rotate right\n");
	v->player.oldDirX = v->player.dirX;
    v->player.dirX = v->player.dirX * cos((double)ROT_SPEED) - v->player.dirY * sin((double)ROT_SPEED);
    v->player.dirY = v->player.oldDirX * sin((double)ROT_SPEED) + v->player.dirY * cos((double)ROT_SPEED);
    v->camera.oldPlaneX = v->camera.planeX;
    v->camera.planeX = v->camera.planeX * cos((double)ROT_SPEED) - v->camera.planeY * sin((double)ROT_SPEED);
    v->camera.planeY = v->camera.oldPlaneX * sin((double)ROT_SPEED) + v->camera.planeY * cos((double)ROT_SPEED);
	printf("\tposX (after)= %f\n", v->player.posX);
    printf("\tposY (after)= %f\n", v->player.posY);
	printf("\t(int)posX (after)= %d\n", (int)v->player.posX);
    printf("\t(int)posY (after)= %d\n", (int)v->player.posY);
	printf("CONTENT : %c\n", v->map[(int)v->player.posY][(int)v->player.posX]);
}
