/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 10:31:17 by msiesse           #+#    #+#             */
/*   Updated: 2019/08/27 15:14:58 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "gen.h"
#include <unistd.h>

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 1)
		return (manage_error("No name for the file", ERR_MISS_NAME));
	if ((data.fd = create_file(av[1])) == -1)
		return (ERR_FD);
	ft_bzero(data.dim[X], sizeof(char) * 4);
	ft_bzero(data.dim[Y], sizeof(char) * 4);
	get_dim(&data);
	ft_bzero(data.pos[X], sizeof(char) * 6);
	ft_bzero(data.pos[Y], sizeof(char) * 6);
	get_pos(&data);
	ft_bzero(data.angle, sizeof(char) * 4);
	get_angle(&data);
	get_density(&data);
	create_map(&data);
	(void)close(data.fd);
	return (0);
}
