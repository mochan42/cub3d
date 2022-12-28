/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:15:14 by moninechan        #+#    #+#             */
/*   Updated: 2022/12/28 20:19:35 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void    find_player_pos(t_prg *v)
{
    int	i;
	int	j;

	j = 0;
	while (j < v->row)
	{
		i = 0;
		while (v->map[j][i] != '\0')
		{
			if (v->map[j][i] == 'N' || v->map[j][i] == 'S' || v->map[j][i] == 'W' || v->map[j][i] == 'E')
            {
				v->player.posX = i;
                v->player.posY = j;
                break ;
            }
			i++;
		}
		j++;
	}
}

void    init_player_dir(t_prg *v)
{
    if (v->camera.initial_camera_direction == 'N')
    {
        v->player.dirX = 0;
        v->player.dirY = -1;
    }
    if (v->camera.initial_camera_direction == 'S')
    {
        v->player.dirX = 0;
        v->player.dirY = 1;
    }
    if (v->camera.initial_camera_direction == 'W')
    {
        v->player.dirX = -1;
        v->player.dirY = 0;
    }
    if (v->camera.initial_camera_direction == 'E')
    {
        v->player.dirX = 1;
        v->player.dirY = 0;
    }
    printf("dirX = %f\n", v->player.dirX);
    printf("dirY = %f\n", v->player.dirY);
}
