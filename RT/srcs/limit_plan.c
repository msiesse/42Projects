/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limit_plan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 12:13:56 by msiesse           #+#    #+#             */
/*   Updated: 2020/02/05 14:06:02 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	limit_plan(t_plan *plan)
{
	float	tmp;

	limit_vect(&plan->plan_point);
	tmp = get_norm_vect(plan->plan_point);
	if (tmp > SCALE)
		plan->plan_point = scalar_vect(plan->plan_point, SCALE / tmp);
}
