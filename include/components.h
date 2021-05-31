/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 20:06:01 by mde-figu          #+#    #+#             */
/*   Updated: 2021/05/19 22:07:15 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPONENTS_H
# define COMPONENTS_H
# include <stdio.h>
# include <string.h>
# include <math.h>

typedef struct s_color
{
	double				red;
	double				green;
	double				brue;
}						t_color;

typedef struct s_tuple
{
	double				x;
	double				y;
	double				z;
	int					w;
}						t_tuple;

typedef struct s_object
{
	int					id;
	char				*type;
	float				minimum;
	float				maximum;
	float				side;
	t_tuple				center;
	t_matrix			transform;
	t_material			material;
	bool				closed;
	t_tuple				p1;
	t_tuple				p2;
	t_tuple				p3;
	t_tuple				e1;
	t_tuple				e2;
	t_tuple				normal;
}						t_object;

typedef struct s_objects
{
	t_objects			content;
	struct s_objects	*next;
}						t_objects;

typedef struct s_light
{
	t_tuple				position;
	t_color				intensity;
}						t_light;

typedef struct s_lights
{
	t_light				content;
	struct s_lights		*next;
}						t_lights;

typedef struct s_world
{
	t_lights			*lights;
	t_objects			*objects;
	t_color				ambient;
	int					has_light;
	int					num_objects;
}						t_world;

typedef struct s_matrix
{
	double				**element;
	int					dim;
}						t_matrix;

typedef struct s_coord
{
	int					i;
	int					j;
}						t_coord;

t_color	create_color(double red, double green, double blue);
t_color	add_color(t_color c1, t_color c2);
t_color	subtract_color(t_color c1, t_color c2);
t_color	scalar_color(t_color c1, double scale);
t_color	hadamard_product(t_color c1, t_color c2);
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