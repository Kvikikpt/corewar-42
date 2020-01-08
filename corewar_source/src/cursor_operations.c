/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:29:15 by cnikia            #+#    #+#             */
/*   Updated: 2019/12/11 18:29:17 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		cursor_operations_exec(t_arena *arena, t_cursor *cursor)
{
	while (cursor)
	{
		if (cursor->cycles_remaining == 0)
		{
			cursor->current_op = arena->map[cursor->cur_pos];
			if (cursor->current_op >= 0x01 && cursor->current_op <= 0x10)
				cursor->cycles_remaining = op_tab[(int)cursor->current_op].need_cycles;
		}
		if (cursor->cycles_remaining > 0)
			cursor->cycles_remaining--;
		if (cursor->cycles_remaining == 0)
			do_operation(cursor, arena);
		cursor = cursor->next;
	}
}

void		kill_cursor(t_cursor **search_cursor, t_cursor *first_cursor)		// TODO: проверить правильно ли работает
{
	t_cursor *prev_cursor;

	prev_cursor = first_cursor;
	if (prev_cursor == *(search_cursor))
	{
		first_cursor = first_cursor->next;
		free((*search_cursor));
		(*search_cursor) = first_cursor;
		return ;
	}
	while (prev_cursor->next != (*search_cursor) && prev_cursor != NULL)
		prev_cursor = prev_cursor->next;
	prev_cursor->next = (*search_cursor)->next;
	free((*search_cursor));
	(*search_cursor) = prev_cursor->next;
}
