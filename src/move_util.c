/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 11:38:11 by adenhez           #+#    #+#             */
/*   Updated: 2021/09/10 11:38:11 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	case_1(t_state *state, int *x, int *y, int delta)
{
	state->player_up = -delta;
	if (*y + delta >= 0 && state->map[*y + delta][*x] != '1')
	{
		*y += delta ;
		state->step_n++;
		update_str_score(state);
		ft_putnbr_fd(state->step_n, 1);
		ft_putstr_fd("\n", 1);
	}	
}

void	case_2(t_state *state, int *x, int *y, int delta)
{
	state->player_right = delta;
	if (*x + delta >= 0 && state->map[*y][*x + delta] != '1')
	{
		*x += delta;
		state->step_n++;
		update_str_score(state);
		ft_putnbr_fd(state->step_n, 1);
		ft_putstr_fd("\n", 1);
	}
}

int	set_delta(int keycode)
{
	int	delta;

	delta = 1;
	if (keycode == FORWARD || keycode == FORW_2
		|| keycode == LEFT || keycode == LEFT_2)
		delta = -1;
	if (keycode == BACK || keycode == BACK_2
		|| keycode == RIGHT || keycode == RIGHT_2)
		delta = 1;
	return (delta);
}

void	set_player_dir(t_state *state, int keycode)
{
	if (keycode == FORWARD || keycode == FORW_2)
		state->player_dir = 'N';
	else if (keycode == BACK || keycode == BACK_2)
		state->player_dir = 'S';
	else if (keycode == LEFT || keycode == LEFT_2)
		state->player_dir = 'E';
	else if (keycode == RIGHT || keycode == RIGHT_2)
		state->player_dir = 'W';
}

int	move_p(int keycode, t_state *state)
{
	int	x;
	int	y;
	int	delta;

	delta = 0;
	if (state->key_lock == 1)
		return (0);
	x = state->player_coord.x;
	y = state->player_coord.y;
	delta = set_delta(keycode);
	if (keycode == FORWARD || keycode == FORW_2
		|| keycode == BACK || keycode == BACK_2)
	{
		set_player_dir(state, keycode);
		case_1(state, &x, &y, delta);
	}
	else if (keycode == LEFT || keycode == LEFT_2
		|| keycode == RIGHT || keycode == RIGHT_2)
	{
		set_player_dir(state, keycode);
		case_2(state, &x, &y, delta);
	}
	state->player_coord = (t_pos){x, y};
	special_checking(state);
	return (1);
}
