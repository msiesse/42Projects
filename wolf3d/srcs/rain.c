/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rain.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 12:22:36 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/08/28 10:23:00 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "stdlib.h"

void	rain(t_env *e)
{
	e->rand = 100;
	while (e->rand > 0)
	{
		e->x1 = rand() % W_IMG;
		e->y1 = rand() % H_IMG;
		e->y2 = e->y1 + rand() % 15;
		e->x2 = e->x1;
		while (e->y1 < e->y2)
		{
			fill_pixel(e->m.data, e->x1, e->y1, BLUE);
			e->y1++;
		}
		e->rand--;
	}
}
