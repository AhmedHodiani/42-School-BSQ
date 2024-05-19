#ifndef SRCS_H
#define SRCS_H

void    print_string(char *str);
void	arg_skiper(int *argc, char ***argv);
void    allocation_error_checker(void * pointer);
void    file_open_error_checker(int file_descriptor);
int     ft_atoi(char *str);
int     str_length(char *str);

#endif