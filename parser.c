#include "structs.h"
#include "srcs.h"

int open_file(char* file_name)
{
    int     file_descriptor;

    file_descriptor = open(file_name, O_RDONLY);
    file_open_error_checker(file_descriptor);

    return file_descriptor;
}

int get_file_size(char* file_name)
{
    int file_size = 0;
    char c;

    int file_descriptor = open_file(file_name);

    while (read(file_descriptor, &c, 1) != 0)
        file_size++;

    close(file_descriptor);
    return file_size;
}

void set_map_struct(t_map *map, char **lines)
{
    int length;
    char *first_line = lines[0];

    length = str_length(first_line);

    map->full = first_line[length - 1];
    map->obstacle = first_line[length - 2];
    map->empty = first_line[length - 3];
    
    lines++;
    map->matrix = lines;
    
    map->rows = ft_atoi(first_line);
    map->cols = str_length(map->matrix[0]);
}

void    read_map_file(t_map *map, char *file_name)
{
    int file_size = get_file_size(file_name);
    int file_descriptor = open_file(file_name);
    char * buffer = (char *)malloc(sizeof(char) * file_size);

    read(file_descriptor, buffer, file_size);
    char **lines = ft_split(buffer, "\n");
    
    set_map_struct(map, lines);
    close(file_descriptor);
}

