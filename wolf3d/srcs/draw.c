/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:30:57 by msiesse           #+#    #+#             */
/*   Updated: 2019/09/05 17:04:00 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		distortion(t_env *e)
{
	e->corr_dist = round(e->dist * cos((e->i * e->radian)));
	e->wall = (64.0 / (double)e->corr_dist * 277.0 * 3.0);
	e->x1 = e->x;
	e->y1 = ((int)round(((double)H_IMG / 2.0) - (e->wall / 2.0)));
	e->x2 = e->x;
	e->y2 = (int)round(((double)H_IMG / 2.0) + (e->wall / 2.0));
}

static void	*ft_draw_th(void *e)
{
	t_env		v_cpy;
	t_env		*cpy;

	v_cpy = *((t_env*)e);
	cpy = &v_cpy;
	if ((cpy->n_th = check_pthread_id(cpy, pthread_self())) == -1)
		return (NULL);
	init_draw(cpy, cpy->n_th);
	while (cpy->x < (((cpy->n_th + 1) * W_IMG) / N_THREAD))
	{
		if (cpy->view >= 360.0)
			cpy->view = fmod(cpy->view, 360.0);
		if (cpy->view < 0)
			cpy->view = 360 - fabs(cpy->view);
		cpy->y1 = H_MAP / 2;
		cpy->x1 = W_MAP / 2;
		cpy->t_x1 = cpy->pos_x;
		cpy->t_y1 = cpy->pos_y;
		draw2(cpy);
		cpy->x++;
		cpy->view -= 60.0 / (double)W_IMG;
		cpy->i -= 60.0 / (double)W_IMG;
	}
	return (NULL);
}

static void	ft_draw_thread(t_env *e)
{
	int		i;

	i = 0;
	while (i < N_THREAD)
	{
		if (pthread_create(&e->thread[i], NULL, ft_draw_th, e))
			error_thread_create(e);
		i++;
	}
}

static void	ft_draw_join(t_env *e)
{
	int		i;

	i = 0;
	while (i < N_THREAD)
	{
		if (pthread_join(e->thread[i], NULL))
			error_thread_join(e);
		i++;
	}
}

void		ft_draw(t_env *e)
{
	ft_draw_thread(e);
	ft_draw_join(e);
}
