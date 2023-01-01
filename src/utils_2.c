/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 20:26:56 by moninechan        #+#    #+#             */
/*   Updated: 2023/01/01 00:26:23 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	skipe_empty_line(t_prg *v)
{
	while (v->map[v->map_i] && v->map[v->map_i][0] == '\n')
		v->map_i++;
}

void	init_card_pt(int card_pt[4])
{
	card_pt[0] = -1;
	card_pt[1] = -1;
	card_pt[2] = -1;
	card_pt[3] = -1;
}

void	loop_card_points(t_prg *v, int i, int *j)
{
	while (v->map[i][*j] && (v->map[i][*j] == 'N' || v->map[i][*j] == 'S' || \
		v->map[i][*j] == 'O' || v->map[i][*j] == 'W' || v->map[i][*j] == 'E'\
		|| v->map[i][*j] == 'A'))
		*j += 1;
}
