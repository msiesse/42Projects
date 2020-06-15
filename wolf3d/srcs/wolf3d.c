/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <ceaudouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:42:10 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/09/16 12:15:37 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <unistd.h>

static void	error_mlx(int error_id, t_env *e)
{
	reinit_points(&e->points);
	if (error_id == ERR_MLX_INIT)
		ft_putendl_fd("wolf3d: cannot allocate memory for mlx_ptr", 2);
	else if (error_id == ERR_MLX_WINDOW)
		ft_putendl_fd("wolf3d: cannot allocate memory for window", 2);
	else
	{
		if (error_id == ERR_MLX_IMG)
			ft_putendl_fd("wolf3d: cannot allocate memory for img", 2);
		else if (error_id == ERR_MLX_DATA)
			ft_putendl_fd("wolf3d: cannot allocate memory for data_img", 2);
		mlx_destroy_window(e->m.mlx, e->m.win);
	}
	exit(EXIT_FAILURE);
}

void		raycasting(t_env *e)
{
	minimap(e);
	ft_draw(e);
	if (e->rain == 1)
		rain(e);
}

static int	move_expose(t_env *e)
{
	if (e->forward)
		forward(e);
	if (e->backward)
		back(e);
	if (e->right)
		e->axe -= e->sensi;
	if (e->left)
		e->axe += e->sensi;
	if (e->axe >= 360)
		e->axe = 0;
	if (e->axe < 0)
		e->axe = 360;
	if (e->pos_x == e->pos_y)
		e->pos_x += 0.01;
	return (0);
}

int			ft_expose(t_env *e)
{
	mlx_clear_window(e->m.mlx, e->m.win);
	if (!(e->m.img = mlx_new_image(e->m.mlx, W_IMG, H_IMG)))
		error_mlx(ERR_MLX_IMG, e);
	if (!(e->m.data = mlx_get_data_addr(e->m.img, &e->m.bpp, &e->m.sline
					, &e->m.end)))
		error_mlx(ERR_MLX_DATA, e);
	if (!(e->m.img_map = mlx_new_image(e->m.mlx, W_MAP, H_MAP)))
		error_mlx(ERR_MLX_IMG, e);
	if (!(e->m.data_map = mlx_get_data_addr(e->m.img_map, &e->m.bpp
					, &e->m.sline, &e->m.end)))
		error_mlx(ERR_MLX_DATA, e);
	move_expose(e);
	raycasting(e);
	mlx_put_image_to_window(e->m.mlx, e->m.win, e->m.img, 0, 0);
	mlx_put_image_to_window(e->m.mlx, e->m.win, e->m.img_map, 5, 5);
	mlx_destroy_image(e->m.mlx, e->m.img);
	mlx_destroy_image(e->m.mlx, e->m.img_map);
	return (0);
}

int			wolf3d(t_env *e)
{
	if (!(e->m.mlx = mlx_init()))
		error_mlx(ERR_MLX_INIT, e);
	if (!(e->m.win = mlx_new_window(e->m.mlx, W_WIN, H_WIN, NAME)))
		error_mlx(ERR_MLX_WINDOW, e);
	texture_wall(e);
	mlx_hook(e->m.win, 2, 1L << 2, gere_key, e);
	mlx_hook(e->m.win, 3, 1L << 3, release_key, e);
	mlx_hook(e->m.win, 17, 1L << 17, do_exit, e);
	mlx_loop_hook(e->m.mlx, ft_expose, e);
	mlx_loop(e->m.mlx);
	return (0);
}
