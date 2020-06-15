/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <ceaudouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:39:18 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/09/11 15:05:20 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	check_moove2(t_env *e)
{
	if (e->axe < 360 && e->axe > 180 && (int)e->pos_y % 64 < 3)
		if (moove_get_z(&e->points, e, e->pos_x / 64, e->pos_y
					/ 64 - 1) == 1)
			e->pos_y += 4.0;
	if (e->axe >= 180 && e->axe <= 360 && (int)e->pos_y % 64 > 61)
		if (moove_get_z(&e->points, e, e->pos_x / 64, e->pos_y
					/ 64 + 1) == 1)
			e->pos_y -= 4.0;
	if (e->axe < 180 && e->axe > 0 && (int)e->pos_y % 64 > 61)
		if (moove_get_z(&e->points, e, e->pos_x / 64, e->pos_y
					/ 64 + 1) == 1)
			e->pos_y -= 4.0;
}

void	check_moove_back2(t_env *e)
{
	if (e->axe < 360 && e->axe > 180 && (int)e->pos_y % 64 > 61)
		if (moove_get_z(&e->points, e, e->pos_x / 64, e->pos_y
					/ 64 + 1) == 1)
			e->pos_y -= 4.0;
	if (e->axe >= 180 && e->axe <= 360 && (int)e->pos_y % 64 < 3)
		if (moove_get_z(&e->points, e, e->pos_x / 64, e->pos_y
					/ 64 - 1) == 1)
			e->pos_y += 4.0;
	if (e->axe < 180 && e->axe > 0 && (int)e->pos_y % 64 < 3)
		if (moove_get_z(&e->points, e, e->pos_x / 64, e->pos_y
					/ 64 - 1) == 1)
			e->pos_y += 4.0;
}
