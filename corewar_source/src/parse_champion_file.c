#include "../includes/corewar.h"

void	parse_champion_file(t_gstate *gstate, int *argc, char ***argv)
{
	int	champion_order;

	champion_order = 0;
	if (ft_strequ(**argv, "-n"))
		champion_order = parse_flag_n(argc, argv);
	if (is_champion_filename(**argv))
		gstate->all_players[gstate->players_num] =
		        parse_champion(champion_order, gstate->players_num, **argv);
}

