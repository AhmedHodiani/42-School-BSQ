/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 21:51:35 by ataher            #+#    #+#             */
/*   Updated: 2024/05/21 23:06:15 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs.h"
#include "structs.h"

int	**create_buffer(int ori_rows, int ori_cols)
{
	int	**buffer;
	int	rows;
	int	cols;
	int	i;

	rows = ori_rows + 1;
	cols = ori_cols + 1;
	buffer = malloc(sizeof(int *) * rows);
	allocation_error_checker(buffer);
	i = 0;
	while (i < rows)
	{
		buffer[i] = (int *)malloc(sizeof(int) * cols);
		allocation_error_checker(buffer[i]);
		i++;
	}
	return (buffer);
}

void	fill_solution(t_map map, t_point max)
{
	t_point	start_point;
	t_point	end_point;
	int		row_indexor;
	int		col_indexor;

	end_point = max;
	start_point.x = max.x - max.value + 1;
	start_point.y = max.y - max.value + 1;
	row_indexor = 0;
	while (row_indexor < map.rows)
	{
		col_indexor = 0;
		while (col_indexor < map.cols)
		{
			if (row_indexor >= start_point.y && row_indexor <= end_point.y
				&& col_indexor >= start_point.x && col_indexor <= end_point.x)
				write(1, &map.full, 1);
			else
				write(1, &map.matrix[row_indexor][col_indexor], 1);
			col_indexor++;
		}
		write(1, "\n", 1);
		row_indexor++;
	}
	write(1, "\n", 1);
}

void	max_setter(t_point *max, int **buffer, int row_indexor, int col_indexor)
{
	int	value;

	value = get_min(
			buffer[row_indexor][col_indexor],
			buffer[row_indexor + 1][col_indexor],
			buffer[row_indexor][col_indexor + 1]) + 1;
	buffer[row_indexor + 1][col_indexor + 1] = value;
	if (value > max->value)
	{
		max->value = value;
		max->y = row_indexor;
		max->x = col_indexor;
	}
}

void	free_buffer(int **buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		free(buffer[i]);
		i++;
	}
	free(buffer);
}

t_point	solve_map(t_map map)
{
	int		**buffer;
	int		row_indexor;
	int		col_indexor;
	t_point	max;

	buffer = create_buffer(map.rows, map.cols);
	max.value = 0;
	row_indexor = -1;
	while (++row_indexor < map.rows)
	{
		col_indexor = -1;
		while (++col_indexor < map.cols)
			if (map.matrix[row_indexor][col_indexor] == map.empty)
				max_setter(&max, buffer, row_indexor, col_indexor);
	}
	free_buffer(buffer);
	return (max);
}
