/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:45:33 by moninechan        #+#    #+#             */
/*   Updated: 2022/12/04 18:15:46 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	count_nb_row(char *map_path)
{
	int		nb_row;
	int		fd;
	char	*line;

	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	nb_row = 0;
	while (line != NULL)
	{
		if (line)
			free(line);
		line = get_next_line(fd);
		nb_row++;
	}
	if (line)
		free(line);
	close(fd);
	return (nb_row);
}

char	**store_map(t_prg *v)
{
	int		fd;
	int		row_index;

	row_index = 0;
	v->map = malloc(sizeof(char *) * (v->row));
	if (!v->map)
		return (0);
	fd = open(v->map_path, O_RDONLY);
	while (row_index < v->row)
	{
        v->map[row_index] = get_next_line(fd);
        printf("ROW INDEX %d :%s\n", row_index, v->map[row_index]);
		row_index++;
	}
	close(fd);
	return (v->map);
}

void    print_map(t_prg *v)
{
    int i;
    int j;

    i = 0;
    if (!v->map)
        return ;
    while (i < v->row)
    {
        j = 0;
        while (v->map[i][j] != '\0')
        {
            printf("%c", v->map[i][j]);
            j++;
        }
        i++;
    }
    printf("\n");
}
