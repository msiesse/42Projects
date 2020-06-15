/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 18:45:19 by msiesse           #+#    #+#             */
/*   Updated: 2020/01/04 19:03:24 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	fill_pixel(SDL_Renderer *renderer, int x, int y, t_color color)
{
	if (x >= W_WIN || y >= H_WIN)
		return ;
	SDL_SetRenderDrawColor(renderer, color.channels[R], color.channels[G]
		, color.channels[B], color.channels[A]);
	SDL_RenderDrawPoint(renderer, x, y);
}
