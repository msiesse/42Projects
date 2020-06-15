/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <ceaudouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:49:11 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/09/16 12:11:50 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	env_init(t_env *e)
{
	e->radian = M_PI / 180;
	e->view = e->axe;
	e->rain = 0;
	e->speed = 1;
	if (e->pos_x == e->pos_y)
		e->pos_x += 0.01;
	if ((int)e->pos_x % 64 == 0)
		e->pos_x++;
	if ((int)e->pos_y % 64 == 0)
		e->pos_y++;
	e->sensi = 2;
	ft_bzero(e->tex, sizeof(t_tex*) * 9);
}
