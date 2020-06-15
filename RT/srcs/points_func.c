/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:13:12 by msiesse           #+#    #+#             */
/*   Updated: 2020/01/27 15:26:13 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	copy_point(t_point *dst, t_point src)
{
	dst->x = src.x;
	dst->y = src.y;
	dst->z = src.z;
}

t_point	create_point(float x, float y, float z)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}
