/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:18:37 by msiesse           #+#    #+#             */
/*   Updated: 2020/02/09 22:03:42 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	free_scene(t_scene *scene)
{
	reinit_darr(&scene->objects, sizeof(t_object));
}

void	free_env(t_env *e)
{
	SDL_DestroyRenderer(e->renderer);
	SDL_DestroyWindow(e->win);
	SDL_Quit();
	free_scene(&e->scene);
}
