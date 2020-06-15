/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mat_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:29:21 by msiesse           #+#    #+#             */
/*   Updated: 2020/01/28 15:02:42 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

static t_angle	get_theta(t_cam *cam)
{
	t_angle	theta;

	if (cam->view.y == 0)
		theta = 0.0;
	else if (cam->view.x == 0)
	{
		if (cam->view.y < 0)
			theta = -M_PI_2;
		else
			theta = M_PI_2;
	}
	else
	{
		theta = (t_angle)atan((float)(cam->view.y / cam->view.x))
			+ signbit(cam->view.x) * M_PI;
	}
	return (theta);
}

static t_cam	get_cam_prime(t_cam *cam, t_angle theta)
{
	t_cam	cam_prime;

	cam_prime.view.y = 0;
	cam_prime.view.z = cam->view.z;
	cam_prime.view.x = cos(theta) * cam->view.x + sin(theta) * cam->view.y;
	return (cam_prime);
}

static t_angle	get_phi(t_cam *cam)
{
	t_angle	phi;

	if (cam->view.z == 0)
		phi = 0.0;
	else if (cam->view.x == 0)
	{
		if (cam->view.z < 0)
			phi = M_PI_2;
		else
			phi = -M_PI_2;
	}
	else
	{
		phi = (t_angle)atan((float)(-cam->view.z / cam->view.x))
			- signbit(cam->view.x) * M_PI;
	}
	return (phi);
}

void			get_mat_base(t_scene *scene)
{
	t_angle	theta;
	t_angle	phi;
	t_cam	cam_prime;
	t_mat	z[3][3];
	t_mat	y[3][3];

	theta = get_theta(&scene->cam);
	cam_prime = get_cam_prime(&scene->cam, theta);
	phi = get_phi(&cam_prime);
	rot_z(theta, z);
	rot_y(phi, y);
	product_mat(y, z, scene->rot);
}
