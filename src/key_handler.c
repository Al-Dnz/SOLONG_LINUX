/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 11:37:34 by adenhez           #+#    #+#             */
/*   Updated: 2021/09/10 11:37:34 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	keypress(int keycode, t_state *state)
{
	if (keycode == EXIT)
		quit(state, 0);
	return (1);
}

int	keyrelease(int keycode, t_state *state)
{
	if (keycode == FORWARD || keycode == 126)
		state->key.forward = false;
	else if (keycode == BACK || keycode == 125)
		state->key.back = false;
	else if (keycode == LEFT || keycode == 123)
		state->key.left = false;
	else if (keycode == RIGHT || keycode == 124)
		state->key.right = false;
	return (1);
}
