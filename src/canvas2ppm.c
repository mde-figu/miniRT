/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas2ppm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 23:00:21 by mde-figu          #+#    #+#             */
/*   Updated: 2021/04/06 00:55:53 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "canvas.h"

int main ()
{
	FILE * fp;

	fp = fopen ("file.ppm", "w+");
	fprintf(fp, "%s \n", "P3");
	fprintf(fp, "%s %s %s %d", "We", "are", "in", 2012);

	fclose(fp):

	return(0);
}