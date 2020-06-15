/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 10:46:12 by msiesse           #+#    #+#             */
/*   Updated: 2019/08/27 14:11:21 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "gen.h"
#include <stdio.h>

int			get_chars(char *nb, int size)
{
	char	c;
	int		i;

	i = 0;
	while ((c = ft_fgetc(0)) >= 0 && c != '\n')
	{
		if (c >= '0' && c <= '9')
			nb[i++] = c;
		else if (c != ' ' && c != '\t')
			return (manage_error("### Forbidden Char ###", ERR_CHAR));
		else if ((c == ' ' || c == '\t') && i > 0 && i <= (size - 1))
		{
			while (c != '\n')
				c = ft_fgetc(0);
			break ;
		}
		if (i > (size - 1))
			return (manage_error("### Not enough memory ###", ERR_MEM));
	}
	nb[i] = 0;
	return (0);
}

static int	get_dim_one(t_data *data, int cord)
{
	char	nb[4];

	if (get_chars(nb, 4))
		return (1);
	if (ft_atoi(nb) > BDR_MAX || ft_atoi(nb) < BDR_MIN)
		return (manage_error("### Error boundaries ###", ERR_BDR));
	data->nb_dim[cord] = ft_atoi(nb);
	ft_strcpy(data->dim[cord], nb);
	return (0);
}

int			get_dim(t_data *data)
{
	ft_putendl("Put dimension on X-axis:");
	while (get_dim_one(data, X))
		ft_putendl("Put dimension on X-axis:");
	ft_putendl("Put dimension on Y-axis:");
	while (get_dim_one(data, Y))
		ft_putendl("Put dimension on Y-axis:");
	return (0);
}

static int	get_pos_one(t_data *data, int cord)
{
	char	nb[6];

	if (get_chars(nb, 6))
		return (1);
	if (ft_atoi(nb) >= (data->nb_dim[cord] - 1) * 64 || ft_atoi(nb) < 64)
		return (manage_error("### Error boundaries ###", ERR_BDR));
	data->nb_pos[cord] = ft_atoi(nb);
	ft_strcpy(data->pos[cord], nb);
	return (0);
}

int			get_pos(t_data *data)
{
	ft_putendl("Put position on X-axis:");
	while (get_pos_one(data, X))
		ft_putendl("Put position on X-axis:");
	ft_putendl("Put position on Y-axis:");
	while (get_pos_one(data, Y))
		ft_putendl("Put position on Y-axis:");
	return (0);
}
