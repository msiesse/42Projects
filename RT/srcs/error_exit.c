/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 10:28:20 by msiesse           #+#    #+#             */
/*   Updated: 2020/02/09 22:03:30 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include <stdio.h>

void	error_exit(int err_num, t_env *e)
{
	if (err_num == ERR_MEM)
		ft_putendl_fd("rtv1: Memory error", 2);
	else if (err_num == ERR_NOT_VALID_FILE)
		ft_putendl_fd("rtv1: Not a .scene file", 2);
	else if (err_num == ERR_INIT_SDL)
		ft_putendl_fd("rtv1: Error initialization SDL", 2);
	else if (err_num == ERR_CREATE_WINDOW)
		ft_putendl_fd("rtv1: Cannot create a window", 2);
	else if (err_num == ERR_CREATE_RENDERER)
		ft_putendl_fd("rtv1: Cannot create a renderer", 2);
	free_env(e);
	exit(EXIT_FAILURE);
}

void	perror_exit(const char *str, t_env *e)
{
	perror(str);
	free_env(e);
	exit(EXIT_FAILURE);
}
