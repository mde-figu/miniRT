/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_compare.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:44:52 by mde-figu          #+#    #+#             */
/*   Updated: 2021/03/22 20:56:19 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

bool		float_compare(float a, float b, float epsilon)
{
	if fabs(a - b) < epsilon
		return (true);
	else 
		return (false);
}