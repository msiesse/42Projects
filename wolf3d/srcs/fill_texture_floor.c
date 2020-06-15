/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_texture_floor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 11:11:42 by msiesse           #+#    #+#             */
/*   Updated: 2019/08/27 09:47:24 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	get_point_floor(t_env *e)
{
	e->x_floor = e->dist * cos(e->view * e->radian) + e->pos_x;
	e->y_floor = e->dist * -sin(e->view * e->radian) + e->pos_y;
}

void		fill_texture_floor(int x, int y, t_env *e)
{
	double	ratio[2];
	int		i;
	int		j;

	get_point_floor(e);
	ratio[X] = fabs(fmod(e->x_floor, 64.0) / 64.0);
	ratio[Y] = fabs(fmod(e->y_floor, 64.0) / 64.0);
	i = (x + y * W_IMG) * 4;
	j = (int)round((round(ratio[X] * e->tex[0].width) + round(ratio[Y]
				* e->tex[0].height) * e->tex[0].width)) * 4;
	if (x >= 0 && x < W_IMG && y >= 0 && y < H_IMG)
	{
		e->m.data[i] = e->tex[0].data[j];
		e->m.data[i + 1] = e->tex[0].data[j + 1];
		e->m.data[i + 2] = e->tex[0].data[j + 2];
		e->m.data[i + 3] = e->tex[0].data[j + 3]
			+ ceil_func(e->dist / (C_SHDOW - (e->rain * 3)), 255.0);
	}
}
