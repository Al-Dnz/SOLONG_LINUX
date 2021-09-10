/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 11:36:53 by adenhez           #+#    #+#             */
/*   Updated: 2021/09/10 11:36:55 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	special_checking(t_state *state)
{
	int	x;
	int	y;

	x = state->player_coord.x;
	y = state->player_coord.y;
	if (state->map[y][x] == 'c')
	{
		state->map[y][x] = 'x';
		draw_map(state);
		state->score++;
	}
	if ((state->map[y][x] == 'e' && !symbol_occurence(state->map, 'c', 0))
			|| (x == state->foe_coord.x && y == state->foe_coord.y))
	{
		state->key_lock = 1;
		if (state->map[y][x] == 'e')
			ending_screen(state, state->win_screen, 0, 0);
		if (x == state->foe_coord.x && y == state->foe_coord.y)
			ending_screen(state, state->gameover_screen, 0, 0);
		mlx_loop_hook(state->mlx, &end_time, state);
	}
}
