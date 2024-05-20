#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
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

// char	**read_user_input()
// {
//     // todo
// }

// char	**read_file(char *filename)
// {
//     // todo
// }


void set_map_struct(t_map *map, char **lines)
{
    int length;
    char *first_line = lines[0];

    length = str_length(first_line);

    map->num_lines = ft_atoi(first_line);
    map->full = first_line[length - 1];
    map->obstacle = first_line[length - 2];
    map->empty = first_line[length - 3];
    
    lines++;
    map->matrix = lines;
   //printf("%s",lines[0]);
}

void    set_map(t_map *map, char *file_name, int file_size)
{
    char * buffer = (char *)malloc(sizeof(char) * file_size);
    int file_descriptor = open_file(file_name);

    read(file_descriptor, buffer, file_size);
    char **lines = ft_split(buffer, "\n");
    
    set_map_struct(map, lines);
    close(file_descriptor);
}

int		main(int argc, char *argv[])
{
	t_map		map;
	char		*filename;

	arg_skiper(&argc, &argv);

    filename = "example_file";

    int file_size = get_file_size(filename);
    set_map(&map, filename, file_size);


   print_map(map);
     //print(map);
//    solve_map();

    // char    *first_line = get_first_line(file_descriptor);
    // set_map_settings(&map, first_line);
    // get_map_matrix(&map, file_descriptor);

    // if (argc == 0)
    // {
    //     // take input from user;
    // }
    // else 
    // {
    //     // while loop through files;
    // }


	// free memory map please please dont foooorgett!!
	return (0);
}