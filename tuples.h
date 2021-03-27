/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 23:07:25 by mde-figu          #+#    #+#             */
/*   Updated: 2021/03/25 10:57:11 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLES_H
# define TUPLES_H

#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct			s_tuple
{
	double				x;
	double				y;
	double				z;
	int					w;
}						t_tuple;

t_tuple	create_tuple(double x, double y, double z, int w);
t_tuple	add_tuple(t_tuple t1, t_tuple t2);
t_tuple	subtract_tuple(t_tuple t1, t_tuple t2);
t_tuple	negate_tuple(t_tuple t1);
t_tuple	scale_tuple(t_tuple t1, double scale);
double	tuple_mag(t_tuple t1);
float	q_rsqrt(float number);
t_tuple	tuple_normalize(t_tuple t1);
t_tuple	quake_normalize(t_tuple t1);
t_tuple	cross_product(t_tuple t1, t_tuple t2);


#endif