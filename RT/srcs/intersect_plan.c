/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plan.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:22:29 by msiesse           #+#    #+#             */
/*   Updated: 2020/01/29 13:45:53 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

float	intersect_plan(t_ray ray, t_plan plan, t_point *hit)
{
	float	dist;
	t_vect	tmp_vect;
	float	scalar_point;
	float	scalar_plan;

	dist = DIST_MAX;
	tmp_vect = add_vect(plan.plan_point, scalar_vect(ray.origin, -1.0));
	scalar_point = scalar_product(tmp_vect, plan.normal);
	scalar_plan = scalar_product(ray.direction, plan.normal);
	if (fabs(scalar_plan) > 0.001)
	{
		dist = scalar_point / scalar_plan;
		if (dist < 0)
			dist = DIST_MAX;
		else if (hit)
			*hit = add_vect(ray.origin, scalar_vect(ray.direction, dist));
	}
	return (dist);
}
