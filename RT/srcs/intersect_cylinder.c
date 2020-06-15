/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:19:48 by msiesse           #+#    #+#             */
/*   Updated: 2020/02/12 13:59:21 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

static void	initialize_linecyl(t_linecyl *vars, t_ray ray, t_cylinder cylinder)
{
	vars->n_cross_a = cross_product(ray.direction, cylinder.direct);
	vars->norm_ncrossa = get_norm_vect_square(vars->n_cross_a);
	vars->base = add_vect(cylinder.origin, scalar_vect(ray.origin, -1.0));
	vars->b_cross_a = cross_product(vars->base, cylinder.direct);
	vars->b_dot_a = scalar_product(vars->base, cylinder.direct);
	vars->dot_doublecross = scalar_product(vars->n_cross_a, vars->b_cross_a);
}

float		intersect_cylinder(t_linecyl *vars, t_ray ray, t_cylinder cylinder
				, t_point *hit)
{
	float	dist;
	float	delta;
	float	sqrt_delta;

	dist = DIST_MAX;
	initialize_linecyl(vars, ray, cylinder);
	if (vars->norm_ncrossa < 0.001)
		return (dist);
	delta = vars->norm_ncrossa * cylinder.rayon_square
			- powf(scalar_product(vars->base, vars->n_cross_a), 2.0);
	sqrt_delta = sqrtf(delta);
	if (delta > 0.001)
	{
		dist = (vars->dot_doublecross - sqrt_delta) / vars->norm_ncrossa;
		if (dist < 0)
			dist = (vars->dot_doublecross + sqrt_delta) / vars->norm_ncrossa;
		if (dist < 0)
			dist = DIST_MAX;
		else if (hit)
			*hit = add_vect(ray.origin, scalar_vect(ray.direction, dist));
	}
	return (dist);
}
