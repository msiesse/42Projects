/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limit_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 13:30:34 by msiesse           #+#    #+#             */
/*   Updated: 2020/02/05 14:01:04 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	limit_cone(t_cone *cone)
{
	float	tmp;

	limit_vect(&cone->origin);
	tmp = get_norm_vect(cone->origin);
	if (tmp > SCALE)
		cone->origin = scalar_vect(cone->origin, SCALE / tmp);
}
