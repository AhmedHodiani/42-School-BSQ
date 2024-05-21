/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 22:29:47 by ataher            #+#    #+#             */
/*   Updated: 2024/05/21 23:22:46 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include <stdbool.h>

typedef struct s_map
{
	int		rows;
	int		cols;

	char	empty;
	char	obstacle;
	char	full;

	char	**matrix;
}	t_map;

typedef struct s_point
{
	int	x;
	int	y;
	int	value;
}	t_point;

#endif