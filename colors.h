/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:53:45 by mde-figu          #+#    #+#             */
/*   Updated: 2021/03/25 12:24:11 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct			s_color
{
	double				red;
	double				green;
	double				brue;
}						t_color;

t_color	create_color(double red, double green, double blue);
t_color	add_color(t_color c1, t_color c2);
t_color	subtract_color(t_color c1, t_color c2);
t_color	scalar_color(t_color c1, double scale);
t_color	hadamard_product(t_color c1, t_color c2);


#endif