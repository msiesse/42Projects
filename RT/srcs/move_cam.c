/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 09:16:25 by msiesse           #+#    #+#             */
/*   Updated: 2020/02/09 21:52:46 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	rotate_cam(t_env *e)
{
	void	(*fptr)(t_scene*, t_dobject*, int8_t);

	if (e->keys[SDLK_x])
		fptr = &rotate_objects_x;
	else if (e->keys[SDLK_y])
		fptr = &rotate_objects_y;
	else if (e->keys[SDLK_z])
		fptr = &rotate_objects_z;
	else
		return (0);
	if (e->keys[(SDLK_UP ^ M_KEYS) + OFFSET])
		fptr(&e->scene, &e->scene.objects, 1);
	else if (e->keys[(SDLK_DOWN ^ M_KEYS) + OFFSET])
		fptr(&e->scene, &e->scene.objects, -1);
	else
		return (0);
	return (1);
}

int			move_cam(t_env *e)
{
	if (rotate_cam(e))
		return (1);
	if (e->keys[(SDLK_LEFT ^ M_KEYS) + OFFSET])
		e->scene.cam.pos = add_vect(e->scene.cam.pos, create_vect(0, 1e7, 0));
	else if (e->keys[(SDLK_RIGHT ^ M_KEYS) + OFFSET])
		e->scene.cam.pos = add_vect(e->scene.cam.pos, create_vect(0, -1e7, 0));
	else if (e->keys[(SDLK_UP ^ M_KEYS) + OFFSET]
				&& e->keys[(SDLK_LGUI ^ M_KEYS) + OFFSET])
		e->scene.cam.pos = add_vect(e->scene.cam.pos, create_vect(0, 0, 1e7));
	else if (e->keys[(SDLK_DOWN ^ M_KEYS) + OFFSET]
				&& e->keys[(SDLK_LGUI ^ M_KEYS) + OFFSET])
		e->scene.cam.pos = add_vect(e->scene.cam.pos, create_vect(0, 0, -1e7));
	else if (e->keys[(SDLK_UP ^ M_KEYS) + OFFSET])
		e->scene.cam.pos = add_vect(e->scene.cam.pos, create_vect(1e7, 0, 0));
	else if (e->keys[(SDLK_DOWN ^ M_KEYS) + OFFSET])
		e->scene.cam.pos = add_vect(e->scene.cam.pos, create_vect(-1e7, 0, 0));
	else
		return (0);
	return (1);
}
