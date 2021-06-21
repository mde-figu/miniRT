/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 20:06:01 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/21 17:41:54 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPONENTS_H
# define COMPONENTS_H
# include <stdio.h>
# include <string.h>
# include <math.h>
# include "entries.h"

typedef struct s_color
{
	double				red;
	double				green;
	double				blue;
}						t_color;

typedef struct s_tuple
{
	double				x;
	double				y;
	double				z;
	int					w;
}						t_tuple;

typedef struct s_ray
{
	t_tuple				origin;
	t_tuple				direction;
}						t_ray;

typedef struct s_matrix
{
	double				**element;
	int					dim;
}						t_matrix;

typedef struct s_material
{
	t_color				color;
	double				ambient;
	double				diffuse;
	double				specular;
	double				shininess;
}						t_material;

typedef struct s_object
{
	int					id;
	char				*type;
	double				minimum;
	double				maximum;
	double				side;
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
	t_object			content;
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

typedef struct s_camera
{
	int					index;
	int					hsize;
	int					vsize;
	double				field_of_view;
	t_matrix			transform;
	double				half_width;
	double				half_height;
	double				pixel_size;
}						t_camera;

typedef struct s_cameras
{
	t_camera			content;
	struct s_cameras	*next;
}						t_cameras;

typedef struct s_coord
{
	int					i;
	int					j;
}						t_coord;


t_color			create_color(double red, double green, double blue);
t_color			add_color(t_color c1, t_color c2);
t_color			subtract_color(t_color c1, t_color c2);
t_color			scalar_color(t_color c1, double scale);
t_color			hadamard_product(t_color c1, t_color c2);
int				color_bool(double a);
unsigned long	color_to_rgb(int r, int g, int b);
t_tuple			create_tuple(double x, double y, double z, int w);
t_tuple			add_tuple(t_tuple t1, t_tuple t2);
t_tuple			subtract_tuple(t_tuple t1, t_tuple t2);
t_tuple			negate_tuple(t_tuple t1);
t_tuple			scale_tuple(t_tuple t1, double scale);
double			tuple_mag(t_tuple t1);
double			tuple_rsqrt(t_tuple t1);
float			q_rsqrt(float number);
t_tuple			tuple_normalize(t_tuple t1);
t_tuple			quake_normalize(t_tuple t1);
t_tuple			cross_product(t_tuple t1, t_tuple t2);
double			dot_product(t_tuple i, t_tuple j);
t_tuple			normal_placement(t_object o, t_tuple point);
t_tuple			place_normal(t_object o, t_tuple v);
t_material		mat_par(void);

t_matrix		matrix(int dim);
t_tuple			matrix_x_vector(t_matrix a, t_tuple b);
void			write_matrix(t_matrix *m, int i, int j, double e);
void			copy_matrix(t_matrix *d, t_matrix o);
void			free_matrix(t_matrix *a);
t_matrix		translation(double x, double y, double z);
t_matrix		scaling(double x, double y, double z);
t_ray			transform(t_ray r, t_matrix m);
t_matrix		transpose(t_matrix a);
double			matrix_minor(t_matrix a, int i, int j);
t_matrix		inverse(t_matrix a);
double			determinant(t_matrix a);
t_matrix		submatrix(t_matrix a, int i, int j);
double			cofactor(t_matrix a, int i, int j);
t_matrix		matrix_multi(t_matrix a, t_matrix b);
t_matrix		identity(void);
t_matrix		inverse(t_matrix a);
bool			is_invertible(t_matrix a);
t_matrix		rotation_x(double r);
t_matrix		rotation_y(double r);
t_matrix		rotation_z(double r);
t_matrix		rotate(t_tuple normal);

void			list_obj(t_objects **l, t_object o);
int				list_size_obj(t_objects *lst);
t_objects		*list_new_obj(t_object content);
int				list_size_world(t_objects *lst);
t_objects		*list_new_world(t_object content);
int				list_size_lig(t_lights *lst);
t_lights		*list_new_lig(t_light content);
void			light(t_lights **l, t_light light);
t_light			point_light(t_tuple position, t_color intensity);
t_tuple			reflect(t_tuple in, t_tuple normal);


t_camera		camera(int hsize, int vsize, double field_of_view);
t_matrix		transform_cam(t_tuple from, t_tuple to, t_tuple up);


#endif