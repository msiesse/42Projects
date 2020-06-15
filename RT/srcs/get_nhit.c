/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nhit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:55:32 by msiesse           #+#    #+#             */
/*   Updated: 2020/02/12 13:24:56 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

static t_vect	get_nhit_cylinder(t_point p_hit, t_cylinder cylinder)
{
	t_vect	n_hit;
	t_vect	tmp_vect;
	t_vect	p_b;
	float	dot_k;

	p_b = add_vect(p_hit, scalar_vect(cylinder.origin, -1.0));
	dot_k = scalar_product(cylinder.direct, p_b);
	tmp_vect = scalar_vect(cylinder.direct, -dot_k);
	n_hit = add_vect(p_b, tmp_vect);
	n_hit = scalar_vect(n_hit, 1.0 / cylinder.rayon);
	n_hit = normalize_vect(n_hit);
	return (n_hit);
}

static t_vect	get_nhit_cone(t_point p_hit, t_cone cone)
{
	t_vect	n_hit;
	t_point	center;
	float	d_bp;
	float	d_bb;
	t_vect	tmp_vect;

	d_bp = get_norm_vect(add_vect(p_hit, scalar_vect(cone.origin, -1.0)));
	d_bb = d_bp / cos(cone.angle * (M_PI / 180.0));
	tmp_vect = scalar_vect(cone.direct, d_bb
		* get_sign_dot_product(add_vect(p_hit
		, scalar_vect(cone.origin, -1.0)), cone.direct));
	center = add_vect(cone.origin, tmp_vect);
	n_hit = normalize_vect(add_vect(p_hit, scalar_vect(center, -1.0)));
	return (n_hit);
}

t_vect			get_nhit(t_scene *scene, t_point p_hit, t_object *object)
{
	t_vect	n_hit;

	if (object->type == SPHERE)
	{
		n_hit = normalize_vect(add_vect(p_hit
			, scalar_vect(object->item.sphere.origin, -1.0)));
	}
	else if (object->type == PLAN)
		n_hit = object->item.plan.normal;
	else if (object->type == CYLINDER)
		n_hit = get_nhit_cylinder(p_hit, object->item.cylinder);
	else
		n_hit = get_nhit_cone(p_hit, object->item.cone);
	if (scalar_product(n_hit, scene->prim_ray.direction) > 0
		&& object->type != PLAN)
		n_hit = create_vect(0, 0, 0);
	return (n_hit);
}
