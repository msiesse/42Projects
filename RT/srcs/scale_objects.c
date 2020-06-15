/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 14:12:55 by msiesse           #+#    #+#             */
/*   Updated: 2020/02/09 21:51:54 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

static float	get_max(t_object *object, float max)
{
	float	new_max;

	if (object->type == SPHERE)
		new_max = object->item.sphere.rayon;
	else if (object->type == CYLINDER)
		new_max = object->item.cylinder.rayon;
	else
		new_max = 0;
	if (new_max > max)
		return (new_max);
	return (max);
}

static void		scale_object_i(t_object *object, float ratio)
{
	t_point	*point;
	float	*p_r;
	float	*p_r_2;

	point = get_point_object(object);
	p_r = NULL;
	p_r_2 = NULL;
	if (object->type == SPHERE)
	{
		p_r = &(object->item.sphere.rayon);
		p_r_2 = &(object->item.sphere.rayon_square);
	}
	else if (object->type == CYLINDER)
	{
		p_r = &(object->item.cylinder.rayon);
		p_r_2 = &(object->item.cylinder.rayon_square);
	}
	*point = scalar_vect(*point, ratio);
	if (p_r)
		*p_r = *p_r * ratio;
	if (p_r_2)
		*p_r_2 = *p_r_2 * ratio * ratio;
}

void			scale_objects(t_scene *scene)
{
	float		max;
	float		ratio;
	t_object	*object;
	int			i;

	i = 0;
	max = 0;
	while (i < scene->objects.size)
	{
		object = &(((t_object*)scene->objects.arr)[i]);
		max = get_max(object, max);
		i++;
	}
	i = 0;
	ratio = SCALE / max;
	while (max != 0 && max < SCALE && i < scene->objects.size)
	{
		object = &(((t_object*)scene->objects.arr)[i]);
		scale_object_i(object, ratio);
		i++;
	}
	if (max != 0 && max < SCALE)
		scene->light.pos = scalar_vect(scene->light.pos, ratio);
}
