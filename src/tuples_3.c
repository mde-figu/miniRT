/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:02:07 by mde-figu          #+#    #+#             */
/*   Updated: 2021/05/16 13:48:49 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/components.h"

t_tuple create_point(double x, double y, double z)
{
	t_tuple	p;

	p.x = x;
	p.y = y;
	p.z = z;
	p.w = 1;
	return (p);
}

t_tuple create_vector(double x, double y, double z)
{
	t_tuple v;
	v.x = x;
	v.y = y;
	v.z = z;
	v.w = 0;
	return (v);
}
