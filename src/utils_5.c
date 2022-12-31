/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 20:49:41 by moninechan        #+#    #+#             */
/*   Updated: 2022/12/31 20:54:41 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	is_allowed_space_y(t_prg *v, int i, int j, int sens)
{
	while (v->map[i][j])
	{
		if (sens == 1)
			j++;
		else
			j--;
		if (is_allowed_char(v->map[i][j]))
			return (1);
	}
	return (0);
}

int	is_allowed_space_x(t_prg *v, int i, int j, int sens)
{
	while (v->map[i][j] && v->map[i][j] == 32)
	{
		if (sens == 1)
			i++;
		else
			i--;
		if (is_allowed_char(v->map[i][j]))
			return (1);
	}
	return (0);
}

void	reading_color_num_value(t_prg *v, int i, int *j, int nb[2])
{
	nb[0] = *j;
	while (v->map[i][*j] && (v->map[i][*j] >= '0' && v->map[i][*j] <= '9'))
		*j += 1;
	nb[1] = *j;
}

int	is_comma_respected(t_prg *v, int i, int j, int *validator)
{
	if (!v->map[i][j] || v->map[i][j] != ',')
	{
		printf("Invalid map, bad definition Floor and Ceilling color\n");
		*validator = 1;
		return (1);
	}
	return (0);
}

void	get_color_value(int *red, char *str_color)
{
	*red = ft_atoi(str_color);
}
