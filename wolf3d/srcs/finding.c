/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 11:15:15 by msiesse           #+#    #+#             */
/*   Updated: 2019/08/23 12:07:55 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	finding_wall(t_env *e)
{
	e->pos_hor = sqrt(((e->pos_x - e->xnew) * (e->pos_x - e->xnew))
			+ ((e->pos_y - e->ynew) * (e->pos_y - e->ynew)));
	e->pos_ver = sqrt(((e->pos_x - e->bxnew) * (e->pos_x - e->bxnew))
			+ ((e->pos_y - e->bynew) * (e->pos_y - e->bynew)));
	if (fabs(e->pos_hor) < fabs(e->pos_ver))
	{
		e->y2 = (int)round(e->ynew);
		e->x2 = (int)round(e->xnew);
		e->dist = e->pos_hor;
		if (e->cordinal_hor == 1)
			e->side = 2;
		else
			e->side = 1;
	}
	else
	{
		e->y2 = (int)round(e->bynew);
		e->x2 = (int)round(e->bxnew);
		e->dist = e->pos_ver;
		if (e->cordinal_ver == 1)
			e->side = 3;
		else
			e->side = 4;
	}
}
