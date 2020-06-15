/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limit_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 12:07:43 by msiesse           #+#    #+#             */
/*   Updated: 2020/02/05 14:07:16 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	limit_sphere(t_sphere *sphere)
{
	float	tmp;

	limit_vect(&sphere->origin);
	tmp = get_norm_vect(sphere->origin);
	if (tmp > SCALE)
		sphere->origin = scalar_vect(sphere->origin, SCALE / tmp);
	if (sphere->rayon > SCALE)
		sphere->rayon *= (SCALE / sphere->rayon);
	else if (sphere->rayon < (1.0 / sqrtf(SCALE)))
		sphere->rayon *= ((1.0) / sqrtf(SCALE)) / sphere->rayon;
	sphere->rayon_square = sphere->rayon * sphere->rayon;
}
