/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_vert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 15:27:44 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/03/05 18:11:23 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	ft_octant4(t_env *e, float f)
{
	f = e->dx;
	e->dx *= 2;
	e->dy *= 2;
	while (e->t_x1 > e->x2)
	{
		fill_pixel_map(e->m.data_map, e->x1, e->y1, RED);
		e->x1--;
		e->t_x1 -= 2;
		f += e->dy;
		if (f >= 0)
		{
			e->y1++;
			f += e->dx;
		}
	}
}

void	ft_octant3(t_env *e, float f)
{
	f = e->dy;
	e->dx *= 2;
	e->dy *= 2;
	while (e->t_y1 < e->y2)
	{
		fill_pixel_map(e->m.data_map, e->x1, e->y1, RED);
		e->y1++;
		e->t_y1 += 2;
		f += e->dx;
		if (f <= 0)
		{
			e->x1--;
			f += e->dy;
		}
	}
}

void	ft_octant5(t_env *e, float f)
{
	f = e->dx;
	e->dx *= 2;
	e->dy *= 2;
	while (e->t_x1 > e->x2)
	{
		fill_pixel_map(e->m.data_map, e->x1, e->y1, RED);
		e->x1--;
		e->t_x1 -= 2;
		f -= e->dy;
		if (f >= 0)
		{
			e->y1--;
			f += e->dx;
		}
	}
}

void	ft_octant6(t_env *e, float f)
{
	f = e->dy;
	e->dx *= 2;
	e->dy *= 2;
	while (e->t_y1 > e->y2)
	{
		fill_pixel_map(e->m.data_map, e->x1, e->y1, RED);
		e->y1--;
		e->t_y1 -= 2;
		f -= e->dx;
		if (f >= 0)
		{
			e->x1--;
			f += e->dy;
		}
	}
}
