/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_without_visualisation.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:01:51 by cnikia            #+#    #+#             */
/*   Updated: 2020/01/09 15:01:52 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			end_of_battle(t_gstate *gstate)
{
	int 	a;

	a = 0;
	while (gstate->all_players[a])
	{
		if (a == gstate->arena->last_live)
			break ;
		a++;
	}
	if (gstate->all_players[a])
		printf("WINNER WINNER, CHICHEN DINNER!!! CONGRAT %s\n", gstate->all_players[a]->name);
	else
		printf("There is no winners out of here...\n");
}

void			init_battle(t_gstate *gstate)
{
	int	a;

	a = 0;
	printf("Introducing contestants...\n");
	while (a < gstate->players_num)
	{
		printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", (a + 1),
			   gstate->all_players[a]->size, gstate->all_players[a]->name,
			   gstate->all_players[a]->comment);
		a++;
	}
}
