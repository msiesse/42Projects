/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:02:21 by msiesse           #+#    #+#             */
/*   Updated: 2020/02/12 14:00:42 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

t_ray	get_shadow_ray(t_scene *scene, t_point p_hit, t_light light)
{
	t_ray	shadow_ray;
	float	bias;

	shadow_ray.direction = add_vect(light.pos, scalar_vect(p_hit, -1.0));
	scene->light_dist = get_norm_vect(shadow_ray.direction);
	shadow_ray.direction = normalize_vect(shadow_ray.direction);
	bias = 1e6;
	shadow_ray.origin = add_vect(p_hit
			, scalar_vect(scene->n_hit, bias));
	return (shadow_ray);
}
