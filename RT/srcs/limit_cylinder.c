/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limit_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 12:16:24 by msiesse           #+#    #+#             */
/*   Updated: 2020/02/05 14:06:48 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	limit_cylinder(t_cylinder *cylinder)
{
	float	tmp;

	limit_vect(&cylinder->origin);
	tmp = get_norm_vect(cylinder->origin);
	if (tmp > SCALE)
		cylinder->origin = scalar_vect(cylinder->origin, SCALE / tmp);
	if (cylinder->rayon > SCALE)
		cylinder->rayon *= SCALE / cylinder->rayon;
	else if (cylinder->rayon < (1.0 / sqrtf(SCALE)))
		cylinder->rayon *= (1.0 / sqrtf(SCALE)) / cylinder->rayon;
	cylinder->rayon_square = cylinder->rayon * cylinder->rayon;
}
