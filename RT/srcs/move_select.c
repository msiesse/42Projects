/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_select.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 15:25:34 by msiesse           #+#    #+#             */
/*   Updated: 2020/02/09 21:52:23 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static uint8_t	translate_select(t_env *e)
{
	t_point	*point;

	point = get_point_object(e->select);
	if (e->keys[(SDLK_LEFT ^ M_KEYS) + OFFSET])
		*point = add_vect(*point, create_vect(0, 1e7, 0));
	else if (e->keys[(SDLK_RIGHT ^ M_KEYS) + OFFSET])
		*point = add_vect(*point, create_vect(0, -1e7, 0));
	else if (e->keys[(SDLK_UP ^ M_KEYS) + OFFSET]
				&& e->keys[(SDLK_LGUI ^ M_KEYS) + OFFSET])
		*point = add_vect(*point, create_vect(0, 0, 1e7));
	else if (e->keys[(SDLK_DOWN ^ M_KEYS) + OFFSET]
				&& e->keys[(SDLK_LGUI ^ M_KEYS) + OFFSET])
		*point = add_vect(*point, create_vect(0, 0, -1e7));
	else if (e->keys[(SDLK_UP ^ M_KEYS) + OFFSET])
		*point = add_vect(*point, create_vect(1e7, 0, 0));
	else if (e->keys[(SDLK_DOWN ^ M_KEYS) + OFFSET])
		*point = add_vect(*point, create_vect(-1e7, 0, 0));
	else
		return (0);
	return (1);
}

static uint8_t	rotate_select(t_env *e)
{
	t_mat	rot[3][3];
	uint8_t	axe;
	t_vect	*vect;

	vect = get_vect_object(e->select);
	if (e->keys[SDLK_x])
		axe = X;
	else if (e->keys[SDLK_y])
		axe = Y;
	else if (e->keys[SDLK_z])
		axe = Z;
	else
		return (0);
	if (e->keys[(SDLK_UP ^ M_KEYS) + OFFSET])
		get_rot(rot, ROT, axe);
	else if (e->keys[(SDLK_DOWN ^ M_KEYS) + OFFSET])
		get_rot(rot, -ROT, axe);
	else
		return (0);
	if (vect)
		change_base_point(rot, vect);
	else
		return (0);
	return (1);
}

uint8_t			move_select(t_env *e)
{
	if (rotate_select(e))
		return (1);
	if (translate_select(e))
		return (1);
	return (0);
}
