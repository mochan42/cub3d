/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:00:44 by moninechan        #+#    #+#             */
/*   Updated: 2022/12/28 22:06:24 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void    init_camera_pos(t_prg *v)
{
    v->camera.initial_camera_direction = v->map[(int)v->player.posY][(int)v->player.posX];
    printf("initial camera direction : %c\n", v->camera.initial_camera_direction);
    v->map[(int)v->player.posY][(int)v->player.posX] = '0';
}

void    init_camera_dir(t_prg *v)
{  
    if (v->camera.initial_camera_direction == 'N')
    {
        v->camera.planeX = 0.66;
        v->camera.planeY = 0;
    }
    if (v->camera.initial_camera_direction == 'S')
    {
        v->camera.planeX = -0.66;
        v->camera.planeY = 0;
    }
    if (v->camera.initial_camera_direction == 'W')
    {
        v->camera.planeX = 0;
        v->camera.planeY = -0.66;
    }
    if (v->camera.initial_camera_direction == 'E')
    {
        v->camera.planeX = 0;
        v->camera.planeY = 0.66;
    }
    printf("planeX = %f\n", v->camera.planeX);
    printf("planeY = %f\n", v->camera.planeY);
}
