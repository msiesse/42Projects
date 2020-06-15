/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsor_cam.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:18:16 by msiesse           #+#    #+#             */
/*   Updated: 2019/08/28 10:26:59 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	cam_posx(char *c, const int fd, t_env *e)
{
	init_parsor(&e->parsor);
	while ((*c = parsor_com(fd)) == COM)
		;
	while (*c == '\n' || *c == ' ')
		*c = ft_fgetc(fd);
	while (*c > 0 && *c != ' ')
	{
		verif_charnb(*c, e);
		*c = ft_fgetc(fd);
	}
	e->pos_x = (double)ft_atoi(e->parsor.nb);
}

static void	cam_posy(char *c, const int fd, t_env *e)
{
	init_parsor(&e->parsor);
	while (*c == ' ')
		*c = ft_fgetc(fd);
	while (*c > 0 && *c != ' ')
	{
		verif_charnb(*c, e);
		*c = ft_fgetc(fd);
	}
	e->pos_y = (double)ft_atoi(e->parsor.nb);
}

static void	cam_axe(char *c, const int fd, t_env *e)
{
	init_parsor(&e->parsor);
	while (*c == ' ')
		*c = ft_fgetc(fd);
	while (*c > 0 && *c != '\n')
	{
		verif_charnb(*c, e);
		*c = ft_fgetc(fd);
	}
	e->axe = (double)(ft_atoi(e->parsor.nb) % 360);
}

void		parsor_cam(const int fd, t_env *e)
{
	char	c;

	cam_posx(&c, fd, e);
	cam_posy(&c, fd, e);
	cam_axe(&c, fd, e);
}
