/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 22:29:53 by ataher            #+#    #+#             */
/*   Updated: 2024/05/21 22:29:54 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRCS_H
# define SRCS_H
# include "structs.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	read_user_input(t_map *map);

void	print_string(char *str);

void	allocation_error_checker(void *pointer);
void	file_open_error_checker(int file_descriptor);
void	stdin_reader_checker(int byte);

int		ft_atoi(char *str);
int		str_length(char *str);
char	**ft_split(char *str, char *charset);

void	print_map(t_map map);
int		get_min(int a, int b, int c);
t_point	solve_map(t_map map);
void	fill_solution(t_map map, t_point max);

int		open_file(char *file_name);
int		get_file_size(char *file_name);
void	set_map_struct(t_map *map, char **lines);
void	read_map_file(t_map *map, char *file_name);

#endif