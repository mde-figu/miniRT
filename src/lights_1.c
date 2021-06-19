/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 13:34:15 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/18 22:14:18 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

void	light(t_lights **l, t_light light)
{
	t_lights	*tmp;

	if (list_size_lig(*l) == 0)
		*l = list_new_lig(light);
	else
	{
		tmp = *l;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = list_new_lig(light);
	}
}

t_light	point_light(t_tuple position, t_color intensity)
{
	t_light	ret;

	ret.position = position;
	ret.intensity = intensity;
	return (ret);
}

static void	ft_int(t_reflexpar *q, t_colcomp p, double *light_dot_normal)
{
	q->black = create_color(0, 0, 0);
	q->effective_color = hadamard_product(p.material.color, p.light.intensity);
	q->lightv = tuple_normalize(subtract_tuple(p.light.position, p.position));
	q->ambient = scalar_color(q->effective_color, p.material.ambient);
	q->ambient = add_color(q->ambient, p.a);
	*light_dot_normal = dot_product(q->lightv, p.normalv);
}

static void	ft_aux(t_reflexpar *q, t_colcomp *p, double *light_dot_normal,
					t_reflex *y)
{
	q->diffuse = scalar_color(q->effective_color,
			p->material.diffuse * *light_dot_normal);
	q->reflectv = reflect(scale_tuple(q->lightv, -1), p->normalv);
	y->reflect_dot_eye = dot_product(q->reflectv, p->eyev);
	if (y->reflect_dot_eye <= 0)
	{
		q->specular = q->black;
	}
	else
	{
		y->factor = ft_pow(y->reflect_dot_eye, p->material.shininess);
		q->specular = scalar_color(p->light.intensity,
				p->material.specular * y->factor);
	}
}

t_color	lighting(t_colcomp p)
{
	t_reflexpar	q;
	double	light_dot_normal;
	t_reflex	y;

	ft_int(&q, p, &light_dot_normal);
	if (light_dot_normal < 0)
	{
		q.diffuse = q.black;
		q.specular = q.black;
	}
	else
	{
		ft_aux(&q, &p, &light_dot_normal, &y);
	}
	if (p.in_shadow == true)
	{
		q.diffuse = q.black;
		q.specular = q.black;
	}
	return (add_color(q.ambient, add_color(q.diffuse, q.specular)));
}
