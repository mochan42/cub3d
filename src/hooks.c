/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:32:14 by moninechan        #+#    #+#             */
/*   Updated: 2022/12/11 11:15:48 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	key_hook(int keycode, t_prg *v)
{
    
    if (keycode == KEY_UP)
        move_forward(v);
	if (keycode == KEY_LEFT)
	{
        printf("move left\n");
    }
	if (keycode == KEY_DOWN)
	{
        printf("move backwards\n");
    }
	if (keycode == KEY_RIGHT)
	{
        printf("move right\n");
    }
    if (keycode == KEY_ROT_LEFT)
	{
        printf("rotate left\n");
    }
    if (keycode == KEY_ROT_RIGHT)
	{
        printf("rotate right\n");
    }
	if (keycode == KEY_ESC)
	{
        ft_close_window(v);
    }
    raycasting(v);
	return (0);
}
