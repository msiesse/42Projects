/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 10:56:13 by msiesse           #+#    #+#             */
/*   Updated: 2020/02/10 11:36:59 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	modif_keys(t_env *e)
{
	if (e->event.type == SDL_KEYDOWN)
	{
		if (e->event.key.keysym.sym < 128)
			e->keys[e->event.key.keysym.sym] = PRESSED;
		else if (e->event.key.keysym.sym > M_KEYS)
			e->keys[(e->event.key.keysym.sym ^ M_KEYS) + OFFSET] = PRESSED;
	}
	else if (e->event.type == SDL_KEYUP)
	{
		if (e->event.key.keysym.sym < 128)
			e->keys[e->event.key.keysym.sym] = RELEASED;
		else if (e->event.key.keysym.sym > M_KEYS)
			e->keys[(e->event.key.keysym.sym ^ M_KEYS) + OFFSET] = RELEASED;
	}
}

int			handler_event(t_env *e)
{
	if (e->modif != 42)
		e->modif = 0;
	SDL_WaitEvent(&(e->event));
	if (e->event.type == SDL_QUIT)
		return (1);
	modif_keys(e);
	if (e->keys[SDLK_ESCAPE])
		return (1);
	choose_object(e);
	if (e->keys[SDLK_SPACE])
	{
		e->select = NULL;
	}
	if (!e->select && move_cam(e))
		e->modif = 1;
	else if (e->select && move_select(e))
		e->modif = 1;
	if (e->modif)
		render_scene(e);
	return (0);
}
