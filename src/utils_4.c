/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 20:41:28 by moninechan        #+#    #+#             */
/*   Updated: 2023/01/01 17:59:09 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	process_path_texture(t_prg *v, int *i, int j, int path[2])
{
	char	*str;

	str = ft_substr(&v->map[*i][path[1]], 0, j - path[1]);
	if (assign_path_to_texture(v, path[0], str) == 1)
	{
		if (str)
			free(str);
		return (1);
	}
	*i += 1;
	v->map_i = *i;
	skipe_empty_line(v);
	*i = v->map_i;
	if (str)
		free(str);
	return (0);
}

int	check_process_path_texture(t_prg *v, int *i, int j, int path[2])
{
	if (process_path_texture(v, i, j, path) == 1)
		return (1);
	return (0);
}

int	check_direction(t_prg *v, int *validator)
{
	int	i;
	int	j;
	int	path[2];		
	int	card_pt[4];

	init_card_pt(card_pt);
	i = v->map_i;
	path[0] = 0;
	while (v->map[i] && (card_pt[0] || card_pt[1] || card_pt[2] || card_pt[3]))
	{
		j = 0;
		loop_card_points(v, i, &j);
		if (is_valid_len_points(j, validator) == 1)
			return (1);
		if (is_valid_card_points(v, card_pt, validator, i) == 1)
			return (1);
		path[0] += 1;
		skype_spaces(v, i, &j);
		path[1] = j;
		if (is_valid_textures_paths(v, i, &j, validator) == 1)
			return (1);
		if (check_process_path_texture(v, &i, j, path) == 1)
			return (1);
	}
	return (0);
}

int	is_allowed_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == '1' || c == '0')
		return (1);
	return (0);
}

int	is_init_player_pos(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}
