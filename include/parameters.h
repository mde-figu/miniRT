/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 21:16:49 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/17 17:44:53 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMETERS_H
# define PARAMETERS_H

#include "entries.h"
#include <stdio.h>
#include <string.h>
#include <math.h>


typedef struct s_obj_par
{
	char				*position;
	char				*normal;
	char				*diameter;
	char				*height;
	char				*color;
}						t_obj_par;

typedef struct s_obj2_par
{
	char				*size;
	char				*color;
}						t_obj2_par;

typedef struct s_vtx_par
{
	char				*p1;
	char				*p2;
	char				*p3;
}						t_vtx_par;

typedef struct s_atofpar
{
	int					i;
	int					flag;
	int					j;
	double				val;
	char				c;
}						t_atofpar;

typedef struct s_comps
{
	double				t;
	t_object			object;
	t_tuple				point;
	t_tuple				eyev;
	t_tuple				normalv;
	bool				inside;
	t_tuple				over_point;
}						t_comps;

typedef struct s_raypara
{
	double				distance;
	t_tuple				direction;
}						t_raypara;

typedef struct s_reflexpar
{
	t_color				ambient;
	t_color				diffuse;
	t_color				specular;
	t_color				black;
	t_color				effective_color;
	t_tuple				lightv;
	t_tuple				reflectv;
}						t_reflexpar;

typedef struct s_reflex
{
	float				reflect_dot_eye;
	float				factor;
}						t_reflex;

typedef struct s_colmix
{
	t_color				c1;
	t_color				c2;
}						t_colmix;

typedef struct s_orientcam
{
	t_tuple				forward;
	t_tuple				upn;
	t_tuple				left;
	t_tuple				true_up;
}						t_orientcam;

typedef struct s_colcomp
{
	t_color				a;
	t_material			material;
	t_light				light;
	t_tuple				position;
	t_tuple				eyev;
	t_tuple				normalv;
	bool				in_shadow;
}						t_colcomp;

typedef struct s_iter
{
	int					i;
	int					j;
	bool				swapped;
	int					n;
}						t_iter;

int			str_ptr_len(char **s);
t_color		lighting(t_colcomp p);
double		ft_atof(char *str);
double		ft_pow(int n, int exp);

#endif