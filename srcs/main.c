/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 21:41:59 by ataher            #+#    #+#             */
/*   Updated: 2024/05/21 23:33:45 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs.h"
#include "structs.h"

int	open_file(char *file_name)
{
	int	file_descriptor;

	file_descriptor = open(file_name, O_RDONLY);
	file_open_error_checker(file_descriptor);
	return (file_descriptor);
}

void	arg_skiper(int *argc, char ***argv)
{
	*argc = *argc - 1;
	*argv = *argv + 1;
}

void	free_map(t_map map)
{
	int	i;

	i = 0;
	while (i < map.rows)
	{
		free(map.matrix[i]);
		map.matrix[i] = NULL;
		i++;
	}
	free(--map.matrix);
}

int	main(int argc, char *argv[])
{
	t_map	map;
	t_point	max;
	int		i;

	arg_skiper(&argc, &argv);
	if (argc == 0)
	{
		read_user_input(&map);
		write(1, "\n", 1);
		max = solve_map(map);
		fill_solution(map, max);
		free_map(map);
	}
	else
	{
		i = 0;
		while (i < argc)
		{
			read_map_file(&map, argv[i]);
			max = solve_map(map);
			fill_solution(map, max);
			free_map(map);
			i++;
		}
	}
	
	return (0);
}
