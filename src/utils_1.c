/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:31:50 by moninechan        #+#    #+#             */
/*   Updated: 2022/12/31 21:17:29 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	empty_or_valid_char(t_prg *v, int i, int j, int *validator)
{
	if (is_empty_line(v, i, validator) == 1)
		return (1);
	if (is_valid_char(v, i, j, validator) == 1)
		return (1);
	return (0);
}

int	check_map_content(t_prg *v, int *validator, int *is_pos)
{
	int	i;
	int	j;

	i = v->map_i;
	j = 0;
	while (i < v->row)
	{
		j = 0;
		while (v->map[i][j])
		{
			if (empty_or_valid_char(v, i, j, validator) == 1)
				return (1);
			if (v->map[i][j] == '0' || is_init_player_pos(v->map[i][j]))
			{
				if (is_init_player_pos(v->map[i][j]))
					*is_pos += 1;
				if (is_zero_close(v, i, j, validator) == 1)
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	parsing(t_prg *v, int *validator)
{
	int	p_len;
	int	is_pos;

	if (is_valid_map_extension(v, &p_len, validator, &is_pos) == 1)
		return ;
	skipe_empty_line(v);
	if (check_direction(v, validator) == 1)
	{
		*validator = 1;
		return ;
	}		
	skipe_empty_line(v);
	if (check_ceil_and_floor_color(v, validator) == 1)
		return ;
	skipe_empty_line(v);
	if (check_map_content(v, validator, &is_pos) == 1)
		return ;
	valid_init_position(is_pos, validator);
}
