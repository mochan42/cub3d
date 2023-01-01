/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:59:54 by moninechan        #+#    #+#             */
/*   Updated: 2022/12/31 23:36:34 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_textures(t_prg *v)
{
	create_texture_images(v);
	get_texture_params(v);
}

void	find_texture_coord(t_prg *v, t_img *wall_tex)
{
	if (v->graphics.side == 0)
		v->graphics.wall_x = v->player.pos_y + v->graphics.perpwalldist * \
			v->graphics.raydir_y;
	else
		v->graphics.wall_x = v->player.pos_x + v->graphics.perpwalldist * \
			v->graphics.raydir_x;
	v->graphics.wall_x -= floor(v->graphics.wall_x);
	v->graphics.tex_x = (int)(v->graphics.wall_x * (double)wall_tex->width);
	if ((v->graphics.side == 0 && v->graphics.raydir_x > 0) || \
		(v->graphics.side == 1 && v->graphics.raydir_y < 0))
		v->graphics.tex_x = wall_tex->width - v->graphics.tex_x;
	v->graphics.tex_y_step = wall_tex->height / (double)v->graphics.line_height;
	v->graphics.tex_y = 0;
	if (v->graphics.line_height > SCR_HEIGHT)
		v->graphics.tex_y = (v->graphics.line_height - SCR_HEIGHT) * \
			v->graphics.tex_y_step / 2;
}

t_img	*get_wall_tex(t_textures *tex)
{
	if (tex->to_apply == 'W')
		return (&(tex->we));
	else if (tex->to_apply == 'N')
		return (&(tex->no));
	else if (tex->to_apply == 'E')
		return (&(tex->ea));
	else
		return (&(tex->so));
}

void	apply_wall_tex(t_prg *v, t_graphics *graphics)
{
	if (graphics->step_y == -1 && graphics->step_x == -1 && graphics->side == 1)
		v->tex.to_apply = 'N';
	else if (graphics->step_y == 1 && graphics->step_x == -1 && \
		graphics->side == 0)
		v->tex.to_apply = 'W';
	else if (graphics->step_y == -1 && graphics->step_x == -1 && \
		graphics->side == 0)
		v->tex.to_apply = 'W';
	else if (graphics->step_y == -1 && graphics->step_x == 1 && \
		graphics->side == 0)
		v->tex.to_apply = 'E';
	else if (graphics->step_y == 1 && graphics->step_x == 1 && \
		graphics->side == 1)
		v->tex.to_apply = 'S';
	else if (graphics->step_y == 1 && graphics->step_x == -1 && \
		graphics->side == 1)
		v->tex.to_apply = 'S';
	else if (graphics->step_y == -1 && graphics->step_x == 1 && \
		graphics->side == 1)
		v->tex.to_apply = 'N';
	else if (graphics->step_y == 1 && graphics->step_x == 1 && \
		graphics->side == 0)
		v->tex.to_apply = 'E';
}

void	add_texture(t_prg *v, t_img *wall_tex, int x)
{
	t_graphics	*tex_graphics;
	int			y;
	int			color;
	char		*tex_addr;

	tex_graphics = &v->graphics;
	find_texture_coord(v, wall_tex);
	y = tex_graphics->draw_start;
	while (y < tex_graphics->draw_end)
	{
		tex_addr = NULL;
		tex_addr = wall_tex->addr + ((int)(tex_graphics->tex_y) % \
			wall_tex->height * wall_tex->line_length + \
			tex_graphics->tex_x % wall_tex->width * \
			(wall_tex->bits_per_pixel / 8));
		color = *(int *)tex_addr;
		my_mlx_pixel_put(&(v->img), x, y, color);
		tex_graphics->tex_y += tex_graphics->tex_y_step;
		y++;
	}
}
