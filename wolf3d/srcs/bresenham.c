/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 13:41:42 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/08/21 14:47:18 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_octant1(t_env *e, float f)
{
	f = e->dx;
	e->dx *= 2;
	e->dy *= 2;
	while (e->t_x1 < e->x2)
	{
		fill_pixel_map(e->m.data_map, e->x1, e->y1, RED);
		e->x1++;
		e->t_x1 += 2;
		f -= e->dy;
		if (f <= 0)
		{
			e->y1++;
			f += e->dx;
		}
	}
}

void	ft_octant8(t_env *e, float f)
{
	f = e->dx;
	e->dx *= 2;
	e->dy *= 2;
	while (e->t_x1 < e->x2)
	{
		fill_pixel_map(e->m.data_map, e->x1, e->y1, RED);
		e->x1++;
		e->t_x1 += 2;
		f += e->dy;
		if (f <= 0)
		{
			e->y1--;
			f += e->dx;
		}
	}
}

void	ft_octant2(t_env *e, float f)
{
	f = e->dy;
	e->dy *= 2;
	e->dx *= 2;
	while (e->t_y1 < e->y2)
	{
		fill_pixel_map(e->m.data_map, e->x1, e->y1, RED);
		e->y1++;
		e->t_y1 += 2;
		f -= e->dx;
		if (f <= 0)
		{
			e->x1++;
			f += e->dy;
		}
	}
}

void	ft_octant7(t_env *e, float f)
{
	f = e->dy;
	e->dy *= 2;
	e->dx *= 2;
	while (e->t_y1 > e->y2 && e->t_y1 > 0)
	{
		fill_pixel_map(e->m.data_map, e->x1, e->y1, RED);
		e->y1--;
		e->t_y1 -= 2;
		f += e->dx;
		if (f > 0)
		{
			e->x1++;
			f += e->dy;
		}
	}
}

void	ft_bresenham(t_env *e)
{
	float	f;

	f = 0.0;
	e->dx = e->x2 - e->t_x1;
	e->dy = e->y2 - e->t_y1;
	if (e->dx > 0)
	{
		if (e->dy > 0)
		{
			if (e->dx >= e->dy)
				ft_octant1(e, f);
			else
				ft_octant2(e, f);
		}
		else if (e->dy < 0 && e->dx > 0)
		{
			if (e->dx >= -e->dy)
				ft_octant8(e, f);
			else
				ft_octant7(e, f);
		}
		if (e->dy == 0 && e->dx > 0)
			ft_octant_horright(e);
	}
	ft_bresenham2(e, f);
}
