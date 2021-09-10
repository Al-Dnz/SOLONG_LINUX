/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foe_patrol_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 11:37:17 by adenhez           #+#    #+#             */
/*   Updated: 2021/09/10 11:40:30 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	foe_coord(t_state *state)
{
	int	x;
	int	y;

	y = 0;
	state->foe_coord = (t_pos){0, 0};
	while (state->map[y])
	{
		x = 0;
		while (state->map[y][x])
		{
			if (state->map[y][x] == 'f')
			{
				state->foe_coord = (t_pos){x, y};
				state->map[y][x] = 'x';
				return ;
			}
			x++;
		}
		y++;
	}
}

void	foe_patrol(t_state *state)
{
	static int	sens;
	int			x;
	int			y;

	x = state->foe_coord.x;
	y = state->foe_coord.y;
	if (sens == 1 && state->map[y][x + 1])
	{
		if (state->map[y][x + 1] == 'x')
			state->foe_coord.x += 1;
		else if (ft_find_index("1ecf", state->map[y][x + 1]) != -1)
			sens = 0;
	}
	if (sens == 0 && state->map[y][x - 1])
	{
		if (state->map[y][x - 1] == 'x')
			state->foe_coord.x -= 1;
		else if (ft_find_index("1ecf", state->map[y][x - 1]) != -1)
			sens = 1;
	}
	if (sens == 1 && !state->map[y][x + 1])
		sens = 0;
	if (sens == 0 && !state->map[y][x - 1])
		sens = 1;
}
