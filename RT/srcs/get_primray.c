/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_primray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:48:16 by msiesse           #+#    #+#             */
/*   Updated: 2020/02/09 21:42:22 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

void	get_primray(int x, int y, t_scene *scene)
{
	float	dist;
	float	angle;

	angle = FOV * (M_PI / 180.0);
	dist = ((float)W_WIN / 2.0) / tan(angle / 2.0);
	scene->prim_ray.origin = scene->cam.pos;
	scene->prim_ray.direction.x = dist;
	scene->prim_ray.direction.y = (float)W_WIN / 2.0 - x;
	scene->prim_ray.direction.z = (float)H_WIN / 2.0 - y;
	scene->prim_ray.direction = normalize_vect(scene->prim_ray.direction);
}
