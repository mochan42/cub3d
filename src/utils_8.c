/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_8.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 21:09:15 by moninechan        #+#    #+#             */
/*   Updated: 2022/12/31 21:11:54 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	is_zero_close_to_top(t_prg *v, int i, int j, int *validator)
{
	if (i == v->map_i || i == v->row - 1 || j == 0)
	{
		printf("The map should be surrounded by the wall\n");
		*validator = 1;
		return (1);
	}
	if (!is_allowed_char(v->map[i - 1][j]))
	{
		if (is_allowed_space_x(v, i - 1, j, 0))
			;
		else
		{
			printf("The map should be surrounded by the wall\n");
			*validator = 1;
			return (1);
		}
	}
	return (0);
}

int	is_zero_close_down(t_prg *v, int i, int j, int *validator)
{
	if (!is_allowed_char(v->map[i + 1][j]))
	{
		if (is_allowed_space_x(v, i + 1, j, 1))
			;
		else
		{
			printf("The map should be surrounded by the wall\n");
			*validator = 1;
			return (1);
		}
	}
	return (0);
}

int	is_zero_close_right(t_prg *v, int i, int j, int *validator)
{
	if (v->map[i][j + 1] && !is_allowed_char(v->map[i][j + 1]))
	{
		if (is_allowed_space_y(v, i, j + 1, 1))
			;
		else
		{
			printf("The map should be surrounded by the wall\n");
			*validator = 1;
			return (1);
		}
	}
	return (0);
}

int	is_zero_close_left(t_prg *v, int i, int j, int *validator)
{
	if (!is_allowed_char(v->map[i][j - 1]))
	{
		if (is_allowed_space_y(v, i, j - 1, 0))
			;
		else
		{
			printf("The map should be surrounded by the wall\n");
			*validator = 1;
			return (1);
		}
	}
	return (0);
}

int	is_zero_close(t_prg *v, int i, int j, int *validator)
{
	if (is_zero_close_to_top(v, i, j, validator) == 1)
		return (1);
	if (is_zero_close_down(v, i, j, validator) == 1)
		return (1);
	if (is_zero_close_right(v, i, j, validator) == 1)
		return (1);
	if (is_zero_close_left(v, i, j, validator) == 1)
		return (1);
	return (0);
}
