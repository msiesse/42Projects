/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 18:01:22 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/08/21 14:48:44 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	ft_bresenham2(t_env *e, float f)
{
	if (e->dx < 0)
	{
		if (e->dy > 0)
		{
			if (-e->dx >= e->dy)
				ft_octant4(e, f);
			else
				ft_octant3(e, f);
		}
		if (e->dy < 0 && e->dx < 0)
		{
			if (e->dx <= e->dy)
				ft_octant5(e, f);
			else
				ft_octant6(e, f);
		}
		if (e->dy == 0 && e->dx < 0)
			ft_octant_horleft(e);
	}
	if (e->dx == 0)
		if (e->dy > 0)
			ft_octant_vert(e);
	if (e->dy < 0 && e->dx == 0)
		ft_octant_vert2(e);
}
