/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:56:11 by moninechan        #+#    #+#             */
/*   Updated: 2022/12/10 19:44:43 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void    move_forward(t_prg *v)
{
    printf("move forward\n");
	//printf("v->row = %d\n", v->row);
	// print_map(v);
	// find_player_pos(v);
	printf("posX = %f\n", v->player.posX);
    printf("posY = %f\n", v->player.posY);
    // if(v->map[(int)(v->player.posX + v->player.dirX * (double)MOVE_SPEED)][(int)v->player.posY] != '1')
	// 	v->player.posX += v->player.dirX * (double)MOVE_SPEED;
    // if(v->map[(int)(v->player.posX)][(int)(v->player.posY + v->player.dirY * (double)MOVE_SPEED)] != '1')
	// 	v->player.posY += v->player.dirY * (double)MOVE_SPEED;
	// printf("posX = %f\n", v->player.posX);
    // printf("posY = %f\n", v->player.posY);
}
