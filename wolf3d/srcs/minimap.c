/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 14:58:09 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/08/28 14:50:08 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		minimap(t_env *e)
{
	e->y = 0;
	e->mapy = e->pos_y - 192;
	while (e->y < H_MAP)
	{
		e->x = 0;
		e->mapx = e->pos_x - 192;
		while (e->x < W_MAP)
		{
			if (moove_get_z(&e->points, e, e->mapx / 64, e->mapy / 64) == 1)
				fill_pixel_map(e->m.data_map, e->x, e->y, GREY2);
			else
				fill_pixel_map(e->m.data_map, e->x, e->y, GREY);
			e->x++;
			e->mapx += 2;
		}
		e->y++;
		e->mapy += 2;
	}
	fill_pixel_map(e->m.data_map, W_MAP / 2, H_MAP / 2, WHITE);
	fill_pixel_map(e->m.data_map, W_MAP / 2 - 1, H_MAP / 2, WHITE);
	fill_pixel_map(e->m.data_map, W_MAP / 2 + 1, H_MAP / 2, WHITE);
	fill_pixel_map(e->m.data_map, W_MAP / 2, H_MAP / 2 - 1, WHITE);
	fill_pixel_map(e->m.data_map, W_MAP / 2, H_MAP / 2 + 1, WHITE);
}
