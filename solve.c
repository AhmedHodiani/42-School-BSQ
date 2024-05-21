#include "structs.h"
#include "srcs.h"

// void    print_map(t_map map)
// {
//     int i = 0;
//     while (i < map.rows)
//     {
//         print_string(map.matrix[i]);
//         print_string("\n");
//         i++;
//     }
// }

int   **create_buffer(int ori_rows, int ori_cols)
{
    int **buffer;
    int rows = ori_rows + 1;
    int cols = ori_cols + 1;

    buffer = malloc(sizeof(int *) * rows);
    allocation_error_checker(buffer);

	int i = 0;
	while (i < rows)
	{
		buffer[i] = (int *)malloc(sizeof(int) * cols);
        allocation_error_checker(buffer[i]);
		i++;
	};

    return buffer;
}


// void        fill_buffer(int **buffer, int row_size, int col_size)
// {
//     int row_indexor = -1;

//     while (++row_indexor < row_size)
//     {
//         int col_indexor = -1;
//         while (++col_indexor < col_size)
//             buffer[row_indexor][col_indexor] = 0;
//     }
// }

// void        print_buffer(int **buffer, int row_size, int col_size)
// {
//     int row_indexor = -1;

//     while (++row_indexor < row_size)
//     {
//         int col_indexor = -1;
//         while (++col_indexor < col_size)
//             printf("%d", buffer[row_indexor][col_indexor]);
//         printf("%s", "\n");
//     }
// }
void    fill_solution(t_map map, t_point max)
{
    t_point start_point;
    t_point end_point = max;
    
    start_point.x = max.x - max.value + 1;
    start_point.y = max.y - max.value + 1;
    
    int row_indexor = 0;
    while (row_indexor < map.rows)
    {
        int col_indexor = 0;
        while (col_indexor < map.cols)
        {
            if (row_indexor >= start_point.y 
            && row_indexor <= end_point.y && col_indexor >= start_point.x && col_indexor <= end_point.x)
                write(1, &map.full, 1);
            else
                write(1, &map.matrix[row_indexor][col_indexor], 1);
            
            col_indexor++;
        }
        write(1, "\n", 1);
        row_indexor++;
    }
}


t_point   solve_map(t_map map)
{
    int **buffer = create_buffer(map.rows, map.cols);
    int row_indexor = 0;
    t_point max;

    max.value = 0;
    max.x = 0;
    max.y = 0;

    while (row_indexor < map.rows)
    {
        int col_indexor = 0;
        while (col_indexor < map.cols)
        {
            if (map.matrix[row_indexor][col_indexor] == map.empty)
            {
                int value = get_min(
                    buffer[row_indexor][col_indexor],
                    buffer[row_indexor + 1][col_indexor],
                    buffer[row_indexor][col_indexor + 1]
                ) + 1;

                buffer[row_indexor + 1][col_indexor + 1] = value;

                if (value > max.value)
                {
                    max.value = value;
                    max.y = row_indexor;
                    max.x = col_indexor;
                }
            }
            col_indexor++;
        }
        row_indexor++;
    }

    // print_buffer(buffer, map.rows + 1, map.cols + 1);
    // printf("(%d, %d) => %d", max.x, max.y, max.value);
    
    // print_map(map);
    // printf("%s", "\n");
    // printf("%s", "\n");
    return max;
}