/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:45:45 by moninechan        #+#    #+#             */
/*   Updated: 2022/12/29 23:40:48 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/cub3d.h"

void    init_prg(t_prg *v)
{
    v->row = count_nb_row(v->map_path);
    printf("nb of rows = %d\n", v->row);
    v->map = store_map(v);
    v->map_i = 0;
}

void    update_prog(t_prg *v) 
{
    print_map(v);
    find_player_pos(v);
    printf("posX = %f\n", v->player.posX);
    printf("posY = %f\n", v->player.posY);
    init_camera_pos(v);
    init_player_dir(v);
    init_camera_dir(v);
    init_graphics(v);
}

int	ft_close_window(t_prg *v)
{
    // free_cub3d(v);
    mlx_destroy_window(v->mlx, v->mlx_win);
	printf("exit cub3D\n");
	exit (0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(int ac, char **av)
{
    t_prg   *v;
    int     validator;
    char    **tmp;
    int     i;
	int		i2;

    if (ac != 2)
        exit(0);
    v = malloc(sizeof(t_prg) * 1);
    v->map_path = ft_strdup(av[1]);
    init_prg(v);
    parsing(v, &validator);
    if (validator == 1)
        return (0);
    //skipe_empty_line(v);
    //v->map_i += 2;
    skipe_empty_line(v);
    i = 0;
    tmp = malloc(sizeof(char *) * (v->row - v->map_i + 1));
	while (v->map_i < v->row)
	{
        tmp[i] = ft_strdup(v->map[v->map_i]);
		i2 = 0;
		while (tmp[i][i2])
		{
			if (tmp[i][i2] == 32)
				tmp[i][i2] = '1';
			i2++;
		}
        printf("%s", tmp[i]);
        i++;
        v->map_i++;
	}
    tmp[i] = NULL;
    //free previous map
    printf("V-row : %d", i);
    v->map = tmp;
    v->row = i;
    update_prog(v);
    i = 0;
    printf("\n\n");
    while(i < v->row)
    {
        printf("%s", v->map[i]);
        i++;
    }
    printf("path :%s\n", v->map_path);
    v->mlx = mlx_init();
    v->mlx_win = mlx_new_window(v->mlx, SCR_WIDTH, SCR_HEIGHT, "cub3D");
    v->img.img = mlx_new_image(v->mlx, SCR_WIDTH, SCR_HEIGHT);
    v->img.addr = mlx_get_data_addr(v->img.img, &v->img.bits_per_pixel, &v->img.line_length,
								&v->img.endian);
    raycasting(v);
    mlx_hook(v->mlx_win, 2, 1L << 0, key_hook, v);
    mlx_hook(v->mlx_win, 17, 0, ft_close_window, v);
    mlx_loop(v->mlx);
    return (0);
}
