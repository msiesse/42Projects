/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 10:29:30 by msiesse           #+#    #+#             */
/*   Updated: 2020/01/16 10:49:17 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include <fcntl.h>

static int	verif_file(const char *path, t_env *e)
{
	char	*rev;
	int		verif;

	verif = 0;
	if (!(rev = ft_strrev(path)))
		error_exit(ERR_MEM, e);
	if (ft_strlen(rev) >= 6)
	{
		rev[6] = 0;
		if (!(ft_strcmp(rev, "enecs.")))
			verif = 1;
		else
			verif = 0;
		rev[6] = 42;
	}
	ft_strdel(&rev);
	return (verif);
}

int			read_file(const char *path, t_env *e)
{
	if (verif_file(path, e))
	{
		if ((e->fd = open(path, O_RDONLY)) == -1)
			perror_exit(path, e);
	}
	else
		error_exit(ERR_NOT_VALID_FILE, e);
	return (1);
}
