/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 11:38:30 by adenhez           #+#    #+#             */
/*   Updated: 2021/09/10 11:40:41 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	period_process(t_state *state)
{
	state->timer++;
	if (state->timer > state->sprite_period)
		state->timer = 0;
	if (!state->end_timer
		&& (state->timer == state->sprite_period / 2 || state->timer == 0))
	{
		if (state->foe_occur)
			foe_patrol(state);
		draw_map(state);
		special_checking(state);
	}
	return (0);
}

int	end_time(t_state *state)
{
	state->end_timer++;
	if (state->end_timer > state->end_period)
		quit(state, 0);
	return (0);
}
