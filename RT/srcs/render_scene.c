/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 09:24:12 by msiesse           #+#    #+#             */
/*   Updated: 2020/02/06 15:05:45 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_color	render_shadow_ray(t_object *object, t_scene *scene)
{
	t_color	color_pixel;

	scene->shadow_ray = get_shadow_ray(scene, scene->p_hit, scene->light);
	scene->is_in_shadow = intersect_shadow(object, scene, scene->shadow_ray
		, scene->objects);
	color_pixel = get_color_pixel(scene, object, scene->shadow_ray
		, scene->n_hit);
	return (color_pixel);
}

void			render_scene(t_env *e)
{
	int			x;
	int			y;
	t_color		color_pixel;
	t_object	*object;

	x = -1;
	while (++x < W_WIN)
	{
		y = -1;
		while (++y < H_WIN)
		{
			get_primray(x, y, &e->scene);
			object = intersect_prim(&e->scene, e->scene.prim_ray
				, e->scene.objects, &e->scene.p_hit);
			if (object)
				color_pixel = render_shadow_ray(object, &e->scene);
			else
				color_pixel.color = 0;
			fill_pixel(e->renderer, x, y, color_pixel);
		}
	}
	SDL_RenderPresent(e->renderer);
}
