/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_9.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 23:52:33 by moninechan        #+#    #+#             */
/*   Updated: 2022/12/31 23:54:12 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	free_2d_char(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	if (map[i] != NULL)
		free(map[i]);
	if (map != NULL)
		free(map);
	map = NULL;
}

void	free_cub3d(t_prg *v)
{
	if (v->map_path != NULL)
		free(v->map_path);
	if (v->map != NULL)
		free_2d_char(v->map);
	if (v->tex.path_no != NULL)
		free(v->tex.path_no);
	if (v->tex.path_so != NULL)
		free(v->tex.path_so);
	if (v->tex.path_ea != NULL)
		free(v->tex.path_ea);
	if (v->tex.path_we != NULL)
		free(v->tex.path_we);
	if (v != NULL)
		free(v);
}

int	ft_close_window(t_prg *v)
{
	mlx_destroy_window(v->mlx, v->mlx_win);
	free_cub3d(v);
	printf("exit cub3D\n");
	exit (0);
}
