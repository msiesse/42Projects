/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_object.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 11:46:12 by msiesse           #+#    #+#             */
/*   Updated: 2020/02/06 12:01:55 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_point	*get_point_object(t_object *object)
{
	t_point	*point;

	if (object->type == SPHERE)
		point = &object->item.sphere.origin;
	else if (object->type == PLAN)
		point = &object->item.plan.plan_point;
	else if (object->type == CYLINDER)
		point = &object->item.cylinder.origin;
	else
		point = &object->item.cone.origin;
	return (point);
}

t_vect	*get_vect_object(t_object *object)
{
	t_vect	*vect;

	if (object->type == PLAN)
		vect = &object->item.plan.normal;
	else if (object->type == CYLINDER)
		vect = &object->item.cylinder.direct;
	else if (object->type == CONE)
		vect = &object->item.cone.direct;
	else
		vect = NULL;
	return (vect);
}
