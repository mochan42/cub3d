/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 19:52:44 by moninechan        #+#    #+#             */
/*   Updated: 2022/12/31 19:53:25 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// add error management in case of failure
void	create_texture_images(t_prg *v)
{
	v->tex.no.img = mlx_xpm_file_to_image(v->mlx, v->tex.path_no, \
		&v->tex.no.width, &v->tex.no.height);
	v->tex.so.img = mlx_xpm_file_to_image(v->mlx, v->tex.path_so, \
		&v->tex.so.width, &v->tex.so.height);
	v->tex.ea.img = mlx_xpm_file_to_image(v->mlx, v->tex.path_ea, \
		&v->tex.ea.width, &v->tex.ea.height);
	v->tex.we.img = mlx_xpm_file_to_image(v->mlx, v->tex.path_we, \
		&v->tex.we.width, &v->tex.we.height);
}

// add error management in case of failure
void	get_texture_params(t_prg *v)
{
	v->tex.no.addr = mlx_get_data_addr(v->tex.no.img, \
		&v->tex.no.bits_per_pixel, &v->tex.no.line_length, &v->tex.no.endian);
	v->tex.so.addr = mlx_get_data_addr(v->tex.so.img, \
		&v->tex.so.bits_per_pixel, &v->tex.so.line_length, &v->tex.so.endian);
	v->tex.ea.addr = mlx_get_data_addr(v->tex.ea.img, \
		&v->tex.ea.bits_per_pixel, &v->tex.ea.line_length, &v->tex.ea.endian);
	v->tex.we.addr = mlx_get_data_addr(v->tex.we.img, \
		&v->tex.we.bits_per_pixel, &v->tex.we.line_length, &v->tex.we.endian);
}
