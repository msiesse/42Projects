/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_func_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:37:32 by msiesse           #+#    #+#             */
/*   Updated: 2020/02/05 14:03:29 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

float	get_norm_vect(t_vect vect)
{
	float	norm;

	norm = sqrtf(vect.x * vect.x + vect.y * vect.y + vect.z * vect.z);
	return (norm);
}

float	get_norm_vect_square(t_vect vect)
{
	float	norm_square;

	norm_square = vect.x * vect.x + vect.y * vect.y + vect.z * vect.z;
	return (norm_square);
}

t_vect	normalize_vect(t_vect vect)
{
	t_vect	norm_vect;
	float	norm;

	norm = get_norm_vect(vect);
	norm_vect = scalar_vect(vect, 1.0 / norm);
	return (norm_vect);
}

int		get_sign_dot_product(t_vect a, t_vect b)
{
	int		sign_bit;
	int		sign;

	sign_bit = signbit(scalar_product(a, b));
	sign = (sign_bit ^ 1) - (sign_bit & 1);
	return (sign);
}

void	limit_vect(t_vect *a)
{
	float	min;

	min = (1.0 / sqrtf(3.0)) * SCALE;
	a->x = fmin(min, a->x);
	a->y = fmin(min, a->y);
	a->z = fmin(min, a->z);
}
