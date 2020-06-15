/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gere_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <ceaudouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 17:07:22 by msiesse           #+#    #+#             */
/*   Updated: 2019/09/16 12:16:03 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		gere_key(int key, t_env *e)
{
	if (key == ESC)
		good_exit(e, 0);
	if (key == SHFT)
		e->speed = 0;
	if (key == UP)
		e->forward = 1;
	if (key == DOWN)
		e->backward = 1;
	if (key == P)
		e->rain ^= 1;
	if (key == LEFT)
		e->left = 1;
	if (key == RIGHT)
		e->right = 1;
	if (key == PGUP)
		e->sensi = ceil_func(e->sensi + 1.0, 20.0);
	if (key == PGDW)
		e->sensi = -ceil_func(-(e->sensi - 1), -1.0);
	mlx_clear_window(e->m.mlx, e->m.win);
	ft_expose(e);
	return (0);
}

int		release_key(int key, t_env *e)
{
	if (key == UP)
		e->forward = 0;
	if (key == DOWN)
		e->backward = 0;
	if (key == RIGHT)
		e->right = 0;
	if (key == LEFT)
		e->left = 0;
	if (key == SHFT)
		e->speed = 1;
	return (0);
}

int		do_exit(t_env *e)
{
	good_exit(e, 0);
	return (0);
}
