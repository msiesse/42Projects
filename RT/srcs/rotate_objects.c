/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:26:56 by msiesse           #+#    #+#             */
/*   Updated: 2020/02/09 21:48:54 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	change_base_point(t_mat rot[3][3], t_point *point)
{
	if (point)
		product_mat_vect(rot, *point, point);
}

void	rotate_objects(t_scene *scene, t_dobject *objects)
{
	int			i;
	t_object	*object;
	t_point		*point;
	t_vect		*vect;

	i = 0;
	while (i < objects->size)
	{
		object = &(((t_object*)objects->arr)[i]);
		point = get_point_object(object);
		vect = get_vect_object(object);
		change_base_point(scene->rot, point);
		change_base_point(scene->rot, vect);
		i++;
	}
	change_base_point(scene->rot, &scene->light.pos);
}

void	rotate_objects_x(t_scene *scene, t_dobject *objects, int8_t sign)
{
	int			i;
	t_object	*object;
	t_point		*point;
	t_vect		*vect;

	i = 0;
	get_rot_x(scene->rot_x, sign * ROT);
	while (i < objects->size)
	{
		object = &(((t_object*)objects->arr)[i]);
		point = get_point_object(object);
		vect = get_vect_object(object);
		change_base_point(scene->rot_x, point);
		change_base_point(scene->rot_x, vect);
		i++;
	}
	change_base_point(scene->rot_x, &scene->light.pos);
}

void	rotate_objects_y(t_scene *scene, t_dobject *objects, int8_t sign)
{
	int			i;
	t_object	*object;
	t_point		*point;
	t_vect		*vect;

	i = 0;
	get_rot_y(scene->rot_y, sign * ROT);
	while (i < objects->size)
	{
		object = &(((t_object*)objects->arr)[i]);
		point = get_point_object(object);
		vect = get_vect_object(object);
		change_base_point(scene->rot_y, point);
		change_base_point(scene->rot_y, vect);
		i++;
	}
	change_base_point(scene->rot_y, &scene->light.pos);
}

void	rotate_objects_z(t_scene *scene, t_dobject *objects, int8_t sign)
{
	int			i;
	t_object	*object;
	t_point		*point;
	t_vect		*vect;

	i = 0;
	get_rot_z(scene->rot_z, sign * ROT);
	while (i < objects->size)
	{
		object = &(((t_object*)objects->arr)[i]);
		point = get_point_object(object);
		vect = get_vect_object(object);
		change_base_point(scene->rot_z, point);
		change_base_point(scene->rot_z, vect);
		i++;
	}
	change_base_point(scene->rot_z, &scene->light.pos);
}
