/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 17:12:27 by cnikia            #+#    #+#             */
/*   Updated: 2019/12/09 17:12:30 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "corewar.h"
#include <stdio.h>

t_arena		*init_arena()
{
	t_arena		*arena;
	int 		a;

	a = 0;
	if (!(arena = (t_arena *)malloc(sizeof(t_arena))))
		return (NULL);
	while (a < MEM_SIZE)
		arena->memory[a++] = 0x0;
	arena->last_live = 0;
	arena->all_cycles = 0;
	arena->recent_live = 0;
	arena->cycles_to_die = CYCLE_TO_DIE;
	arena->checks = 0;
	arena->next_cursor_num = 0;
	return (arena);
}

t_cursor	*init_cursor(int num, int reg)  // TODO: num и reg в этой функции одно и тоже
{
	t_cursor	*cursor;
	int 		a;

	a = 0;
	if (!(cursor = (t_cursor *)malloc(sizeof(t_cursor))))
		return (NULL);
	cursor->carry = 0;
	cursor->current_code = 0;
	cursor->current_position = 0;
	cursor->cycles_remaining = 0;
	cursor->last_live_cycle = 0;
	cursor->next = NULL;
	cursor->prev = NULL;
	cursor->next_operation_steps = 0;
	cursor->num = num;
	while (a < 16)
		cursor->reg[a++] = 0;
	cursor->reg[0] = -1 * reg;
	return (cursor);
}

void		fill_champions_code(t_arena *arena, t_gstate *gstate)
{
	int 	order;
	int 	a;
	int 	b;
	int 	c;

	order = MEM_SIZE / gstate->players_num;
	c = 0;
	a = 0;
	while(c < gstate->players_num)
	{
		b = 0;
		while (b < gstate->all_players[c]->size)
			arena->memory[a++] = gstate->all_players[c]->code[b++];
		c++;
		a = order;          // TODO: следующие две строки можно заменить одной: a += order;
		order += order;
	}
}

t_cursor	*fill_cursors(t_gstate *gstate, t_arena *arena)
{
	int 		order;
	t_cursor	*next;  // todo: maybe next_cursor
	t_cursor	*curr;
	int 		a;
	int 		b;

	order = MEM_SIZE / gstate->players_num;
	b = 0;
	a = 1;
	curr = NULL;
	while (a <= gstate->players_num)
	{
		next = init_cursor(a, a);   // todo: какой смысл отправлять одинаковые числа
		next->current_position = b;
		next->next = curr;
		next->next_operation_steps = 0; // я не знаю пока как это написать
		next->current_code = arena->memory[b];
		if (curr)
			curr->prev = next;
		curr = next;
		b = order;      // todo: можно заменить одной строчкой b += order
		order += order;
		a++;
	}
	return (curr);
}