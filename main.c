/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:45:45 by moninechan        #+#    #+#             */
/*   Updated: 2022/11/18 17:08:06 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

int	ft_close_window(t_prg *v)
{
	mlx_destroy_window(v->mlx, v->mlx_win);
	printf("exit cub3D\n");
	exit (0);
}

int main(void)
{
    t_prg v;
    printf("cub3d\n");
    printf("%f\n", pow(2, 2));
    v.mlx = mlx_init();
    v.mlx_win = mlx_new_window(v.mlx, 500, 500, "CUBE 3 D");
    mlx_hook(v.mlx_win, 17, 0, ft_close_window, &v);
    mlx_loop(v.mlx);
}