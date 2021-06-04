/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 12:23:05 by mde-figu          #+#    #+#             */
/*   Updated: 2021/04/27 15:56:45 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAUNCHER_H
# define LAUNCHER_H

# include <stdio.h>
# include <string.h>
# include <math.h>

typedef struct s_projectile
{
	float				x;
	float				y;
	float				z;
	float				vx;
	float				vy;
	float				vz;
}						t_projectile;

typedef struct s_gravity
{
	float				ax;
	float				ay;
	float				az;
}						t_gravity;

typedef struct s_wind
{
	float				ax;
	float				ay;
	float				az;
}						t_wind;

#endif