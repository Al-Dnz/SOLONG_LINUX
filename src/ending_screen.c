/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ending_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 11:37:06 by adenhez           #+#    #+#             */
/*   Updated: 2021/09/10 11:37:06 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ending_screen(t_state *state, t_img img, int x, int y)
{
	int	i;
	int	j;
	int	ratio;
	int	size;

	draw_map_end(state);
	score_displayer(state);
	size = ft_min(state->win_height, state->win_width);
	ratio = img.width / size;
	if (ratio < 1)
		ratio = 1;
	x = (state->win_width - (img.width / ratio)) / 2;
	y = (state->win_height - (img.height / ratio)) / 2;
	j = -1;
	while (++j < img.height)
	{
		i = -1;
		while (++i < img.width)
			if (img.addr[j * img.line_len / 4 + i] > 0)
				state->img.addr[(y + (j / ratio)) *(state->img.line_len) / 4
					+ (x + (i / ratio))] = img.addr[j * img.line_len / 4 + i];
	}
}
