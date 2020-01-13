/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:05:57 by cnikia            #+#    #+#             */
/*   Updated: 2020/01/09 13:06:04 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vis.h>

static int	get_color(t_cell cell)
{
	int id;

	id = cell.player_id;
	if (cell.is_cursor)
		id = TO_CURSOR_COLOR(id);
	return (g_colors[id]);
}

void		draw_map(t_vis *vis, t_arena *arena)
{
	int		color;
	int		row;
	int		i;

	row = 1;
	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0)
			wmove(vis->w_map, row++, 2);
		color = get_color(vis->map[i]);
		wattron(vis->w_map, color);
		wprintw(vis->w_map, "%02x", arena->map[i]);
		wattroff(vis->w_map, color);
		waddch(vis->w_map, ' ');
		i++;
	}
	wattron(vis->w_map, COLOR_PAIR(GRAY));
	box(vis->w_map, 0, 0);
	wattroff(vis->w_map, COLOR_PAIR(GRAY));
}

void		draw_usage(t_vis *vis)
{
	wmove(vis->w_usage, 2, 2);
	wprintw(vis->w_usage, "ESC - exit");
	wmove(vis->w_usage, 2, 20);
	wprintw(vis->w_usage, "SPACE - ");
	vis->is_running ? wattron(vis->w_usage, A_BOLD) : 0;
	wprintw(vis->w_usage, "run");
	vis->is_running ? wattroff(vis->w_usage, A_BOLD) : 0;
	waddch(vis->w_usage, '/');
	!vis->is_running ? wattron(vis->w_usage, A_BOLD) : 0;
	wprintw(vis->w_usage, "stop");
	!vis->is_running ? wattroff(vis->w_usage, A_BOLD) : 0;
	wmove(vis->w_usage, 2, 44);
	wprintw(vis->w_usage, "s - one step");
	wmove(vis->w_usage, 2, 64);
	wprintw(vis->w_usage, "q, w - slow down (-10, -1)");
	wmove(vis->w_usage, 2, 98);
	wprintw(vis->w_usage, "e, r - speed up (+1, +10)");
	wattron(vis->w_usage, COLOR_PAIR(GRAY));
	box(vis->w_usage, 0, 0);
	wattroff(vis->w_usage, COLOR_PAIR(GRAY));
}
