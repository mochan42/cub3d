/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 20:55:16 by moninechan        #+#    #+#             */
/*   Updated: 2022/12/31 20:57:28 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	is_color_def_valid(t_prg *v, int nb[2], int j, int *validator)
{
	while (v->map[v->map_i][j])
	{
		if ((nb[0] == nb[1]) || (v->map[v->map_i][j] != '\n' && \
			v->map[v->map_i][j] != ' '))
		{
			printf("Invalid map, bad definition Floor and Ceilling color\n");
			*validator = 1;
			return (1);
		}
		j++;
	}
	return (0);
}

int	is_comma2_respected(t_prg *v, int *j, int *validator)
{
	if (v->nb_rgb[0] == v->nb_rgb[1] || (!v->map[v->map_i][*j] || \
		v->map[v->map_i][*j] != ','))
	{
		printf("Invalid map, bad definition Floor and Ceilling color\n");
		*validator = 1;
		return (1);
	}
	return (0);
}

int	floor_ceilling_color(t_prg *v, int *j, int *validator)
{
	*j += 1;
	skype_spaces(v, v->map_i, j);
	reading_color_num_value(v, v->map_i, j, v->nb_rgb);
	skype_spaces(v, v->map_i, j);
	if (is_comma_respected(v, v->map_i, *j, validator) == 1)
		return (1);
	*j += 1;
	get_color_value(&v->rgb[0], ft_substr(&v->map[v->map_i][v->nb_rgb[0]], 0, \
		v->nb_rgb[1] - v->nb_rgb[0]));
	skype_spaces(v, v->map_i, j);
	reading_color_num_value(v, v->map_i, j, v->nb_rgb);
	skype_spaces(v, v->map_i, j);
	if (is_comma2_respected(v, j, validator) == 1)
		return (1);
	*j += 1;
	get_color_value(&v->rgb[1], ft_substr(&v->map[v->map_i][v->nb_rgb[0]], 0, \
		v->nb_rgb[1] - v->nb_rgb[0]));
	skype_spaces(v, v->map_i, j);
	reading_color_num_value(v, v->map_i, j, v->nb_rgb);
	if (is_color_def_valid(v, v->nb_rgb, *j, validator) == 1)
		return (1);
	get_color_value(&v->rgb[2], ft_substr(&v->map[v->map_i][v->nb_rgb[0]], 0, \
		v->nb_rgb[1] - v->nb_rgb[0]));
	return (0);
}

int	find_floor_ceilling(t_prg *v, int *j, int *validator, int checker)
{
	if (v->map[v->map_i][*j] && (v->map[v->map_i][*j] == 'F' && !checker))
	{
		if (floor_ceilling_color(v, j, validator) == 1)
			return (1);
	}
	else if (v->map[v->map_i][*j] && v->map[v->map_i][*j] == 'C' && \
		checker == 1)
	{
		if (floor_ceilling_color(v, j, validator) == 1)
			return (1);
	}
	else
	{
		printf("Invalid map, bad definition Floor and Ceilling color\n");
		*validator = 1;
		return (1);
	}
	return (0);
}

int	is_color_valid(t_prg *v, int *validator)
{
	if (v->rgb[0] > 255 || v->rgb[1] > 255 || v->rgb[2] > 255)
	{
		printf("Invalid map, bad definition Floor and Ceilling color\n");
		*validator = 1;
		return (1);
	}
	return (0);
}
