/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_col.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 11:21:06 by msiesse           #+#    #+#             */
/*   Updated: 2019/08/28 10:33:55 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		draw_col(t_env *e)
{
	int	y;

	y = 0;
	while (y < e->y1 && y < H_IMG)
	{
		fill_texture_sky(e->x, y, e);
		y++;
	}
	while (e->y1 != e->y2)
	{
		if (e->y1 >= 0 && e->y1 < H_IMG)
			fill_texture_wall(e->x, e->y1, e);
		e->y1++;
		if (e->y1 >= H_IMG)
			break ;
	}
	while (e->y1 < H_IMG)
	{
		e->dist = ((32.0 * 277.0 * 3.0) / (e->y1 - H_IMG / 2.0))
			/ cos(e->i * e->radian);
		fill_texture_floor(e->x, e->y1, e);
		e->y1++;
	}
}
