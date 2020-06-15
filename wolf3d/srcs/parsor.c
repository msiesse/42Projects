/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 09:40:39 by msiesse           #+#    #+#             */
/*   Updated: 2019/09/06 10:46:23 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		init_parsor(t_parsor *parsor)
{
	ft_bzero(parsor->nb, 16);
	parsor->index_nb = 0;
	parsor->cols = 0;
	parsor->lines = 0;
}

void		error_parsor(int err_id, t_points *points)
{
	reinit_dint(&points->x);
	reinit_dint(&points->y);
	reinit_dint(&points->z);
	if (err_id == ERR_NB_TOOBIG)
		ft_putendl_fd("Parsing error: Too big number", 2);
	else if (err_id == ERR_DIM_MAP)
		ft_putendl_fd("Parsing error: Dimensions aren't respected", 2);
	else if (err_id == ERR_CHAR)
		ft_putendl_fd("Parsing error: Forbidden char", 2);
	else if (err_id == ERR_TOOSMALL)
		ft_putendl_fd("Parsing error: Map too small", 2);
	else if (err_id == ERR_TOOBIG)
		ft_putendl_fd("Parsing error: Map too big", 2);
	else if (err_id == ERR_WALL)
		ft_putendl_fd("Parsing error: Wall not well placed", 2);
	else if (err_id == ERR_POS_BDR)
		ft_putendl_fd("Parsing error: Player is out of the map", 2);
	else if (err_id == ERR_POS_WALL)
		ft_putendl_fd("Parsing error: Player is in a wall", 2);
	exit(EXIT_FAILURE);
}

int			get_nb(const char *nb)
{
	if (nb[0] == 0)
		return (-1);
	else
		return (ft_atoi(nb));
}

static void	verif_bounds(t_env *e)
{
	int	pos;

	if (e->lines * 64.0 < e->pos_y || e->cols * 64.0 < e->pos_x)
		error_parsor(ERR_POS_BDR, &e->points);
	pos = ((int)(e->pos_y / 64.0) * e->cols + (int)(e->pos_x / 64.0));
	if (e->points.z.arr[pos] == 1)
		error_parsor(ERR_POS_WALL, &e->points);
}

void		w_parsor(const int fd, t_env *e)
{
	init_parsor(&e->parsor);
	init_points(&e->points);
	parsor_lcol(fd, e);
	parsor_map(fd, e);
	parsor_cam(fd, e);
	verif_bounds(e);
}
