/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:32:14 by moninechan        #+#    #+#             */
/*   Updated: 2022/12/31 22:52:44 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	key_hook(int keycode, t_prg *v)
{
	if (keycode == KEY_UP)
		move_forward(v);
	if (keycode == KEY_LEFT)
		move_left(v);
	if (keycode == KEY_DOWN)
		move_backwards(v);
	if (keycode == KEY_RIGHT)
		move_right(v);
	if (keycode == KEY_ROT_LEFT)
		rotate_left(v);
	if (keycode == KEY_ROT_RIGHT)
		rotate_right(v);
	if (keycode == KEY_ESC)
		ft_close_window(v);
	raycasting(v);
	return (0);
}
