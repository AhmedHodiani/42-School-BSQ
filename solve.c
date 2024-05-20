#include "structs.h"
#include "srcs.h"


void    print_map(t_map map)

{
    int i = 0;
    while (i < map.num_lines)
    {
     
        print_string(map.matrix[i]);
        print_string("\n");
        i++;
    }
}

// t_map   solve_map()
// {

// }