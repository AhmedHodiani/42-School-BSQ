/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 21:40:29 by ataher            #+#    #+#             */
/*   Updated: 2024/05/21 23:33:24 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs.h"
#include "structs.h"

#define BUFFER_SIZE 250

int	get_file_size(char *file_name)
{
	int		file_size;
	char	c;
	int		file_descriptor;

	file_size = 0;
	file_descriptor = open_file(file_name);
	while (read(file_descriptor, &c, 1) != 0)
		file_size++;
	close(file_descriptor);
	return (file_size);
}

void	set_map_struct(t_map *map, char **lines)
{
	int		length;
	char	*first_line;

	first_line = lines[0];
	length = str_length(first_line);
	map->full = first_line[length - 1];
	map->obstacle = first_line[length - 2];
	map->empty = first_line[length - 3];
	lines++;
	map->matrix = lines;
	map->rows = ft_atoi(first_line);
	map->cols = str_length(map->matrix[0]);
	free(first_line);
}

void	read_map_file(t_map *map, char *file_name)
{
	int		file_size;
	int		file_descriptor;
	char	*buffer;
	char	**lines;

	file_size = get_file_size(file_name);
	file_descriptor = open_file(file_name);
	buffer = (char *)malloc(sizeof(char) * file_size);
	read(file_descriptor, buffer, file_size);
	lines = ft_split(buffer, "\n");
	set_map_struct(map, lines);
	close(file_descriptor);
}

void	read_line(char **line, int *length)
{
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	allocation_error_checker(buffer);
	*length = read(STDIN_FILENO, buffer, BUFFER_SIZE);
	stdin_reader_checker(*length);
	buffer[*length - 1] = '\0';
	*line = buffer;
}

void	read_user_input(t_map *map)
{
	int		length;
	char	*first_line;
	int		i;

	read_line(&first_line, &length);
	map->full = first_line[length - 2];
	map->obstacle = first_line[length - 3];
	map->empty = first_line[length - 4];
	first_line[length - 3] = '$';
	map->rows = ft_atoi(first_line);
	i = -1;
	while (++i < map->rows)
		read_line(&map->matrix[i], &map->cols);
	map->cols = map->cols - 1;
	free(first_line);
}
