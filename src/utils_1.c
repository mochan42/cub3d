/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:31:50 by moninechan        #+#    #+#             */
/*   Updated: 2022/12/31 18:29:29 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void    free_cub3d(t_prg *v)
{
    (void)v;
}

void    skipe_empty_line(t_prg *v)
{
    while (v->map[v->map_i] && v->map[v->map_i][0] == '\n')
        v->map_i++;
}

void    init_card_pt(int card_pt[4])
{
    card_pt[0] = -1;
    card_pt[1] = -1;
    card_pt[2] = -1;
    card_pt[3] = -1;
}

void	loop_card_points(t_prg *v, int i, int *j)
{
	 while (v->map[i][*j] && (v->map[i][*j] == 'N' || v->map[i][*j] == 'S'
                || v->map[i][*j] == 'O' || v->map[i][*j] == 'W'
                || v->map[i][*j] == 'E' || v->map[i][*j] == 'A'))
            *j += 1;
}

int	is_valid_len_points(int j, int *validator)
{
	if (j != 2)
	{
		printf("Invalid map : Wrong Identifier \n");
		*validator = 1;
		return (1);
	}
	return (0);
}

void	skype_spaces(t_prg *v, int i, int *j)
{
	while (v->map[i][*j] && v->map[i][*j] == 32)
		*j += 1;
}

int	is_valid_card_points(t_prg *v, int card_pt[4], int *validator, int i)
{
	if (ft_strncmp(ft_substr(v->map[i], 0, 2), "NO", 2) == 0 && card_pt[0])
		card_pt[0] = 0;
	else if (ft_strncmp(ft_substr(v->map[i], 0, 2), "SO", 2) == 0 && !card_pt[0])
		card_pt[1] = 0;
	else if (ft_strncmp(ft_substr(v->map[i], 0, 2), "WE", 2) == 0 && !card_pt[1])
		card_pt[2] = 0;
	else if (ft_strncmp(ft_substr(v->map[i], 0, 2), "EA", 2) == 0 && !card_pt[2])
		card_pt[3] = 0;
	else
	{
		printf("Invalid map : Wrong Identifier \n");
		*validator = 1;
		return (1);
	}
	return (0);
}

int	is_valid_textures_paths(t_prg *v, int i, int *j, int *validator)
{
	while (v->map[i][*j] && (v->map[i][*j] != ' ' && v->map[i][*j] != '\n'))
		*j += 1;
	if (v->map[i][*j] == ' ')
	{
		printf("Invalid map : Wrong texture path\n");
		*validator = 1;
		return (1);
	}
	else if (ft_strncmp(&v->map[i][*j - 4], ".xpm\n", 5) != 0)
	{
		printf("Invalid map : Invalid texture extension\n");
		*validator = 1;
		return (1);
	}
	return (0);
}

int	assign_path_to_texture(t_prg *v, int texture, char *path)
{
	if (access(path, F_OK) != 0)
	{
		printf("Invalid map : path texture not found !\n");
		return (1);
	}
	if (texture == 1)
		v->tex.path_no = ft_strdup(path);
	if (texture == 2)
		v->tex.path_so = ft_strdup(path);
	if (texture == 3)
		v->tex.path_we = ft_strdup(path);
	if (texture == 4)
		v->tex.path_ea = ft_strdup(path);
	return (0);
}

int	process_path_texture(t_prg *v, int *i, int j, int path[2])
{
	if (assign_path_to_texture(v, path[0], ft_substr(&v->map[*i][path[1]], 0, j - path[1])) == 1)
		return (1);
    *i += 1;
	v->map_i = *i;
	skipe_empty_line(v);
	*i = v->map_i;
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
		if (process_path_texture(v, &i, j, path) == 1)
		{
			*validator = 1;
			return (1);
		}
    }
	return (0);
}

int	isAllowedChar(char c) 
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == '1' || c == '0')
		return (1);
	return (0);
}

int	isInitPlayerPos(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

int	isAllowedSpaceY(t_prg *v, int i, int j, int sens)
{
	while (v->map[i][j]) 
	{
		if (sens == 1)
			j++;
		else
			j--;
		if (isAllowedChar(v->map[i][j]))
			return 1;
	}
	return 0;
}

int	isAllowedSpaceX(t_prg *v, int i, int j, int sens)
{
	while (v->map[i][j] && v->map[i][j] == 32) 
	{
		if (sens == 1)
		{
			i++;
			printf("CONTINUE DOWN\n");
			
		}
		else
		{
			i--;
			printf("CONTINUE TOP\n");
		}
		printf("CHAR MEET:%c*\n", v->map[i][j]);
		if (isAllowedChar(v->map[i][j]))
			return 1;
	}
	return 0;
}
void	reading_color_num_value(t_prg *v, int i, int *j, int nb[2])
{
	nb[0] = *j;
	while(v->map[i][*j] && (v->map[i][*j] >= '0' && v->map[i][*j] <= '9'))
		*j +=1;
	nb[1] = *j;
}

int	is_comma_respected(t_prg *v, int i, int j, int *validator)
{
	if (!v->map[i][j] || v->map[i][j] != ',')
	{
		printf("Invalid map, bad definition Floor and Ceilling color\n");
		*validator = 1;
		return (1);
	}
	return (0);
}
void	get_color_value(int *red, char *str_color)
{
	*red = ft_atoi(str_color);
}

int	is_color_def_valid(t_prg *v, int nb[2], int j, int *validator)
{
	while(v->map[v->map_i][j])
	{
		if ((nb[0] == nb[1]) || (v->map[v->map_i][j] != '\n' && v->map[v->map_i][j] != ' '))
		{
			printf("Invalid map, bad definition Floor and Ceilling color\n");
			*validator = 1;
			return (1);
		}
		j++;
	}
	return (0);
}
int	is_comma2_respected(t_prg *v, int *j, int *validator)
{
	if (v->nb_rgb[0] == v->nb_rgb[1] || (!v->map[v->map_i][*j] || v->map[v->map_i][*j] != ','))
	{
		printf("Invalid map, bad definition Floor and Ceilling color\n");
		*validator = 1;
		return (1);
	}
	return (0);
}

int	floor_ceilling_color(t_prg *v, int *j, int *validator)
{
	*j +=1;
	skype_spaces(v, v->map_i, j);
	reading_color_num_value(v, v->map_i, j, v->nb_rgb);
	skype_spaces(v, v->map_i, j);
	if (is_comma_respected(v, v->map_i, *j, validator) == 1)
		return (1);
	*j +=1;
	get_color_value(&v->rgb[0], ft_substr(&v->map[v->map_i][v->nb_rgb[0]], 0, v->nb_rgb[1] - v->nb_rgb[0]));
	skype_spaces(v, v->map_i, j);
	reading_color_num_value(v, v->map_i, j, v->nb_rgb);
	skype_spaces(v, v->map_i, j);
	if (is_comma2_respected(v, j, validator) == 1)
		return (1);
	*j += 1;
	get_color_value(&v->rgb[1], ft_substr(&v->map[v->map_i][v->nb_rgb[0]], 0, v->nb_rgb[1] - v->nb_rgb[0]));
	skype_spaces(v, v->map_i, j);
	reading_color_num_value(v, v->map_i, j, v->nb_rgb);
	if (is_color_def_valid(v, v->nb_rgb, *j, validator) == 1)
		return (1);
	get_color_value(&v->rgb[2], ft_substr(&v->map[v->map_i][v->nb_rgb[0]], 0, v->nb_rgb[1] - v->nb_rgb[0]));
	return (0);
}

int	find_floor_ceilling(t_prg *v, int *j, int *validator, int checker)
{
	if (v->map[v->map_i][*j] && (v->map[v->map_i][*j] == 'F' && !checker))
	{
		if (floor_ceilling_color(v, j, validator) == 1)
			return (1);
	}
	else if (v->map[v->map_i][*j] && v->map[v->map_i][*j] == 'C' && checker == 1)
	{
		if (floor_ceilling_color(v, j, validator) == 1)
			return (1);
	}
	else 
	{
		printf("Invalid map, bad definition Floor and Ceilling color\n");
		*validator = 1;
		return (1);
	}
	return (0);
}

int	is_color_valid(t_prg *v, int *validator)
{
	if (v->rgb[0] > 255 || v->rgb[1] > 255 || v->rgb[2] > 255)
	{
		printf("Invalid map, bad definition Floor and Ceilling color\n");
		*validator = 1;
		return (1);
	}
	return (0);
}

int	check_ceil_and_floor_color(t_prg *v, int *validator) 
{
	int checker;
	int j;
	
	checker = 0;
	while (v->map_i < v->row && checker <= 1)
	{
		j = 0;
		while (v->map[v->map_i][j] && v->map[v->map_i][j] == 32)
			j++;
		skype_spaces(v, v->map_i, &j);
		if (find_floor_ceilling(v, &j, validator, checker) == 1)
			return (1);
		checker++;
		if (is_color_valid(v, validator) == 1)
			return (1);
		if (checker == 1)
			v->tex.floor_color = create_trgb(0, v->rgb[0], v->rgb[1], v->rgb[2]);
		else if (checker == 2)
			v->tex.ceiling_color = create_trgb(0, v->rgb[0], v->rgb[1], v->rgb[2]);
		v->map_i++;
		skipe_empty_line(v);
	}
	return (0);
}

int	is_valid_map_extension(t_prg *v, int *p_len, int *validator, int *isPos)
{
	*p_len = ft_strlen(v->map_path);
	*isPos = 0;
    if (ft_strncmp(&v->map_path[*p_len - 4], ".cub", 4) != 0)    
    {
        printf("Invalid map : The file extension should be .cub \n");
        *validator = 1;
		return 1;
    }	
	return 0;
}

int	isEmpty_line(t_prg *v, int i, int *validator)
{
	if (v->map[i][0] == '\0')
	{
		printf("Invalid map\n");
		*validator = 1;
		return (1);
	}
	return (0);
}

int	isValid_char(t_prg *v, int i, int j, int *validator)
{
	if (!isAllowedChar(v->map[i][j]) && v->map[i][j] != 32 && v->map[i][j] != '\n')
	{
		printf("Invalid character in map\n");
		*validator = 1;
		return(1);
	}
	return (0);
}

void	valid_init_position(int isPos, int *validator)
{
	if (!isPos)
	{
		printf("The map should have a player (N, S, W, E)\n");
		*validator = 1;
	}
	else if (isPos > 1)
	{
		*validator = 1;
		printf("The map should have only one player position\n");
	}	
}

int	is_zero_close_to_top(t_prg *v, int i, int j, int *validator)
{
	if (i == v->map_i || i == v->row - 1 || j == 0)
	{
		printf("The map should be surronded by the wall\n");
		*validator = 1;
		return (1);
	}
	if (!isAllowedChar(v->map[i - 1][j]))
	{
		if (isAllowedSpaceX(v, i - 1, j, 0))
			;
		else
		{
			printf("The map should be surronded by the wall\n");
			*validator = 1;
			return (1);
		}
	}
	return (0);
}

int	is_zero_close_down(t_prg *v, int i, int j, int *validator)
{
	if (!isAllowedChar(v->map[i + 1][j]))
	{
		if (isAllowedSpaceX(v, i + 1, j, 1))
			;
		else
		{
			printf("The map should be surronded by the wall\n");
			*validator = 1;
			return (1);
		}
	}
	return (0);
}

int	is_zero_close_right(t_prg *v, int i, int j, int *validator)
{
	if (v->map[i][j + 1] && !isAllowedChar(v->map[i][j + 1]))
	{
		if (isAllowedSpaceY(v, i, j + 1, 1))
			;
		else
		{
			printf("The map should be surronded by the wall\n");
			*validator = 1;
			return (1);
		}
	}
	return (0);
}

int	is_zero_close_left(t_prg *v, int i, int j, int *validator)
{
	if (!isAllowedChar(v->map[i][j - 1]))
	{
		if (isAllowedSpaceY(v, i, j - 1, 0))
			;
		else
		{
			printf("The map should be surronded by the wall\n");
			*validator = 1;
			return(1);
		}
	} 
	return (0);
}

int is_zero_close(t_prg *v, int i, int j, int *validator)
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
void	check_map_content(t_prg *v, int *validator, int *isPos)
{
	int	i;
	int	j;
	
	i = v->map_i;
    j = 0;
	while (i < v->row)
	{
		j = 0;
		while (v->map[i][j]) {
			if (isEmpty_line(v, i, validator) == 1)
				return ;
			if (isValid_char(v, i, j, validator) == 1)
				return ;
			if (v->map[i][j] == '0' || isInitPlayerPos(v->map[i][j]))
			{
				if (isInitPlayerPos(v->map[i][j]))
					*isPos +=1;
				if(is_zero_close(v, i, j, validator) == 1)
					return;
			}
			j++;
		}
		i++;
	}
}

void	parsing(t_prg *v, int *validator)
{
    int	p_len;
	int	isPos;

    if (is_valid_map_extension(v, &p_len, validator, &isPos) == 1)
		return ;
    skipe_empty_line(v);
	if (check_direction(v, validator) == 1)
		return;
    skipe_empty_line(v);
	if (check_ceil_and_floor_color(v, validator) == 1)
		return ;
	skipe_empty_line(v);
    check_map_content(v, validator, &isPos);
	valid_init_position(isPos, validator);
}
