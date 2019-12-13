#include "../includes/corewar.h"

int		is_champion_filename(char *filename)
{
	size_t	filename_len;

	if (!filename)
		print_error_and_exit("Champion filename is invalid", 40);
	filename_len = ft_strlen(filename);
	if (ft_strchr(filename, '.'))
	{
		if (filename_len > 4 && ft_strequ(filename + (filename_len - 4), ".cor"))
			return (1);
		print_error_and_exit("Champion filename is invalid", 40);
	}
	return (0);
}

void	parse_arguments(t_gstate *gstate, int argc, char **argv)
{
	if (argc == 0)
		print_usage();

    while (argc > 0)
    {
        if (ft_strequ(*argv, "-n") || is_champion_filename(*argv))
			parse_champion_file(gstate, &argc, &argv);
        else if (ft_strequ(*argv, "-dump"))
            parse_flag_dump(gstate, &argc, &argv);
        else if (ft_strequ(*argv, "-v"))
            parse_flag_v(gstate, &argc, &argv);
        else
            print_usage();
    }

    if (gstate->players_num < 1 || gstate->players_num > MAX_PLAYERS)
    {
		print_error_and_exit(CONCAT_STR_WITH_NBR(
	"Players amount less than 1 or more than ", MAX_PLAYERS), 45);
    }
}

void print_usage()
{
    printf("Usage: ./corewar [-v][-d <num> | -n <num> ] <champion1.cor> <...>\n");
    exit(1);
}
