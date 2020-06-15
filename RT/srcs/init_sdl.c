/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 21:56:08 by msiesse           #+#    #+#             */
/*   Updated: 2020/02/09 22:16:01 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_sdl(t_env *e)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		error_exit(ERR_INIT_SDL, e);
	e->win = SDL_CreateWindow("RTv1 by OSS 142", SDL_WINDOWPOS_CENTERED
		, SDL_WINDOWPOS_CENTERED, W_WIN, H_WIN, SDL_WINDOW_SHOWN);
	if (e->win == NULL)
		error_exit(ERR_CREATE_WINDOW, e);
	e->renderer = SDL_CreateRenderer(e->win, -1, 0);
	if (e->renderer == NULL)
		error_exit(ERR_CREATE_RENDERER, e);
}
