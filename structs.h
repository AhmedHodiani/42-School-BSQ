#include <stdbool.h>
#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct s_map
{
    int		rows; // aka max square side len
    int     cols;

	char    empty;
    char    obstacle;
    char    full;

    char    **matrix; // 2d array
    bool	is_valid;
}   t_map;

typedef struct s_point
{
    int x;
    int y;
}   t_point;

typedef struct s_square
{
    t_point start; // top-left
    t_point end; // bottom-right
}   t_square;

#endif