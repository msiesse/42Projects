/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 11:01:54 by msiesse           #+#    #+#             */
/*   Updated: 2019/08/26 11:03:52 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

double		ceil_func(double num, double ceil)
{
	if (num > ceil)
		return (ceil);
	return (num);
}