/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <ceaudouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 16:07:43 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/09/11 15:59:53 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	check_moove(t_env *e)
{
	if ((e->axe <= 90 || e->axe >= 270) && (int)e->pos_x % 64 > 61)
		if (moove_get_z(&e->points, e, e->pos_x / 64 + 1, e->pos_y
					/ 64) == 1)
			e->pos_x -= 4.0;
	if (e->axe > 90 && e->axe < 270 && (int)e->pos_x % 64 > 61)
		if (moove_get_z(&e->points, e, e->pos_x / 64 + 1, e->pos_y
					/ 64) == 1)
			e->pos_x -= 4.0;
	if ((e->axe > 90 && e->axe < 270) && (int)e->pos_x % 64 < 3)
		if (moove_get_z(&e->points, e, e->pos_x / 64 - 1, e->pos_y
					/ 64) == 1)
			e->pos_x += 4.0;
	if ((e->axe < 90 || e->axe > 270) && (int)e->pos_x % 64 < 3)
		if (moove_get_z(&e->points, e, e->pos_x / 64 - 1, e->pos_y
					/ 64) == 1)
			e->pos_x += 4.0;
	if (e->axe >= 0 && e->axe <= 180 && (int)e->pos_y % 64 < 3)
		if (moove_get_z(&e->points, e, e->pos_x / 64, e->pos_y
					/ 64 - 1) == 1)
			e->pos_y += 4.0;
	check_moove2(e);
}

void	forward(t_env *e)
{
	int		tmp_x;
	int		tmp_y;

	if (e->axe >= 0 && e->axe <= 180)
	{
		tmp_x = (e->pos_x + cos(e->axe * e->radian) * 8) / 64;
		tmp_y = (e->pos_y - sin(e->axe * e->radian) * 8) / 64;
		if (moove_get_z(&e->points, e, tmp_x, e->pos_y / 64) == 0)
			e->pos_x += cos(e->axe * e->radian) * ((8 - 1) / (e->speed + 1));
		if (moove_get_z(&e->points, e, e->pos_x / 64, tmp_y) == 0)
			e->pos_y -= sin(e->axe * e->radian) * ((8 - 1) / (e->speed + 1));
	}
	else
	{
		tmp_x = (e->pos_x + cos(e->axe * e->radian) * 8) / 64;
		tmp_y = (e->pos_y - sin(e->axe * e->radian) * 8) / 64;
		if (moove_get_z(&e->points, e, tmp_x, e->pos_y / 64) == 0)
			e->pos_x -= -cos(e->axe * e->radian) * ((8 - 1) / (e->speed + 1));
		if (moove_get_z(&e->points, e, e->pos_x / 64, tmp_y) == 0)
			e->pos_y += -sin(e->axe * e->radian) * ((8 - 1) / (e->speed + 1));
	}
	check_moove(e);
}

void	check_moove_back(t_env *e)
{
	if ((e->axe <= 90 || e->axe >= 270) && (int)e->pos_x % 64 < 3)
		if (moove_get_z(&e->points, e, e->pos_x / 64 - 1, e->pos_y
					/ 64) == 1)
			e->pos_x += 4.0;
	if ((e->axe > 90 && e->axe < 270) && (int)e->pos_x % 64 < 3)
		if (moove_get_z(&e->points, e, e->pos_x / 64 - 1, e->pos_y
					/ 64) == 1)
			e->pos_x += 4.0;
	if ((e->axe > 90 && e->axe < 270) && (int)e->pos_x % 64 > 61)
		if (moove_get_z(&e->points, e, e->pos_x / 64 + 1, e->pos_y
					/ 64) == 1)
			e->pos_x -= 4.0;
	if ((e->axe < 90 || e->axe > 270) && (int)e->pos_x % 64 > 61)
		if (moove_get_z(&e->points, e, e->pos_x / 64 + 1, e->pos_y
					/ 64) == 1)
			e->pos_x -= 4.0;
	if (e->axe >= 0 && e->axe <= 180 && (int)e->pos_y % 64 > 61)
		if (moove_get_z(&e->points, e, e->pos_x / 64, e->pos_y
					/ 64 + 1) == 1)
			e->pos_y -= 4.0;
	check_moove_back2(e);
}

void	back(t_env *e)
{
	int		tmp_x;
	int		tmp_y;

	if (e->axe >= 0 && e->axe <= 180)
	{
		tmp_x = (e->pos_x - cos(e->axe * e->radian) * 8) / 64;
		tmp_y = (e->pos_y + sin(e->axe * e->radian) * 8) / 64;
		if (moove_get_z(&e->points, e, tmp_x, e->pos_y / 64) == 0)
			e->pos_x -= cos(e->axe * e->radian) * ((8 - 1) / (e->speed + 1));
		if (moove_get_z(&e->points, e, e->pos_x / 64, tmp_y) == 0)
			e->pos_y += sin(e->axe * e->radian) * ((8 - 1) / (e->speed + 1));
	}
	else
	{
		tmp_x = (e->pos_x + -cos(e->axe * e->radian) * 8) / 64;
		tmp_y = (e->pos_y + sin(e->axe * e->radian) * 8) / 64;
		if (moove_get_z(&e->points, e, e->pos_x / 64, tmp_y) == 0)
			e->pos_y -= -sin(e->axe * e->radian) * ((8 - 1) / (e->speed + 1));
		if (moove_get_z(&e->points, e, tmp_x, e->pos_y / 64) == 0)
			e->pos_x += -cos(e->axe * e->radian) * ((8 - 1) / (e->speed + 1));
	}
	check_moove_back(e);
}
