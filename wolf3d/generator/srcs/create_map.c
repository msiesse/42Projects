/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 14:20:50 by msiesse           #+#    #+#             */
/*   Updated: 2019/09/06 11:18:20 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "gen.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int			create_file(char *name)
{
	int		fd;

	if ((fd = open(name, O_RDWR | O_CREAT | O_EXCL | O_APPEND)) == -1)
		return (manage_error(strerror(errno), -1));
	return (fd);
}

static int	write_dim(t_data *data)
{
	if (write(data->fd, data->dim[Y], ft_strlen(data->dim[Y])) == -1)
		return (manage_error(strerror(errno), -1));
	if (write(data->fd, " ", 1) == -1)
		return (manage_error(strerror(errno), -1));
	if (write(data->fd, data->dim[X], ft_strlen(data->dim[X])) == -1)
		return (manage_error(strerror(errno), -1));
	if (write(data->fd, "\n", 1) == -1)
		return (manage_error(strerror(errno), -1));
	return (0);
}

static int	write_map_case(t_data *data, int i, int j)
{
	int	alea;

	if (j == 0 || j == data->nb_dim[Y] - 1 || i == 0
					|| i == data->nb_dim[X] - 1)
	{
		if (write(data->fd, "1", 1) == -1)
			return (manage_error(strerror(errno), -1));
	}
	else
	{
		alea = rand() % 100;
		if (alea < data->density && not_player(data, i, j))
		{
			if (write(data->fd, "1", 1) == -1)
				return (manage_error(strerror(errno), -1));
		}
		else
		{
			if (write(data->fd, "0", 1) == -1)
				return (manage_error(strerror(errno), -1));
		}
	}
	return (0);
}

static int	write_map(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->nb_dim[Y])
	{
		i = 0;
		while (i < data->nb_dim[X])
		{
			write_map_case(data, i, j);
			i++;
		}
		if (write(data->fd, "\n", 1) == -1)
			return (manage_error(strerror(errno), -1));
		j++;
	}
	return (0);
}

int			create_map(t_data *data)
{
	if (write_dim(data) == -1)
		return (ERR_WDIM);
	if (write_map(data) == -1)
		return (ERR_WMAP);
	if (write_pos_angle(data) == -1)
		return (ERR_WPANGLE);
	return (0);
}
