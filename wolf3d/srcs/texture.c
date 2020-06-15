/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <ceaudouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 14:14:45 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/09/16 12:16:06 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <unistd.h>

static void	texture_wall_sky(t_env *e)
{
	if (access("textures/skybox.xpm", F_OK) != -1)
	{
		e->tex[5].img = mlx_xpm_file_to_image(e->m.mlx, "textures/skybox.XPM"
				, &(e->tex[5].width), &(e->tex[5].height));
		e->tex[5].data = mlx_get_data_addr(e->tex[5].img, &e->m.bpp, &e->m.sline
				, &e->m.end);
	}
	else
	{
		ft_putstr("error file texture: skybox.xpm missing\n");
		good_exit(e, 1);
	}
	if (access("textures/skybox.xpm", F_OK) != -1)
	{
		e->tex[6].img = mlx_xpm_file_to_image(e->m.mlx
		, "textures/skybox_rain.XPM", &(e->tex[6].width), &(e->tex[6].height));
		e->tex[6].data = mlx_get_data_addr(e->tex[6].img, &e->m.bpp, &e->m.sline
				, &e->m.end);
	}
	else
	{
		ft_putstr("error file texture: skybox_rain.xpm missing\n");
		good_exit(e, 1);
	}
}

void		texture3(t_env *e)
{
	if (access("textures/SteelwallL.xpm", F_OK) != -1)
	{
		e->tex[4].img = mlx_xpm_file_to_image(e->m.mlx
		, "textures/SteelwallL.XPM", &(e->tex[4].width), &(e->tex[4].height));
		e->tex[4].data = mlx_get_data_addr(e->tex[4].img, &e->m.bpp, &e->m.sline
				, &e->m.end);
	}
	else
	{
		ft_putstr("error file texture: SteelwallL.xpm missing\n");
		good_exit(e, 1);
	}
	texture_wall_sky(e);
}

void		texture2(t_env *e)
{
	if (access("textures/WoodbrickL.xpm", F_OK) != -1)
	{
		e->tex[2].img = mlx_xpm_file_to_image(e->m.mlx
		, "textures/WoodbrickL.XPM", &(e->tex[2].width), &(e->tex[2].height));
		e->tex[2].data = mlx_get_data_addr(e->tex[2].img, &e->m.bpp, &e->m.sline
				, &e->m.end);
	}
	else
	{
		ft_putstr("error file texture: WoodbrickL.xpm missing\n");
		good_exit(e, 1);
	}
	if (access("textures/RedwallL.xpm", F_OK) != -1)
	{
		e->tex[3].img = mlx_xpm_file_to_image(e->m.mlx, "textures/RedwallL.XPM"
				, &(e->tex[3].width), &(e->tex[3].height));
		e->tex[3].data = mlx_get_data_addr(e->tex[3].img, &e->m.bpp, &e->m.sline
				, &e->m.end);
	}
	else
	{
		ft_putstr("error file texture: RedwallL.xpm missing\n");
		good_exit(e, 1);
	}
	texture3(e);
}

void		texture_wall(t_env *e)
{
	if (access("textures/redgrey.xpm", F_OK) != -1)
	{
		e->tex[0].img = mlx_xpm_file_to_image(e->m.mlx, "textures/redgrey.xpm"
				, &(e->tex[0].width), &(e->tex[0].height));
		e->tex[0].data = mlx_get_data_addr(e->tex[0].img, &e->m.bpp, &e->m.sline
			, &e->m.end);
	}
	else
	{
		ft_putstr("error file texture: redgrey.xpm missing\n");
		good_exit(e, 1);
	}
	if (access("textures/brownbrick.xpm", F_OK) != -1)
	{
		e->tex[1].img = mlx_xpm_file_to_image(e->m.mlx
		, "textures/brownbrick.xpm", &(e->tex[1].width), &(e->tex[1].height));
		e->tex[1].data = mlx_get_data_addr(e->tex[1].img, &e->m.bpp, &e->m.sline
				, &e->m.end);
	}
	else
	{
		ft_putstr("error file texture: brownbrick.xpm missing\n");
		good_exit(e, 1);
	}
	texture2(e);
}
