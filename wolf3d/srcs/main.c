/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:49:46 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/09/06 10:58:02 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <fcntl.h>
#include <unistd.h>

int		main(int ac, char **av)
{
	t_env	e;
	int		fd;

	if (ac == 1)
		fd = open_file("/dev/fd/0");
	else
		fd = open_file(av[1]);
	w_parsor(fd, &e);
	close(fd);
	env_init(&e);
	wolf3d(&e);
	return (0);
}
