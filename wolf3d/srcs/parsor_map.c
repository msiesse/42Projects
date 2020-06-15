/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsor_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 12:27:46 by msiesse           #+#    #+#             */
/*   Updated: 2019/08/28 10:26:11 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	parsor_map_line(const int fd, t_env *e)
{
	char	c;

	while ((c = parsor_com(fd)) == COM)
		;
	while (c == '\n' || c == ' ')
		c = ft_fgetc(fd);
	while (c > 0 && c != '\n')
	{
		if ((c == '0' && e->parsor.cols != 0 && e->parsor.cols != e->cols - 1
		&& e->parsor.lines != 0 && e->parsor.lines != e->lines - 1) || c == '1')
		{
			add_integer_dint(&e->points.x, e->parsor.cols);
			add_integer_dint(&e->points.y, e->parsor.lines);
			add_integer_dint(&e->points.z, c - 48);
			e->parsor.cols++;
		}
		else if (c != ' ')
		{
			if (c == '0')
				error_parsor(ERR_WALL, &e->points);
			else
				error_parsor(ERR_CHAR, &e->points);
		}
		c = ft_fgetc(fd);
	}
}

void		parsor_map(const int fd, t_env *e)
{
	while (e->parsor.lines != e->lines)
	{
		parsor_map_line(fd, e);
		if (e->parsor.cols != e->cols)
			error_parsor(ERR_DIM_MAP, &e->points);
		e->parsor.cols = 0;
		e->parsor.lines++;
	}
}
