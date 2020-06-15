/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:53:31 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/08/28 11:03:48 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		check(t_env *e)
{
	e->xold = (int)floor(e->xnew / 64.0);
	e->yold = (int)floor(e->ynew / 64.0);
	if (e->xold < 0 || e->yold < 0 || e->xold > e->cols || e->yold > e->lines)
	{
		e->xnew = 214748364;
		e->ynew = 214748364;
		return (1);
	}
	if (get_z(&e->points, e) == 1)
		return (1);
	return (0);
}

void	detection_hor(t_env *e)
{
	if (e->view > 0.0 && e->view < 180.0)
	{
		e->ay = floor((e->pos_y / 64.0)) * (64.0) - 0.000001;
		e->ya = -64.0;
		e->xa = (64.0 / tan(e->view * e->radian));
		e->cordinal_hor = 2;
	}
	else
	{
		e->ay = floor((e->pos_y / 64.0)) * (64.0) + 64.0;
		e->ya = 64.0;
		e->xa = (64.0 / -tan(e->view * e->radian));
		e->cordinal_hor = 1;
	}
	e->ax = e->pos_x + (e->pos_y - e->ay) / tan(e->view * e->radian);
	e->ynew = e->ay;
	e->xnew = e->ax;
	while (check(e) != 1)
	{
		e->ynew += e->ya;
		e->xnew += e->xa;
	}
}

int		check_ver(t_env *e)
{
	e->bxold = e->bxnew / 64;
	e->byold = e->bynew / 64;
	if (e->bxold < 0 || e->byold < 0 || e->byold > e->lines
			|| e->bxold > e->cols)
	{
		e->bxnew = 214748364;
		e->bynew = 214748364;
		return (1);
	}
	if (get_bz(&e->points, e) == 1)
		return (1);
	return (0);
}

void	detection_ver(t_env *e)
{
	if (e->view < 270.0 && e->view > 90.0)
	{
		e->bx = floor(e->pos_x / 64.0) * (64.0) - 0.000001;
		e->xb = -64.0;
		e->yb = 64.0 * tan(e->view * e->radian);
		e->cordinal_ver = 2;
	}
	else
	{
		e->bx = floor((e->pos_x / 64.0)) * (64.0) + 64.0;
		e->xb = 64.0;
		e->yb = 64.0 * -tan(e->view * e->radian);
		e->cordinal_ver = 1;
	}
	e->by = e->pos_y + (e->pos_x - e->bx) * tan(e->view * e->radian);
	e->bynew = e->by;
	e->bxnew = e->bx;
	while (check_ver(e) != 1)
	{
		e->bynew += e->yb;
		e->bxnew += e->xb;
	}
}

void	search_walls(t_env *e)
{
	detection_hor(e);
	detection_ver(e);
	finding_wall(e);
}
