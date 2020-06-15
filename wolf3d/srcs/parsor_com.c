/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsor_com.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 10:21:44 by msiesse           #+#    #+#             */
/*   Updated: 2019/08/28 10:26:41 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

char	parsor_com(const int fd)
{
	char	c;

	c = ft_fgetc(fd);
	if (c == ' ' || c == '\n')
		return (parsor_com(fd));
	else if (c == '#')
	{
		while ((c = ft_fgetc(fd)) > 0 && c != '\n')
			;
	}
	else
		return (c);
	return (COM);
}
