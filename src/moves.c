/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:56:11 by moninechan        #+#    #+#             */
/*   Updated: 2022/12/11 11:00:12 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void    move_forward(t_prg *v)
{
    // double tmp;
	
	printf("move forward\n");
	// printf("posX (before)= %f\n", v->player.posX);
    // printf("posY (before)= %f\n", v->player.posY);
	// printf("dirX (before)= %f\n", v->player.dirX);
	// printf("dirY (before)= %f\n", v->player.dirY);
	// printf("MOVE_SPEED= %f\n", (double)MOVE_SPEED);
    if(v->map[(int)v->player.posY][(int)(v->player.posX + v->player.dirX * (double)MOVE_SPEED)] != '1')
		v->player.posX += v->player.dirX * (double)MOVE_SPEED;
    if(v->map[(int)(v->player.posY + v->player.dirY * (double)MOVE_SPEED)][(int)(v->player.posX)] != '1')
		v->player.posY += v->player.dirY * (double)MOVE_SPEED;
	printf("posX (after)= %f\n", v->player.posX);
    printf("posY (after)= %f\n", v->player.posY);
}
