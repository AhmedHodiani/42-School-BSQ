void	arg_skiper(int *argc, char ***argv)
{
	*argc = *argc - 1; // to skip ./bsq argc
	*argv = *argv + 1; // to skip ./bsq argv
}


// todo: is_char_printable
// todo: get_file_size