/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:40:29 by msiesse           #+#    #+#             */
/*   Updated: 2020/01/27 12:41:19 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_scene	init_scene(void)
{
	t_scene	scene;

	init_darr(&scene.objects, sizeof(t_object));
	return (scene);
}
