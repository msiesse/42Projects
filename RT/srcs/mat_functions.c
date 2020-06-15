/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:31:49 by msiesse           #+#    #+#             */
/*   Updated: 2020/02/09 21:51:34 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	product_mat(t_mat mat_a[3][3], t_mat mat_b[3][3], t_mat res[3][3])
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			k = 0;
			res[i][j] = 0;
			while (k < 3)
			{
				res[i][j] += mat_a[i][k] * mat_b[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
}

void	rot_z(t_angle theta, t_mat rot[3][3])
{
	rot[0][0] = cos(theta);
	rot[0][1] = sin(theta);
	rot[0][2] = 0;
	rot[1][0] = -sin(theta);
	rot[1][1] = cos(theta);
	rot[1][2] = 0;
	rot[2][0] = 0;
	rot[2][1] = 0;
	rot[2][2] = 1;
}

void	rot_y(t_angle phi, t_mat rot[3][3])
{
	rot[0][0] = cos(phi);
	rot[0][1] = 0;
	rot[0][2] = -sin(phi);
	rot[1][0] = 0;
	rot[1][1] = 1;
	rot[1][2] = 0;
	rot[2][0] = sin(phi);
	rot[2][1] = 0;
	rot[2][2] = cos(phi);
}

void	product_mat_diag(t_mat a[3][3], t_diag diag[3], t_mat res[3][3])
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			res[i][j] = a[i][j] * diag[j];
			j++;
		}
		i++;
	}
}

void	product_mat_vect(t_mat a[3][3], t_vect vect, t_vect *res)
{
	res->x = a[0][0] * vect.x + a[0][1] * vect.y + a[0][2] * vect.z;
	res->y = a[1][0] * vect.x + a[1][1] * vect.y + a[1][2] * vect.z;
	res->z = a[2][0] * vect.x + a[2][1] * vect.y + a[2][2] * vect.z;
}
