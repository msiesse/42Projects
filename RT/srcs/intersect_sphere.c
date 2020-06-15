/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:27:16 by msiesse           #+#    #+#             */
/*   Updated: 2020/02/12 13:59:28 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <float.h>
#include <math.h>

float	intersect_sphere(t_ray ray, t_sphere sphere, t_point *hit)
{
	float	dist;
	float	delta;
	float	scalar_sphere;
	float	scalar_norm;
	t_vect	tmp_vect;

	dist = DIST_MAX;
	tmp_vect = add_vect(ray.origin, scalar_vect(sphere.origin, -1.0));
	scalar_sphere = scalar_product(ray.direction, tmp_vect);
	scalar_norm = get_norm_vect_square(tmp_vect) - sphere.rayon_square;
	delta = scalar_sphere * scalar_sphere - scalar_norm;
	if (delta >= 0.001)
	{
		dist = -scalar_sphere - sqrtf(delta);
		if (dist < 0)
			dist = -scalar_sphere + sqrtf(delta);
		if (dist < 0)
			dist = DIST_MAX;
		else if (hit)
			*hit = add_vect(ray.origin, scalar_vect(ray.direction, dist));
	}
	return (dist);
}
