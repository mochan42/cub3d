/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.C                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:31:50 by moninechan        #+#    #+#             */
/*   Updated: 2022/12/28 23:17:28 by moninechan       ###   ########.fr       */
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

void    parsing(t_prg *v, int *validator)
{
    int    p_len;
    int    i;
    int    j;

    p_len = ft_strlen(v->map_path);
    if (ft_strncmp(&v->map_path[p_len - 4], ".cub", 4) != 0)    
    {
        printf("Invalid map : The file extension should be .cub \n");
        *validator = 1;
    }
    skipe_empty_line(v);
    check_direction(v, validator);
    skipe_empty_line(v);
    i = 0;
    j = 0;
    // while (v->map[v->map_i][i] != '\0' || v->map[v->row - 1][j] != '\0')
    // {
    //     if ((v->map[v->map_i][i] != '1' && v->map[v->map_i][i] != '\n')
    //         && (v->map[v->map_i][i] != 32 && v->map[v->map_i][i] != '\0'))
    //         *validator = 1;
    //     if ((v->map[v->row - 1][j] != '1')
    //         && (v->map[v->row - 1][j] != 32 && v->map[v->row -1][j] != '\0'))
    //         *validator = 1;
    //     if (*validator == 1)
    //     {
    //         printf("The map should be surrounded by wall : 1\n");
    //         break ;
    //     }
    //     i++;
    //     j++;
    // }
    printf("First line map :%s", v->map[v->map_i]);
    printf("Last line map :%s\n", v->map[v->row - 1]);
}
