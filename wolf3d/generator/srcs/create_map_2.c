/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 15:00:49 by msiesse           #+#    #+#             */
/*   Updated: 2019/08/28 10:10:55 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "gen.h"
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int		not_player(t_data *data, int i, int j)
{
	if (data->nb_pos[X] >= (i * 64) && data->nb_pos[X] <= (i * 64) + 63
			&& data->nb_pos[Y] >= (j * 64) && data->nb_pos[Y]
			<= (j * 64) + 63)
		return (0);
	return (1);
}

int		write_pos_angle(t_data *data)
{
	if (write(data->fd, data->pos[X], ft_strlen(data->pos[X])) == -1)
		return (manage_error(strerror(errno), -1));
	if (write(data->fd, " ", 1) == -1)
		return (manage_error(strerror(errno), -1));
	if (write(data->fd, data->pos[Y], ft_strlen(data->pos[Y])) == -1)
		return (manage_error(strerror(errno), -1));
	if (write(data->fd, " ", 1) == -1)
		return (manage_error(strerror(errno), -1));
	if (write(data->fd, data->angle, ft_strlen(data->angle)) == -1)
		return (manage_error(strerror(errno), -1));
	if (write(data->fd, "\n", 1) == -1)
		return (manage_error(strerror(errno), -1));
	return (0);
}
