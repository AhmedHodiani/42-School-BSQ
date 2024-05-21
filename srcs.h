#ifndef SRCS_H
#define SRCS_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "structs.h"

void    allocation_error_checker(void * pointer);
void    file_open_error_checker(int file_descriptor);
int     ft_atoi(char *str);
int     str_length(char *str);
char	**ft_split(char *str, char *charset);

void    print_map(t_map map);
int		get_min(int a, int b, int c);
t_point solve_map(t_map map);
void    fill_solution(t_map map, t_point max);

// parser
int     open_file(char* file_name);
int     get_file_size(char* file_name);
void    set_map_struct(t_map *map, char **lines);
void    read_map_file(t_map *map, char *file_name);


#endif