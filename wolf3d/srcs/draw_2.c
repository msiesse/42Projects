/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 11:35:56 by msiesse           #+#    #+#             */
/*   Updated: 2019/09/05 17:04:30 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_draw(t_env *e, int n_th)
{
	e->x = W_IMG / N_THREAD * n_th;
	e->view = e->axe + 30 - (W_IMG / N_THREAD * n_th) * (60.0 / W_IMG);
	e->i = 30.0 - (W_IMG / N_THREAD * n_th) * (60.0 / W_IMG);
}

int		check_pthread_id(t_env *e, pthread_t id)
{
	int	i;

	i = 0;
	while (i < N_THREAD)
	{
		if (e->thread[i] == id)
			return (i);
		i++;
	}
	return (-1);
}

void	draw2(t_env *cpy)
{
	search_walls(cpy);
	ft_bresenham(cpy);
	distortion(cpy);
	draw_col(cpy);
}
