/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 19:11:47 by cnikia            #+#    #+#             */
/*   Updated: 2019/12/13 19:11:48 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	argument_code_type_check(int arg_code_type)
{
	if (!arg_code_type) // TODO parse argument_code_type
		return (0);
	return (1);
}

static void	move_error_code(t_cursor *wst, t_arena *arena)
{
	wst->next_operation_steps = next_operation_steps_calculation(wst, arena->memory[wst->current_position + 1]);
	wst->dont_move = 0;
	wst->cycles_remaining = 0;
}

void		do_operations(t_cursor *wst, t_arena *arena)
{
	if (wst->current_code >= 0x01 && wst->current_code <= 0x10)
	{
		if (op_tab[(int)wst->current_code].argument_code_type)
			if (!(argument_code_type_check(arena->memory[wst->current_position + 1])))
				move_error_code(wst, arena);
		wst->next_operation_steps = next_operation_steps_calculation(wst, arena->memory[wst->current_position + 1]);
	}
	else
	{
		wst->current_position += 1;
		wst->dont_move = 1;
	}
}