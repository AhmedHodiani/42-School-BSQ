#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void    print_string(char *str)
{
    int i = -1;
    while (str[++i])
        write(1, &str[i], 1);
}

void	arg_skiper(int *argc, char ***argv)
{
	*argc = *argc - 1; // to skip ./bsq argc
	*argv = *argv + 1; // to skip ./bsq argv
}

void    allocation_error_checker(void * pointer)
{
    if (pointer == NULL) {
        print_string("Memory allocation failed");
        exit(1);
    }
}

void    file_open_error_checker(int file_descriptor)
{
    if (file_descriptor < 0) {
        print_string("Error opening file");
        exit(1);
    }
}

int	ft_atoi(char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * sign);
}

int     str_length(char *str)
{
    int i = -1;
    while (str[++i]);
    return i;
}


int		get_min(int a, int b, int c)
{
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;

	return min;
}


// todo: is_char_printable
// todo: get_file_size