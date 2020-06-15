/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 22:53:44 by msiesse           #+#    #+#             */
/*   Updated: 2019/08/06 17:50:53 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "wolf3d.h"

/*
** Function to get the file, exit the program if an error occured
*/

int		open_file(char *path)
{
	int	fd;

	if ((fd = open(path, O_RDONLY)) < 0)
	{
		perror("wolf3d");
		exit(EXIT_FAILURE);
	}
	return (fd);
}
