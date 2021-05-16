/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 21:16:49 by mde-figu          #+#    #+#             */
/*   Updated: 2021/05/12 11:48:57 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMETERS_H
# define PARAMETERS_H

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

typedef struct			s_respar1
{
	double				val;
	int					flag;
}						t_respar1;

#endif