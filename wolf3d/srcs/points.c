/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:47:39 by msiesse           #+#    #+#             */
/*   Updated: 2019/08/28 14:48:13 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_points(t_points *points)
{
	init_dint(&points->x);
	init_dint(&points->y);
	init_dint(&points->z);
}

void	reinit_points(t_points *points)
{
	reinit_dint(&points->x);
	reinit_dint(&points->y);
	reinit_dint(&points->z);
}

int		get_z(t_points *points, t_env *e)
{
	int	i;

	i = 0;
	while (points->y.arr[i] != e->yold && i < points->y.size)
		i += e->cols;
	while (points->x.arr[i] != e->xold && i < points->x.size)
		i++;
	if (points->x.arr[i] == e->xold && points->y.arr[i] == e->yold)
		return (points->z.arr[i]);
	else
		return (0);
}

int		get_bz(t_points *points, t_env *e)
{
	int	i;

	i = 0;
	while (points->y.arr[i] != e->byold && i < points->y.size)
		i += e->cols;
	while (points->x.arr[i] != e->bxold && i < points->x.size)
		i++;
	if (points->x.arr[i] == e->bxold && points->y.arr[i] == e->byold)
		return (points->z.arr[i]);
	else
		return (0);
}

int		moove_get_z(t_points *points, t_env *e, int x, int y)
{
	int	i;

	i = 0;
	if (y >= e->lines || x >= e->cols || x < 0 || y < 0)
		return (0);
	while (points->y.arr[i] != y && i < points->y.size)
		i += e->cols;
	while (points->x.arr[i] != x && i < points->x.size)
		i++;
	if (points->x.arr[i] == x && points->y.arr[i] == y)
		return (points->z.arr[i]);
	else
		return (0);
}
