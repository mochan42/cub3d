/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:15:14 by moninechan        #+#    #+#             */
/*   Updated: 2022/12/31 23:37:06 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	find_player_pos(t_prg *v)
{
	int	i;
	int	j;

	j = 0;
	while (j < v->row)
	{
		i = 0;
		while (v->map[j][i] != '\0')
		{
			if (v->map[j][i] == 'N' || v->map[j][i] == 'S' || \
				v->map[j][i] == 'W' || v->map[j][i] == 'E')
			{
				v->player.pos_x = i;
				v->player.pos_y = j;
				break ;
			}
			i++;
		}
		j++;
	}
}

void	init_player_dir(t_prg *v)
{
	if (v->camera.initial_camera_direction == 'N')
	{
		v->player.dir_x = 0;
		v->player.dir_y = -1;
	}
	if (v->camera.initial_camera_direction == 'S')
	{
		v->player.dir_x = 0;
		v->player.dir_y = 1;
	}
	if (v->camera.initial_camera_direction == 'W')
	{
		v->player.dir_x = -1;
		v->player.dir_y = 0;
	}
	if (v->camera.initial_camera_direction == 'E')
	{
		v->player.dir_x = 1;
		v->player.dir_y = 0;
	}
}
