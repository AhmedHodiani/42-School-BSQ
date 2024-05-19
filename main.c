#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "structs.h"
#include "srcs.h"


bool is_int(char c)
{
    return (c >= '0' && c <= '9');
}

// char	**read_user_input()
// {
//     // todo
// }

// char	**read_file(char *filename)
// {
//     // todo
// }


// t_map	parse_map(char *filename)
// {
//     if (filename == NULL)
//     {
//         // read_user_input
//     }
//     else
//     {
//         // read_file
//     }
// }

char    *get_first_line(int file_descriptor)
{
    char *buffer = (char *)malloc(sizeof(char) * 24);
    char* byte = (char *)malloc(sizeof(char));
    allocation_error_checker(buffer);
    allocation_error_checker(byte);

    int read_bytes = 0;

    while (*byte != '\n' || read_bytes == 0)
    {
        read(file_descriptor, byte, 1);
        buffer[read_bytes] = *byte;
        read_bytes++;
    }
    buffer[read_bytes - 1] = '\0';
    return buffer;
}

void set_map_settings(t_map *map, char *first_line)
{
    int length;
    
    length = str_length(first_line);

    map->num_lines = ft_atoi(first_line);
    map->full = first_line[length - 1];
    map->obstacle = first_line[length - 2];
    map->empty = first_line[length - 3];
}

void get_map_matrix(t_map *map, int file_descriptor)
{
    printf("%d", map->num_lines);
}

int		main(int argc, char *argv[])
{
	t_map		map;
	char		*filename;

	arg_skiper(&argc, &argv);

    int     file_descriptor = open("example_file", O_RDONLY);
    file_open_error_checker(file_descriptor);
    
    char    *first_line = get_first_line(file_descriptor);
    set_map_settings(&map, first_line);
    get_map_matrix(&map, file_descriptor);

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