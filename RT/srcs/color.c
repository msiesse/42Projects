/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 10:15:25 by msiesse           #+#    #+#             */
/*   Updated: 2020/02/07 10:20:03 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

t_color	add_colors(t_color color_a, t_color color_b)
{
	t_color	new;

	new.channels[R] = fmin(255, color_a.channels[R] + color_b.channels[R]);
	new.channels[G] = fmin(255, color_a.channels[G] + color_b.channels[G]);
	new.channels[B] = fmin(255, color_a.channels[B] + color_b.channels[B]);
	new.channels[A] = fmin(255, color_a.channels[A] + color_b.channels[A]);
	return (new);
}
