/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:31:50 by moninechan        #+#    #+#             */
/*   Updated: 2022/12/29 23:17:38 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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

void    check_direction(t_prg *v, int *validator)
{
    int    i;
    int    j;

    int    card_pt[4];
    init_card_pt(card_pt);
    i = v->map_i;
    while (v->map[i] && (card_pt[0] || card_pt[1] || card_pt[2] || card_pt[3]))
    {
        j = 0;
        while (v->map[i][j] && (v->map[i][j] == 'N' || v->map[i][j] == 'S'
                || v->map[i][j] == 'O' || v->map[i][j] == 'W'
                || v->map[i][j] == 'E' || v->map[i][j] == 'A'))
            j++;
        if (j != 2)
        {
            printf("Invalid map : Wrong Identifier \n");
            *validator = 1;
        }
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
            return ;
        }
        while (v->map[i][j] && v->map[i][j] == ' ')
            j++;
        if (j <= 2)
        {
            printf("Invalid map : Wrong Identifier \n");
            *validator = 1;
            return ;
        }
        while (v->map[i][j] && (v->map[i][j] != ' ' && v->map[i][j] != '\n'))
            j++;
        if (v->map[i][j] == ' ')
        {
            printf("Invalid map : Wrong texture path\n");
            *validator = 1;
            return ;
        }
        else if (ft_strncmp(&v->map[i][j - 4], ".xpm\n", 5) != 0)
        {
            printf("Invalid map : Invalid texture extension\n");
            *validator = 1;
            return ;
        }
        i++;
        v->map_i = i;
        skipe_empty_line(v);
        i = v->map_i;
    }
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

void    parsing(t_prg *v, int *validator)
{
    int    p_len;
    int    i;
    int    j;
	int		isPos = 0;
    p_len = ft_strlen(v->map_path);
    if (ft_strncmp(&v->map_path[p_len - 4], ".cub", 4) != 0)    
    {
        printf("Invalid map : The file extension should be .cub \n");
        *validator = 1;
		return ;
    }
	printf("MAP CURSOR : %d\n", v->map_i);
    skipe_empty_line(v);
	printf("MAP CURSOR : %d\n", v->map_i);
    check_direction(v, validator);
	printf("MAP CURSOR AFTER CHECK DIRECTION: %d\n", v->map_i);
    skipe_empty_line(v);
	printf("MAP CURSOR BEFORE MAP: %d\n", v->map_i);
	
    i = v->map_i;
    j = 0;
	while (i < v->row)
	{
		j = 0;
		while (v->map[i][j]) {
			if (v->map[i][0] == '\0')
			{
				printf("Invalid map\n");
				*validator = 1;
				return ;
			}
			if (!isAllowedChar(v->map[i][j]) && v->map[i][j] != 32 && v->map[i][j] != '\n')
			{
				printf("Invalid character in map\n");
				*validator = 1;
				return ;
			}
			if (v->map[i][j] == '0' || isInitPlayerPos(v->map[i][j]))
			{
				if (isInitPlayerPos(v->map[i][j]))
					isPos++;
				if (i == v->map_i || i == v->row - 1 || j == 0)
				{
					printf("The map should be surronded by the wall\n");
					*validator = 1;
					return ;
				}
				if (!isAllowedChar(v->map[i - 1][j]))
				{
					if (isAllowedSpaceX(v, i - 1, j, 0))
						;
					else
					{
						printf("The map should be surronded by the wall\n");
						*validator = 1;
						return ;
					}
				}
				if (!isAllowedChar(v->map[i + 1][j]))
				{
					if (isAllowedSpaceX(v, i + 1, j, 1))
						;
					else
					{
						printf("The map should be surronded by the wall\n");
						*validator = 1;
						return ;
					}
				}
				if (v->map[i][j + 1] && !isAllowedChar(v->map[i][j + 1]))
				{
					if (isAllowedSpaceY(v, i, j + 1, 1))
						;
					else
					{
						printf("The map should be surronded by the wall\n");
						*validator = 1;
						return ;
					}
				}
				if (!isAllowedChar(v->map[i][j - 1]))
				{
					if (isAllowedSpaceY(v, i, j - 1, 0))
						;
					else
					{
						printf("The map should be surronded by the wall\n");
						*validator = 1;
						return ;
					}
				}
			}
			j++;
		}
		i++;
	}
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
