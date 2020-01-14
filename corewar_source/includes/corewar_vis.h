/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:54:56 by cnikia            #+#    #+#             */
/*   Updated: 2020/01/14 14:54:57 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VIS_H
# define COREWAR_VIS_H

# include <ncurses.h>
# include "corewar.h"

# define COL_WIDTH		65
# define MAP_WIDTH		(COL_WIDTH * 3)
# define MAP_HEIGHT		66
# define USAGE_HEIGHT	5

/*
**	MACROSES
*/

# define TO_CURSOR_COLOR(n)	(n + COLORS_AMOUNT)

/*
**	COLORS
*/

# define COLORS_AMOUNT	7

# define COLOR_GRAY		8
# define COLOR_INDIGO	12
# define COLOR_ERROR	3

# define GRAY			4
# define GREEN			5
# define PURPLE			6
# define RED			7
# define CYAN			8
# define MAGENTA		9
# define YELLOW			10
# define GRAY_CUR		11
# define GREEN_CUR		12
# define PURPLE_CUR		13
# define RED_CUR		14
# define CYAN_CUR		15
# define MAGENTA_CUR	16
# define YELLOW_CUR		17

/*
**	SPEED
*/

# define DEFAULT_SPEED	50000
# define MIN_SPEED		0
# define MAX_SPEED		100000

static int				g_colors[COLORS_AMOUNT * 2] =
{
	COLOR_PAIR(GRAY),
	COLOR_PAIR(GREEN),
	COLOR_PAIR(RED),
	COLOR_PAIR(PURPLE),
	COLOR_PAIR(MAGENTA),
	COLOR_PAIR(CYAN),
	COLOR_PAIR(YELLOW),
	COLOR_PAIR(GRAY_CUR),
	COLOR_PAIR(GREEN_CUR),
	COLOR_PAIR(RED_CUR),
	COLOR_PAIR(PURPLE_CUR),
	COLOR_PAIR(MAGENTA_CUR),
	COLOR_PAIR(CYAN_CUR),
	COLOR_PAIR(YELLOW_CUR),
};

/*
**	HOTKEYS
*/

# define EXIT			27
# define RUN			32
# define ONE_CYCLE		's'
# define SPEED_UP10		'e'
# define SPEED_UP100	'r'
# define SLOW_DOWN10	'w'
# define SLOW_DOWN100	'q'

typedef struct			s_cell
{
	int			player_id;
	char		is_cursor:2;
}						t_cell;

typedef struct			s_vis
{
	WINDOW		*w_map;
	WINDOW		*w_usage;
	WINDOW		*w_info;

	int			width;
	int			height;
	char		is_running:2;
	int			speed;
	char		btn;
	t_cell		map[MEM_SIZE];
}						t_vis;

t_vis					*init_vis();
void					visualisation(t_gstate *gstate, t_arena *arena);
void					prepare_map(t_gstate *gstate);
void					check_window_size(t_vis *vis);
void					init_color_palette();
void					draw_map(t_vis *vis, t_arena *arena);
void					draw_usage(t_vis *vis);
void					draw_info(t_gstate *gstate, t_arena *arena);

#endif
