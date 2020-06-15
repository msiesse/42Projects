/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:33:49 by msiesse           #+#    #+#             */
/*   Updated: 2020/02/12 13:56:54 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float			intersect_object(t_scene *scene, t_ray ray, t_object object
					, t_point *hit)
{
	float	dist;

	dist = DIST_MAX;
	if ((object.type & SPHERE))
		dist = intersect_sphere(ray, object.item.sphere, hit);
	else if ((object.type & PLAN))
		dist = intersect_plan(ray, object.item.plan, hit);
	else if ((object.type & CYLINDER))
	{
		dist = intersect_cylinder(&(scene->linecyl), ray, object.item.cylinder
			, hit);
	}
	else
	{
		dist = intersect_cone(&(scene->linecone), ray, object.item.cone
			, hit);
	}
	return (dist);
}

static void		init_intersect(t_scene *scene)
{
	scene->p_hit = create_vect(DIST_MAX, DIST_MAX, DIST_MAX);
	scene->n_hit = create_vect(DIST_MAX, DIST_MAX, DIST_MAX);
}

t_object		*intersect_prim(t_scene *scene, t_ray prim_ray
			, t_dobject objects, t_point *p_hit)
{
	float		min_dist;
	float		dist;
	int			i;
	t_point		hit;
	t_object	*object;

	min_dist = DIST_MAX;
	object = NULL;
	i = -1;
	init_intersect(scene);
	while (++i < objects.size)
	{
		dist = intersect_object(scene, prim_ray, ((t_object*)objects.arr)[i]
			, &hit);
		if (dist < min_dist)
		{
			min_dist = dist;
			if (p_hit)
				*p_hit = hit;
			object = &(((t_object*)objects.arr)[i]);
		}
	}
	if (object && p_hit)
		scene->n_hit = get_nhit(scene, *p_hit, object);
	return (object);
}

uint8_t			intersect_shadow(t_object *object, t_scene *scene
		, t_ray shadow_ray, t_dobject objects)
{
	uint8_t	is_in_shadow;
	uint8_t	i;
	float	dist;

	is_in_shadow = 0;
	i = 0;
	while (i < objects.size)
	{
		if (((object != &((t_object*)scene->objects.arr)[i])
			|| object->type == CONE) && (dist = intersect_object(scene
			, shadow_ray, ((t_object*)objects.arr)[i], NULL)) < DIST_MAX)
		{
			if (dist / scene->light_dist < 0.995)
			{
				is_in_shadow = 1;
				break ;
			}
		}
		i++;
	}
	return (is_in_shadow);
}
