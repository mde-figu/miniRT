/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:34:49 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/21 18:45:42 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

static void	init_camera(t_camera *c, int hsize, int vsize, double field_of_view)
{
	c->hsize = hsize;
	c->vsize = vsize;
	c->field_of_view = field_of_view;
}

t_camera	camera(int hsize, int vsize, double field_of_view)
{
	t_camera	c;
	float		half_view;
	float		aspect;
	t_matrix	i;

	init_camera(&c, hsize, vsize, field_of_view);
	c.transform = matrix(4);
	i = identity();
	copy_matrix(&c.transform, i);
	free_matrix(&i);
	half_view = tan(c.field_of_view / 2);
	aspect = (float)c.hsize / (float)c.vsize;
	if (aspect >= 1)
	{
		c.half_width = half_view;
		c.half_height = half_view / aspect;
	}
	else
	{
		c.half_width = half_view * aspect;
		c.half_height = half_view;
	}
	c.pixel_size = (c.half_width * 2) / c.hsize;
	return (c);
}

void	cameras(t_cameras **l, t_camera c)
{
	t_cameras	*tmp;

	if (list_size_cam(*l) == 0)
		*l = list_new_cam(c);
	else
	{
		tmp = *l;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = list_new_cam(c);
	}
}

static	void	aux(t_matrix *orientation, t_orientcam p)
{
	write_matrix(orientation, 0, 0, p.left.x);
	write_matrix(orientation, 0, 1, p.left.y);
	write_matrix(orientation, 0, 2, p.left.z);
	write_matrix(orientation, 0, 3, 0.0);
	write_matrix(orientation, 1, 0, p.true_up.x);
	write_matrix(orientation, 1, 1, p.true_up.y);
	write_matrix(orientation, 1, 2, p.true_up.z);
	write_matrix(orientation, 1, 3, 0.0);
	write_matrix(orientation, 2, 0, -p.forward.x);
	write_matrix(orientation, 2, 1, -p.forward.y);
	write_matrix(orientation, 2, 2, -p.forward.z);
	write_matrix(orientation, 2, 3, 0.0);
	write_matrix(orientation, 3, 0, 0.0);
	write_matrix(orientation, 3, 1, 0.0);
	write_matrix(orientation, 3, 2, 0.0);
	write_matrix(orientation, 3, 3, 1.0);
}

t_matrix	transform_cam(t_tuple from, t_tuple to, t_tuple up)
{
	t_orientcam	p;
	t_matrix	orientation;
	t_matrix	t;
	t_matrix	resp;

	p.forward = tuple_normalize(subtract_tuple(to, from));
	p.upn = tuple_normalize(up);
	p.left = cross_product(p.forward, p.upn);
	p.true_up = cross_product(p.left, p.forward);
	orientation = matrix(4);
	aux(&orientation, p);
	t = translation(-from.x, -from.y, -from.z);
	resp = matrix_multi(orientation, t);
	free_matrix(&orientation);
	free_matrix(&t);
	return (resp);
}
