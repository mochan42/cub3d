/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_7.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 21:00:02 by moninechan        #+#    #+#             */
/*   Updated: 2023/01/01 20:30:49 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	check_ceil_and_floor_color(t_prg *v, int *validator)
{
	int	checker;
	int	j;

	checker = 0;
	while (v->map_i < v->row && checker <= 1)
	{
		j = 0;
		while (v->map[v->map_i][j] && v->map[v->map_i][j] == 32)
			j++;
		skype_spaces(v, v->map_i, &j);
		if (find_floor_ceilling(v, &j, validator, checker) == 1)
			return (1);
		checker++;
		if (is_color_valid(v, validator) == 1)
			return (1);
		if (checker == 1)
			v->tex.floor_color = create_trgb(0, v->rgb[0], v->rgb[1], \
				v->rgb[2]);
		else if (checker == 2)
			v->tex.ceiling_color = create_trgb(0, v->rgb[0], v->rgb[1], \
				v->rgb[2]);
		v->map_i++;
		skipe_empty_line(v);
	}
	return (0);
}

int	is_valid_map_extension(t_prg *v, int *p_len, int *validator, int *is_pos)
{
	if (access(v->map_path, F_OK) != 0)
	{
		printf("Invalid path for the .cub file\n");
		*validator = 1;
		return (1);
	}
	*p_len = ft_strlen(v->map_path);
	*is_pos = 0;
	if (ft_strncmp(&v->map_path[*p_len - 4], ".cub", 4) != 0)
	{
		printf("Invalid map : The file extension should be .cub \n");
		*validator = 1;
		return (1);
	}
	return (0);
}

int	is_empty_line(t_prg *v, int i, int *validator)
{
	if (v->map[i][0] == '\0')
	{
		printf("Invalid map\n");
		*validator = 1;
		return (1);
	}
	return (0);
}

int	is_valid_char(t_prg *v, int i, int j, int *validator)
{
	if (!is_allowed_char(v->map[i][j]) && (v->map[i][j] != 32 && \
		v->map[i][j] != '\n'))
	{
		printf("Invalid character in map\n");
		*validator = 1;
		return (1);
	}
	return (0);
}

void	valid_init_position(int is_pos, int *validator)
{
	if (!is_pos)
	{
		printf("The map should have a player (N, S, W, E)\n");
		*validator = 1;
	}
	else if (is_pos > 1)
	{
		*validator = 1;
		printf("The map should have only one player position\n");
	}	
}
