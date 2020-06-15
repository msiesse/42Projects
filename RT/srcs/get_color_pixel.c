/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_pixel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:42:36 by msiesse           #+#    #+#             */
/*   Updated: 2020/02/12 13:43:00 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

t_color			k_color(t_color color, float k)
{
	t_color	new_color;

	new_color = color;
	new_color.channels[R] = (int)(fmin(255, (float)new_color.channels[R] * k));
	new_color.channels[G] = (int)(fmin(255, (float)new_color.channels[G] * k));
	new_color.channels[B] = (int)(fmin(255, (float)new_color.channels[B] * k));
	new_color.channels[A] = (int)((float)new_color.channels[A] * k);
	return (new_color);
}

static t_vect	get_ideal_reflect(t_vect n_hit, t_vect l_direct)
{
	t_vect	coeff_r;

	coeff_r = scalar_vect(n_hit, 2.0 * scalar_product(n_hit, l_direct));
	coeff_r = add_vect(coeff_r, scalar_vect(l_direct, -1.0));
	return (coeff_r);
}

static t_color	get_diffuse(t_object *object, t_vect n_hit, t_ray shadow_ray)
{
	t_color	diffuse;
	float	abs_scalar;

	if (object->type == PLAN)
		abs_scalar = fabs(scalar_product(n_hit, shadow_ray.direction));
	else
		abs_scalar = fmax(0, scalar_product(n_hit, shadow_ray.direction))
			* 1.5;
	diffuse = k_color(object->color, abs_scalar);
	return (diffuse);
}

static t_color	get_specular(t_scene *scene, t_vect coeff_r, t_ray shadow_ray)
{
	t_color	specular;
	float	abs_scalar;

	abs_scalar = pow(fmax(0, scalar_product(coeff_r, shadow_ray.direction))
		, N);
	specular = k_color(scene->light.color, abs_scalar);
	return (specular);
}

t_color			get_color_pixel(t_scene *scene, t_object *object
						, t_ray shadow_ray, t_vect n_hit)
{
	t_color	diffuse;
	t_color	specular;
	t_color	color;
	t_vect	coeff_r;

	color.color = 0;
	if (scene->is_in_shadow)
		return (color);
	else
	{
		if ((scalar_product(n_hit, shadow_ray.direction)
				* scalar_product(n_hit, scene->prim_ray.direction)) > 0)
			return (color);
		diffuse = get_diffuse(object, n_hit, shadow_ray);
		coeff_r = get_ideal_reflect(n_hit, scene->shadow_ray.direction);
		specular = get_specular(scene, coeff_r, shadow_ray);
		color = add_colors(k_color(diffuse, KD), k_color(specular, KS));
	}
	return (color);
}
