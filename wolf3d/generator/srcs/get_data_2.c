/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 14:07:00 by msiesse           #+#    #+#             */
/*   Updated: 2019/08/27 15:11:04 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "gen.h"

static int	get_angle_one(t_data *data)
{
	char	nb[4];

	if (get_chars(nb, 4))
		return (1);
	if (ft_atoi(nb) > ANG_MAX)
		return (manage_error("### Error boundaries ###", ERR_BDR));
	data->nb_angle = ft_atoi(nb);
	ft_strcpy(data->angle, nb);
	return (0);
}

int			get_angle(t_data *data)
{
	ft_putendl("Put the angle view:");
	while (get_angle_one(data))
		ft_putendl("Put the angle view:");
	return (0);
}

static int	get_density_one(t_data *data)
{
	char	nb[4];

	if (get_chars(nb, 4))
		return (1);
	if (ft_atoi(nb) > 100)
		return (manage_error("### Error boundaries ###", ERR_BDR));
	data->density = ft_atoi(nb);
	return (0);
}

int			get_density(t_data *data)
{
	ft_putendl("Put the density of the map:");
	while (get_density_one(data))
		ft_putendl("Put the density of the map:");
	return (0);
}
