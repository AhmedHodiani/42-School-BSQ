#include <stdio.h>
#include <unistd.h>
#include "structs.h"
#include "srcs.h"


char	**read_user_input()
{
    // todo
}

char	**read_file(char *filename)
{
    // todo
}


t_map	parse_map(char *filename)
{
    if (filename == NULL)
    {
        // read_user_input
    }
    else
    {
        // read_file
    }
}


int		main(int argc, char *argv[])
{
	t_map		map;
	char		*filename;
	int			i;

	i = 0;
	arg_skiper(&argc, &argv);
    
    if (argc == 0)
    {
        // take input from user;
    }
    else 
    {
        // while loop through files;
    }


	// free memory map please please dont foooorgett!!
	return (0);
}