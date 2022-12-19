/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:59:54 by moninechan        #+#    #+#             */
/*   Updated: 2022/12/17 21:16:57 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void    load_texture_paths(t_prg *v)
{
    v->tex.path_no = "../textures/brick_brown_64x64.xpm";
    v->tex.path_so = "../textures/brick_green_64x64.xpm";
    v->tex.path_ea = "../textures/stones_64x64.xpm";
    v->tex.path_we = "../textures/wooden_box_64x64.xpm";
}

// add error management in case of failure
void    create_texture_images(t_prg *v)
{
    v->tex.no.img = mlx_xpm_file_to_image(v->mlx, v->tex.path_no, &v->tex.no.width, &v->tex.no.height);
    v->tex.so.img = mlx_xpm_file_to_image(v->mlx, v->tex.path_so, &v->tex.so.width, &v->tex.so.height);
    v->tex.ea.img = mlx_xpm_file_to_image(v->mlx, v->tex.path_ea, &v->tex.ea.width, &v->tex.ea.height);
    v->tex.we.img = mlx_xpm_file_to_image(v->mlx, v->tex.path_we, &v->tex.we.width, &v->tex.we.height);
}

// add error management in case of failure
void    get_texture_params(t_prg *v)
{
    v->tex.no.addr = mlx_get_data_addr(v->tex.no.img, &v->tex.no.bits_per_pixel, &v->tex.no.line_length , &v->tex.no.endian);
    v->tex.so.addr = mlx_get_data_addr(v->tex.so.img, &v->tex.so.bits_per_pixel, &v->tex.so.line_length , &v->tex.so.endian);
    v->tex.ea.addr = mlx_get_data_addr(v->tex.ea.img, &v->tex.ea.bits_per_pixel, &v->tex.ea.line_length , &v->tex.ea.endian);
    v->tex.we.addr = mlx_get_data_addr(v->tex.we.img, &v->tex.we.bits_per_pixel, &v->tex.we.line_length , &v->tex.we.endian);
}

void    init_textures(t_prg *v)
{
    load_texture_paths(v);
    create_texture_images(v);
    get_texture_params(v);
}

void    find_texture_coord(t_prg *v, t_img *wall_tex)
{
    if (v->graphics.side == 0)
        v->graphics.wallX = v->player.posY + v->graphics.perpWallDist * v->graphics.rayDirY;
    else
        v->graphics.wallX = v->player.posX + v->graphics.perpWallDist * v->graphics.rayDirX;
    v->graphics.wallX -= floor(v->graphics.wallX);
    v->graphics.tex_x = (int)(v->graphics.wallX * (double)wall_tex->width);
    if ((v->graphics.side == 0 && v->graphics.rayDirX > 0) || \
        (v->graphics.side == 1 && v->graphics.rayDirY < 0))
        v->graphics.tex_x = wall_tex->width - v->graphics.tex_x;
    v->graphics.tex_y_step = wall_tex->height / (double)v->graphics.lineHeight;
    v->graphics.tex_y = 0;
    if (v->graphics.lineHeight > SCR_HEIGHT)
        v->graphics.tex_y = (v->graphics.lineHeight - SCR_HEIGHT) * v->graphics.tex_y_step / 2;

}

t_img   *get_wall_tex(t_textures *tex)
{
    if (tex->toApply == 'W')
		return (&(tex->we));
	else if (tex->toApply == 'N')
		return (&(tex->no));
	else if (tex->toApply == 'E')
		return (&(tex->ea));
	else
		return (&(tex->so));
}

void    apply_wall_tex(t_prg *v, t_graphics *graphics)
{
    if (graphics->stepY == -1 && graphics->stepX == -1 && graphics->side == 1)
		v->tex.toApply = 'N';
	else if (graphics->stepY == 1 && graphics->stepX == -1 && graphics->side == 0)
		v->tex.toApply = 'W';
	else if (graphics->stepY == -1 && graphics->stepX == -1 && graphics->side == 0)
		v->tex.toApply = 'W';
	else if (graphics->stepY == -1 && graphics->stepX == 1 && graphics->side == 0)
		v->tex.toApply = 'E';
	else if (graphics->stepY == 1 && graphics->stepX == 1 && graphics->side == 1)
		v->tex.toApply = 'S';
	else if (graphics->stepY == 1 && graphics->stepX == -1 && graphics->side == 1)
		v->tex.toApply = 'S';
	else if (graphics->stepY == -1 && graphics->stepX == 1 && graphics->side == 1)
		v->tex.toApply = 'N';
	else if (graphics->stepY == 1 && graphics->stepX == 1 && graphics->side == 0)
		v->tex.toApply = 'E';
}

void    add_texture(t_prg *v, t_img *wall_tex, int x)
{
    t_graphics  *tex_graphics;
    int         y;
    int         color;
    char        *tex_addr;

    tex_graphics = &v->graphics;
    find_texture_coord(v, wall_tex);
    y = tex_graphics->drawStart;
    while (y < tex_graphics->drawEnd)
    {
        tex_addr = NULL;
        tex_addr = wall_tex->addr + ((int)(tex_graphics->tex_y) % wall_tex->height * wall_tex->line_length + \
            tex_graphics->tex_x % wall_tex->width *(wall_tex->bits_per_pixel / 8));

        color = *(int *)tex_addr;
        my_mlx_pixel_put(&(v->img), x, y, color);
        tex_graphics->tex_y += tex_graphics->tex_pos; 
        y++;
    }
}