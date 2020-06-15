/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 11:30:58 by msiesse           #+#    #+#             */
/*   Updated: 2020/02/06 15:57:50 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	get_rot_x(t_mat rot_x[3][3], t_angle theta)
{
	rot_x[0][0] = 1;
	rot_x[0][1] = 0;
	rot_x[0][2] = 0;
	rot_x[1][0] = 0;
	rot_x[1][1] = cos(theta);
	rot_x[1][2] = -sin(theta);
	rot_x[2][0] = 0;
	rot_x[2][1] = sin(theta);
	rot_x[2][2] = cos(theta);
}

void	get_rot_y(t_mat rot_y[3][3], t_angle theta)
{
	rot_y[0][0] = cos(theta);
	rot_y[0][1] = 0;
	rot_y[0][2] = sin(theta);
	rot_y[1][0] = 0;
	rot_y[1][1] = 1;
	rot_y[1][2] = 0;
	rot_y[2][0] = -sin(theta);
	rot_y[2][1] = 0;
	rot_y[2][2] = cos(theta);
}

void	get_rot_z(t_mat rot_z[3][3], t_angle theta)
{
	rot_z[0][0] = cos(theta);
	rot_z[0][1] = -sin(theta);
	rot_z[0][2] = 0;
	rot_z[1][0] = sin(theta);
	rot_z[1][1] = cos(theta);
	rot_z[1][2] = 0;
	rot_z[2][0] = 0;
	rot_z[2][1] = 0;
	rot_z[2][2] = 1;
}

void	get_rot(t_mat rot[3][3], t_angle theta, uint8_t axe)
{
	if (axe == X)
		get_rot_x(rot, theta);
	else if (axe == Y)
		get_rot_y(rot, theta);
	else if (axe == Z)
		get_rot_z(rot, theta);
}
