/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 11:25:35 by msiesse           #+#    #+#             */
/*   Updated: 2019/08/26 11:27:04 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	error_thread_create(t_env *e)
{
	ft_putendl_fd("wolf3d: error creating thread", 2);
	mlx_destroy_window(e->m.mlx, e->m.win);
	exit(EXIT_FAILURE);
}

void	error_thread_join(t_env *e)
{
	ft_putendl_fd("wolf3d: error joining threads", 2);
	mlx_destroy_window(e->m.mlx, e->m.win);
	exit(EXIT_FAILURE);
}
