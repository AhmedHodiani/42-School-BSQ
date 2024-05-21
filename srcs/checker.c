/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 22:16:19 by ataher            #+#    #+#             */
/*   Updated: 2024/05/21 22:20:53 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs.h"
#include "structs.h"

void	allocation_error_checker(void *pointer)
{
	if (pointer == NULL)
	{
		print_string("Memory allocation failed");
		exit(1);
	}
}

void	file_open_error_checker(int file_descriptor)
{
	if (file_descriptor < 0)
	{
		print_string("Error opening file");
		exit(1);
	}
}

void	stdin_reader_checker(int byte)
{
	if (byte < 0)
	{
		print_string("Error reading STD_IN");
		exit(1);
	}
}
