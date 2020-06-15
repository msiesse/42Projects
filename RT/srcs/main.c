/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:29:31 by msiesse           #+#    #+#             */
/*   Updated: 2020/02/09 22:15:21 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	main(int ac, char **av)
{
	t_env		e;

	init_sdl(&e);
	init_env(&e);
	e.scene = create_scene_test();
	get_mat_base(&e.scene);
	limit_objects(&e.scene);
	scale_objects(&e.scene);
	rotate_objects(&e.scene, &e.scene.objects);
	render_scene(&e);
	while (!handler_event(&e))
		;
	good_exit(&e);
	(void)ac;
	(void)av;
}
