/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 21:08:51 by msiesse           #+#    #+#             */
/*   Updated: 2020/02/12 13:59:16 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

static void		get_vars_linecone(t_linecone *linecone, t_cone cone, t_ray ray)
{
	t_vect	bo;

	linecone->n_dot_a = scalar_product(ray.direction, cone.direct);
	bo = add_vect(ray.origin, scalar_vect(cone.origin, -1.0));
	linecone->bo_dot_a = scalar_product(bo, cone.direct);
	linecone->n_dot_bo = scalar_product(ray.direction, bo);
	linecone->norm2_bo = get_norm_vect_square(bo);
}

static float	get_dist_quadratic(float a, float b, float s_delta)
{
	float	dist;
	float	dist_p;
	float	dist_n;

	dist_n = (-b - s_delta) / (2.0 * a);
	dist_p = (-b + s_delta) / (2.0 * a);
	if (a < 0)
		dist = dist_p;
	else
		dist = dist_n;
	if (dist < 0)
	{
		if (a < 0)
			dist = dist_n;
		else
			dist = dist_p;
	}
	if (dist < 0)
		dist = DIST_MAX;
	return (dist);
}

float			intersect_cone(t_linecone *linecone, t_ray ray, t_cone cone
			, t_point *hit)
{
	float	delta;
	float	a;
	float	b;
	float	c;
	float	dist;

	dist = DIST_MAX;
	get_vars_linecone(linecone, cone, ray);
	a = pow(linecone->n_dot_a, 2.0) - cone.cos2_angle;
	if (fabs(a) < 1e-4)
		return (dist);
	b = 2 * (linecone->n_dot_a * linecone->bo_dot_a - linecone->n_dot_bo
		* cone.cos2_angle);
	c = pow(linecone->bo_dot_a, 2.0) - linecone->norm2_bo * cone.cos2_angle;
	delta = get_delta(a, b, c);
	if (delta > 1e-4)
	{
		dist = get_dist_quadratic(a, b, sqrtf(delta));
		if (hit && dist != DIST_MAX)
			*hit = add_vect(ray.origin, scalar_vect(ray.direction, dist));
	}
	return (dist);
}
