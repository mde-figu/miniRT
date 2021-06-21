/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:37:29 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/21 16:06:53 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

static t_interl	*ft_aux(t_object s, t_ray ray)
{
	t_ray		local_ray;
	t_interl		*xs;
	t_matrix	a;

	xs = NULL;
	if (ft_memcmp("plane", s.type, 5) == 0)
	{
		a = inverse(s.transform);
		local_ray = transform(ray, a);
		free_matrix(&a);
		xs = intersect_plane(s, local_ray);
	}
	else if (ft_memcmp("square", s.type, 7) == 0)
	{
		a = inverse(s.transform);
		local_ray = transform(ray, a);
		free_matrix(&a);
		xs = intersect_square(s, local_ray);
	}
	return (xs);
}

t_interl	*intersect(t_object s, t_ray ray)
{
	t_interl		*xs;
	t_ray		local_ray;
	t_matrix	a;

	xs = NULL;
	if (ft_memcmp("sphere", s.type, 7) == 0)
		xs = intersect_sphere(s, ray);
	else if (ft_memcmp("cylinder", s.type, 9) == 0)
	{
		a = inverse(s.transform);
		local_ray = transform(ray, a);
		free_matrix(&a);
		xs = intersect_cylinder(s, local_ray);
	}
	else if (ft_memcmp("triangle", s.type, 9) == 0)
	{
		a = inverse(s.transform);
		local_ray = transform(ray, a);
		free_matrix(&a);
		xs = intersect_triangle(s, local_ray);
	}
	else
		xs = ft_aux(s, ray);
	return (xs);
}
