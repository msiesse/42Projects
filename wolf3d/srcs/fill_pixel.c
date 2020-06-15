/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:58:49 by msiesse           #+#    #+#             */
/*   Updated: 2019/09/05 16:41:22 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** Function to change pixels in img_data pointer without brightness
*/

void		fill_pixel_map(char *img_data, int x, int y, int color)
{
	int	i;

	i = (x + y * W_MAP) * 4;
	if (x >= 0 && x < W_MAP && y >= 0 && y < H_MAP)
	{
		img_data[i] = (char)(color & 0x0000ff);
		img_data[i + 1] = (char)((color & 0x00ff00) >> 8);
		img_data[i + 2] = (char)((color & 0xff0000) >> 16);
		img_data[i + 3] = (char)(((color & 0xff000000) >> 16) >> 8);
	}
}

void		fill_pixel(char *img_data, int x, int y, int color)
{
	int	i;

	i = (x + y * W_IMG) * 4;
	if (x >= 0 && x < W_IMG && y >= 0 && y < H_IMG)
	{
		img_data[i] = (char)(color & 0x0000ff);
		img_data[i + 1] = (char)((color & 0x00ff00) >> 8);
		img_data[i + 2] = (char)((color & 0xff0000) >> 16);
		img_data[i + 3] = (char)(((color & 0xff000000) >> 16) >> 8);
	}
}

static int	find_j(double ratio_x, double ratio_y, t_tex *tex)
{
	int	j;

	j = (int)round((floor(ratio_x * tex->width) + floor(ratio_y
				* tex->height) * tex->width)) * 4;
	return (j);
}

void		fill_texture_wall(int x, int y, t_env *e)
{
	double	ratio_y;
	double	ratio_x;
	int		i;
	int		j;

	if (e->side == 1 || e->side == 2)
		ratio_x = (fmod(e->xnew, 64.0) / 64.0);
	else
		ratio_x = (fmod(e->bynew, 64.0) / 64.0);
	ratio_y = fabs(1.0 - ((double)e->y2 - (double)y) / e->wall);
	i = (x + y * W_IMG) * 4;
	j = find_j(ratio_x, ratio_y, &e->tex[e->side]);
	if (x >= 0 && x < W_IMG && y >= 0 && y < H_IMG)
	{
		e->m.data[i] = e->tex[e->side].data[j];
		e->m.data[i + 1] = e->tex[e->side].data[j + 1];
		e->m.data[i + 2] = e->tex[e->side].data[j + 2];
		e->m.data[i + 3] = e->tex[e->side].data[j + 3]
			+ ceil_func(e->dist / (C_SHDOW - (e->rain * 3)), 255.0);
	}
}
