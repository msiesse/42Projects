/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <ceaudouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 13:09:58 by msiesse           #+#    #+#             */
/*   Updated: 2019/09/16 12:18:17 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** function to exit the program and free everything we can
*/

void	good_exit(t_env *e, int id)
{
	int		i;

	i = 0;
	while (i < 7)
	{
		if (e->tex[i].img != NULL)
			mlx_destroy_image(e->m.mlx, e->tex[i].img);
		i++;
	}
	mlx_destroy_window(e->m.mlx, e->m.win);
	reinit_points(&e->points);
	exit(id);
}
