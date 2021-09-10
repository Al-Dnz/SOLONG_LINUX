/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 11:37:56 by adenhez           #+#    #+#             */
/*   Updated: 2021/09/10 11:37:56 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	map_analyzer(t_state *state)
{
	state->error = false;
	state->valid_symbol = valid_symbol(state->map);
	state->player_occur = symbol_occurence(state->map, 'P', 1);
	state->exit_occur = symbol_occurence(state->map, 'E', 0);
	state->collectible_occur = symbol_occurence(state->map, 'C', 0);
	state->foe_occur = symbol_occurence(state->map, 'F', 1);
	state->foe_error = false;
	if (count_symbol(state->map, 'F') > 1)
		state->foe_error = true;
	state->rectangular_map = rectangular_map(state->map);
	state->closed_map = true;
	player_coord(state);
	if (state->map_height > 2 && state->map_width > 2 && state->player_occur)
		map_floodfill(state, state->player_coord.x, state->player_coord.y);
	if (state->closed_map == true)
		change_rest_of_map_symbol(state->map);
}

void	map_diagnostic(t_state *state)
{
	int	fd;

	fd = 2;
	if (state->error)
		ft_putstr_fd("Error\n", fd);
	if (state->map == NULL)
		ft_putstr_fd("MAP IS EMPTY\n", fd);
	if (state->map_height < 3 || state->map_width < 3)
		ft_putstr_fd("MAP IS TOO SHORT\n", fd);
	if (state->valid_symbol == false)
		ft_putstr_fd("WRONG(S) SYMBOL(S) IS/ARE SET IN MAP\n", fd);
	if (state->player_occur == false)
		ft_putstr_fd("PLAYER SYMBOL IS NOT CORRECTLY SET\n", fd);
	if (state->exit_occur == false)
		ft_putstr_fd("EXIT SYMBOL IS NOT CORRECTLY SET\n", fd);
	if (state->collectible_occur == false)
		ft_putstr_fd("COLLECTIBLE SYMBOLS ARE NOT SET\n", fd);
	if (state->map && state->closed_map == false)
		ft_putstr_fd("MAP IS NOT CLOSED\n", fd);
	if (state->rectangular_map == false)
		ft_putstr_fd("MAP IS NOT RECTANGULAR\n", fd);
	if (state->foe_error == true)
		ft_putstr_fd("TOO MUCH FOE\n", fd);
}

int	map_validation(t_state *state)
{
	if (state->valid_symbol == false
		|| state->player_occur == false
		|| state->exit_occur == false
		|| state->collectible_occur == false
		|| state->rectangular_map == false
		|| state->closed_map == false
		|| state->foe_error == true)
	{
		state->error = true;
		return (0);
	}
	return (1);
}
