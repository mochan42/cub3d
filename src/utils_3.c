/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 20:37:49 by moninechan        #+#    #+#             */
/*   Updated: 2022/12/31 20:38:20 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	is_valid_len_points(int j, int *validator)
{
	if (j != 2)
	{
		printf("Invalid map : Wrong Identifier \n");
		*validator = 1;
		return (1);
	}
	return (0);
}

void	skype_spaces(t_prg *v, int i, int *j)
{
	while (v->map[i][*j] && v->map[i][*j] == 32)
		*j += 1;
}

int	is_valid_card_points(t_prg *v, int card_pt[4], int *validator, int i)
{
	if (ft_strncmp(ft_substr(v->map[i], 0, 2), "NO", 2) == 0 && card_pt[0])
		card_pt[0] = 0;
	else if (ft_strncmp(ft_substr(v->map[i], 0, 2), "SO", 2) == 0 && \
		!card_pt[0])
		card_pt[1] = 0;
	else if (ft_strncmp(ft_substr(v->map[i], 0, 2), "WE", 2) == 0 && \
		!card_pt[1])
		card_pt[2] = 0;
	else if (ft_strncmp(ft_substr(v->map[i], 0, 2), "EA", 2) == 0 && \
		!card_pt[2])
		card_pt[3] = 0;
	else
	{
		printf("Invalid map : Wrong Identifier \n");
		*validator = 1;
		return (1);
	}
	return (0);
}

int	is_valid_textures_paths(t_prg *v, int i, int *j, int *validator)
{
	while (v->map[i][*j] && (v->map[i][*j] != ' ' && v->map[i][*j] != '\n'))
		*j += 1;
	if (v->map[i][*j] == ' ')
	{
		printf("Invalid map : Wrong texture path\n");
		*validator = 1;
		return (1);
	}
	else if (ft_strncmp(&v->map[i][*j - 4], ".xpm\n", 5) != 0)
	{
		printf("Invalid map : Invalid texture extension\n");
		*validator = 1;
		return (1);
	}
	return (0);
}

int	assign_path_to_texture(t_prg *v, int texture, char *path)
{
	if (access(path, F_OK) != 0)
	{
		printf("Invalid map : path texture not found !\n");
		return (1);
	}
	if (texture == 1)
		v->tex.path_no = ft_strdup(path);
	if (texture == 2)
		v->tex.path_so = ft_strdup(path);
	if (texture == 3)
		v->tex.path_we = ft_strdup(path);
	if (texture == 4)
		v->tex.path_ea = ft_strdup(path);
	return (0);
}
