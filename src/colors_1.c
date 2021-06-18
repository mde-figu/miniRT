/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:00:10 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/18 00:21:50 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

t_color	create_color(double red, double green, double blue)
{
	t_color	color;

	color.red = red;
	color.green = green;
	color.blue = blue;

	return (color);
}

t_color	add_color(t_color c1, t_color c2)
{
	t_color	new;

	new.red = c1.red + c2.red;
	new.green = c1.green + c2.green;
	new.blue = c1.blue + c2.blue;

	return (new);
}

t_color	subtract_color(t_color c1, t_color c2)
{
	t_color	new;

	new.red = c1.red - c2.red;
	new.green = c1.green - c2.green;
	new.blue = c1.blue - c2.blue;

	return (new);
}

t_color	scalar_color(t_color c1, double scale)
{
	t_color	new;

	new.red = c1.red * scale;
	new.green = c1.green * scale;
	new.blue = c1.blue * scale;

	return (new);
}

t_color	hadamard_product(t_color c1, t_color c2)
{
	t_color	new;

	new.red = c1.red * c2.red;
	new.green = c1.green * c2.green;
	new.blue = c1.blue * c2.blue;
	return (new);
}
