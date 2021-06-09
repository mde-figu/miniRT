/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_compare.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:44:52 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/06 19:26:03 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../include/entries.h"

bool	float_compare(float a, float b)
{
	if (fabs(a - b) < EPSILON)
		return (true);
	else
		return (false);
}
