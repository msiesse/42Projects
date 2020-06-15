/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 18:03:52 by msiesse           #+#    #+#             */
/*   Updated: 2020/02/09 22:17:01 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(const char *str)
{
	char	*rev;
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	if (!(rev = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		rev[i] = str[len - i - 1];
		i++;
	}
	return (rev);
}
