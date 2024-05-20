#ifndef SRCS_H
#define SRCS_H
#include "structs.h"

void    print_string(char *str);
void	arg_skiper(int *argc, char ***argv);
void    allocation_error_checker(void * pointer);
void    file_open_error_checker(int file_descriptor);
int     ft_atoi(char *str);
int     str_length(char *str);
char	**ft_split(char *str, char *charset);

void    print_map(t_map map);
int		get_min(int a, int b, int c);
t_map   solve_map(t_map map);

#endif