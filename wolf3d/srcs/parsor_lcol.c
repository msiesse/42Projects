/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsor_lcol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 10:19:29 by msiesse           #+#    #+#             */
/*   Updated: 2019/08/28 10:45:10 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		verif_charnb(char c, t_env *e)
{
	if (c >= '0' && c <= '9' && e->parsor.index_nb < 9)
	{
		e->parsor.nb[e->parsor.index_nb] = c;
		e->parsor.index_nb++;
	}
	else if (e->parsor.index_nb > 8)
		error_parsor(ERR_NB_TOOBIG, &e->points);
	else
		error_parsor(ERR_CHAR, &e->points);
}

static void	verif_lines(t_env *e)
{
	e->lines = get_nb(e->parsor.nb);
	if (e->lines < 3)
		error_parsor(ERR_TOOSMALL, &e->points);
	if (e->lines > 200)
		error_parsor(ERR_TOOBIG, &e->points);
	init_parsor(&e->parsor);
}

void		parsor_lcol(const int fd, t_env *e)
{
	char	c;

	while ((c = parsor_com(fd)) == COM)
		;
	while (c == '\n' || c == ' ')
		c = ft_fgetc(fd);
	while (c > 0 && c != ' ')
	{
		verif_charnb(c, e);
		c = ft_fgetc(fd);
	}
	verif_lines(e);
	while ((c = ft_fgetc(fd)) > 0 && c == ' ')
		;
	while (c > 0 && c != ' ' && c != '\n')
	{
		verif_charnb(c, e);
		c = ft_fgetc(fd);
	}
	e->cols = get_nb(e->parsor.nb);
	if (e->cols < 3)
		error_parsor(ERR_TOOSMALL, &e->points);
	if (e->cols > 200)
		error_parsor(ERR_TOOBIG, &e->points);
}
