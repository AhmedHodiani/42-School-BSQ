#include "structs.h"
#include "srcs.h"

void    print_map(t_map map)
{
    int i = 0;
    while (i < map.rows)
    {
        print_string(map.matrix[i]);
        print_string("\n");
        i++;
    }
}

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


void        fill_buffer(int **buffer, int row_size, int col_size)
{
    int row_indexor = -1;

    while (++row_indexor < row_size)
    {
        int col_indexor = -1;
        while (++col_indexor < col_size)
            buffer[row_indexor][col_indexor] = 0;
    }
}

void        print_buffer(int **buffer, int row_size, int col_size)
{
    int row_indexor = 0;

    while (++row_indexor < row_size)
    {
        int col_indexor = 0;
        while (++col_indexor < col_size)
            printf("%d", buffer[row_indexor][col_indexor]);
        printf("%s", "\n");
    }
}

t_map   solve_map(t_map map)
{
    int **buffer = create_buffer(map.rows, map.cols);

    print_buffer(buffer, map.rows + 1, map.cols + 1);
    printf("%s", "\n");

    int row_indexor = 0;
    while (row_indexor < map.rows)
    {
        int col_indexor = 0;
        while (col_indexor < map.cols)
        {
            if (map.matrix[row_indexor][col_indexor] == map.empty)
            {
                buffer[row_indexor + 1][col_indexor + 1] = get_min(
                    buffer[row_indexor][col_indexor],
                    buffer[row_indexor + 1][col_indexor],
                    buffer[row_indexor][col_indexor + 1]
                ) + 1;

                print_buffer(buffer, map.rows + 1, map.cols + 1);
                printf("%s", "\n");
            }


            col_indexor++;
        }
        row_indexor++;
    }

    printf("%d\n", map.rows);
    printf("%d", map.cols); 
}