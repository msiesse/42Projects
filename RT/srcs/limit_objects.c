/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limit_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:57:56 by msiesse           #+#    #+#             */
/*   Updated: 2020/02/09 21:46:27 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	limit_type(t_object *object)
{
	if (object->type == SPHERE)
		limit_sphere(&(object->item.sphere));
	else if (object->type == PLAN)
		limit_plan(&(object->item.plan));
	else if (object->type == CYLINDER)
		limit_cylinder(&(object->item.cylinder));
	else
		limit_cone(&(object->item.cone));
}

void		limit_objects(t_scene *scene)
{
	int		i;
	float	tmp;

	i = 0;
	if ((tmp = get_norm_vect(scene->light.pos)) > SCALE)
		scene->light.pos = scalar_vect(scene->light.pos, SCALE / tmp);
	while (i < scene->objects.size)
	{
		limit_type(&(((t_object*)scene->objects.arr)[i]));
		i++;
	}
}
