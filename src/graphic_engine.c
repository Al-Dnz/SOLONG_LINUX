/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_engine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 11:37:21 by adenhez           #+#    #+#             */
/*   Updated: 2021/09/10 11:37:21 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	draw_pix(t_img *img, int x, int y, int color)
{
	img->addr[y * img->line_len / 4 + x] = color;
}
