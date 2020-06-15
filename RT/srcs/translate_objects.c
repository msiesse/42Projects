/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_objects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:22:01 by msiesse           #+#    #+#             */
/*   Updated: 2020/01/31 21:42:49 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	move_point(t_point *point, t_point base)
{
	point->x -= base.x;
	point->y -= base.y;
	point->z -= base.z;
}

void	translate_objects(t_scene *scene, t_dobject *objects)
{
	int			i;
	t_point		base;
	t_object	*object;

	i = 0;
	base = scene->cam.pos;
	while (i < objects->size)
	{
		object = &(((t_object*)objects->arr)[i]);
		if (object->type & SPHERE)
			move_point(&(object->item.sphere.origin), base);
		else if (object->type & PLAN)
			move_point(&(object->item.plan.plan_point), base);
		else if (object->type & CYLINDER)
			move_point(&(object->item.cylinder.origin), base);
		else
			move_point(&(object->item.cone.origin), base);
		i++;
	}
	move_point(&scene->cam.pos, base);
	move_point(&scene->light.pos, base);
}
