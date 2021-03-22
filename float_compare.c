/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_compare.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:44:52 by mde-figu          #+#    #+#             */
/*   Updated: 2021/03/22 20:49:02 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

bool		float_compare(float a, float b, float epsilon)
{
	return fabs(a - b) < epsilon;
}