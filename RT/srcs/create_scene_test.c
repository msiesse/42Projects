/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_scene_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:55:25 by msiesse           #+#    #+#             */
/*   Updated: 2020/02/12 14:03:41 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

t_scene	create_scene_test(void)
{
	t_scene		scene;
	t_cam		cam;
	t_light		light;
	t_object	object;
	t_object	object_2;
	t_object	object_3;
	t_object	object_4;
	t_object	object_5;

	//cam options
	cam.pos.x = -0.6;
	cam.pos.y = 0;
	cam.pos.z = 0;
	cam.view.x = 1;
	cam.view.y = 0;
	cam.view.z = 0;

	//light options
	light.pos.x = -1;
	light.pos.y = 0.5;
	light.pos.z = 0.3;
	light.color.color = WHITE;

	//sphere options
	object.item.sphere.origin.x = 0;
	object.item.sphere.origin.y = 0;
	object.item.sphere.origin.z = 0;
	object.item.sphere.rayon = 0.05;
	object.item.sphere.rayon_square = pow(object.item.sphere.rayon, 2.0);
	object.color.color = 0xe5bbf0;
	object.type = SPHERE;

	//plan options
	object_2.item.plan.plan_point.x = 0;
	object_2.item.plan.plan_point.y = 0;
	object_2.item.plan.plan_point.z = -0.1;
	object_2.item.plan.normal = normalize_vect(create_vect(0.0, 0.0, -1.0));
	object_2.color.color = 0xc3e6cd;
	object_2.type = PLAN;

	object_5.item.plan.plan_point.x = 1;
	object_5.item.plan.plan_point.y = 0;
	object_5.item.plan.plan_point.z = 0;
	object_5.item.plan.normal = normalize_vect(create_vect(-1.0, 0.0, 0.0));
	object_5.color.color = 0xc8e8d1;
	object_5.type = PLAN;

	//cylinder options
	object_3.item.cylinder.origin = create_point(0, 0, 0);
	object_3.item.cylinder.direct = normalize_vect(create_vect(1.0, 1.0, 1.0));
	object_3.item.cylinder.rayon = 0.025;
	object_3.item.cylinder.rayon_square = 0.025 * 0.025;
	object_3.color.color = 0xa1cced;
	object_3.type = CYLINDER;

	//cone options
	object_4.item.cone.origin = create_point(-0.3, 0, 0);
	object_4.item.cone.direct = normalize_vect(create_vect(-1.0, -1.0, 1.0));
	object_4.item.cone.angle = 20;
	object_4.item.cone.cos2_angle = pow(cos(20 * (M_PI / 180.)), 2.0);
	object_4.color.color = 0xaaaaaa;
	object_4.type = CONE;

	//d_objects creation
	scene = init_scene();
	add_elem_darr(&scene.objects, &object);
	add_elem_darr(&scene.objects, &object_2);
	add_elem_darr(&scene.objects, &object_3);
	add_elem_darr(&scene.objects, &object_4);
	add_elem_darr(&scene.objects, &object_5);
	
	//scene creation
	scene.light = light;
	scene.cam = cam;
	translate_objects(&scene, &scene.objects);

	return (scene);
}
