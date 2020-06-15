/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresemham3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 10:52:07 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/08/21 14:48:16 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	ft_octant_horleft(t_env *e)
{
	while (e->t_x1 > e->x2)
	{
		fill_pixel_map(e->m.data_map, e->x1, e->y1, RED);
		e->x1--;
		e->t_x1 -= 2;
	}
}

void	ft_octant_vert(t_env *e)
{
	while (e->t_y1 < e->y2)
	{
		fill_pixel_map(e->m.data_map, e->x1, e->y1, RED);
		e->y1++;
		e->t_y1 += 2;
	}
}

void	ft_octant_vert2(t_env *e)
{
	while (e->t_y1 > e->y2)
	{
		fill_pixel_map(e->m.data_map, e->x1, e->y1, RED);
		e->y1--;
		e->t_y1 -= 2;
	}
}

void	ft_octant_horright(t_env *e)
{
	while (e->t_x1 < e->x2)
	{
		fill_pixel_map(e->m.data_map, e->x1, e->y1, RED);
		e->x1++;
		e->t_x1 += 2;
	}
}
