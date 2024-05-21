#include "structs.h"
#include "srcs.h"



// char	**read_user_input()
// {
//     // todo
// }
void	arg_skiper(int *argc, char ***argv)
{
	*argc = *argc - 1;
	*argv = *argv + 1;
}

int		main(int argc, char *argv[])
{
	t_map		map;
    t_point     max;
    int         i;

	arg_skiper(&argc, &argv); // to skip executable name from argc and argv

    if (argc == 0)
    {
        // take input from user;
    }
    else 
    {
        // while loop through files;
        i = 0;
        while (i < argc)
        {
            read_map_file(&map, argv[i]);
            max = solve_map(map);
            fill_solution(map, max);
            write(1, "\n", 1);

            i++;
        }
    }

	return (0);
}