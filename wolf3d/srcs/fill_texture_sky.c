/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_texture_sky.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 16:38:22 by msiesse           #+#    #+#             */
/*   Updated: 2019/08/28 10:27:18 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	fill_texture_sky(int x, int y, t_env *e)
{
	double	ratio[2];
	int		i;
	int		j;

	ratio[Y] = (double)(H_IMG / 2.0 - y) / (double)H_IMG;
	ratio[X] = (360.0 - fmod(e->view, 360.0)) / 360;
	i = (x + y * W_IMG) * 4;
	j = (int)round((round(ratio[X] * e->tex[5 + e->rain].width) + round(ratio[Y]
				* e->tex[5 + e->rain].height) * e->tex[5 + e->rain].width)) * 4;
	if (x >= 0 && x < W_IMG && y >= 0 && y < H_IMG)
	{
		e->m.data[i] = e->tex[5 + e->rain].data[j];
		e->m.data[i + 1] = e->tex[5 + e->rain].data[j + 1];
		e->m.data[i + 2] = e->tex[5 + e->rain].data[j + 2];
		e->m.data[i + 3] = e->tex[5 + e->rain].data[j + 3];
	}
}
