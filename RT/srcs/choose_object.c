/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 15:06:01 by msiesse           #+#    #+#             */
/*   Updated: 2020/02/06 15:32:14 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

uint8_t	choose_object(t_env *e)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (e->event.type == SDL_MOUSEBUTTONDOWN &&
			e->event.button.button == SDL_BUTTON_LEFT)
	{
		SDL_GetMouseState(&x, &y);
		get_primray(x, y, &e->scene);
		e->select = intersect_prim(&e->scene, e->scene.prim_ray
			, e->scene.objects, NULL);
		return (1);
	}
	return (0);
}
