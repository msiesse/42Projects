/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 11:30:56 by msiesse           #+#    #+#             */
/*   Updated: 2019/08/27 15:19:02 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "gen.h"

int	manage_error(const char *str, int err_num)
{
	char	c;

	c = 0;
	ft_putstr(RED);
	ft_putstr(BOLD);
	ft_putendl_fd(str, 2);
	ft_putstr(DEFAULT);
	while (err_num != ERR_BDR && err_num != ERR_MISS_NAME && err_num != -1
			&& c != '\n')
		c = ft_fgetc(0);
	return (err_num);
}
