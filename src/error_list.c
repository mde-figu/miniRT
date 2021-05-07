/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:55:01 by mde-figu          #+#    #+#             */
/*   Updated: 2021/05/07 20:14:58 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entries.h"

int		error_list(int error_nbr)
{
	int		i;
	int		fd;
	char	*fil;
	char	*error_str;

	if (error_nbr == 0)
	{
		printf(" .rt file is empty")
		exit(0);
	}
	if (error_nbr == 1)
		printf("Too few arguments!\n", );
	if (error_nbr == 2)
		printf("Too many arguments!\n", );
	if (error_nbr == 3)
		printf(".rt file is wrong or its data is corrupted\n", );
	if (error_nbr == 4)
		printf("wrong spacing on second argument, check syntax\n", );
	if (error_nbr == 10)
		printf("could not add tuple, W parameter is wrong\n");
	if (error_nbr == 20)
		printf("Invalid code in .rt file, use:R,A,c,l,pl,sp,sq,cy or tr");
	if (error_nbr == 21)
		printf("The resolution parameters must total 3: R Width Height");
	if (error_nbr == 22)
		printf("The resolution parameters Width and Height must be numbers");
	if (error_nbr == 23)
		printf("The ambient light must have 3 parameters: A, x size, y size");
	if (error_nbr == 24)
		printf("The parameters value for ambient light must be 0.0 ~ 1.0");
	if (error_nbr == 25)
		printf("Camera parameters must be four: c and its coordinates, x,y,z");
	if (error_nbr == 26)
		printf("Camera coordinate parameters are invalid");
	if (error_nbr == 27)
		printf("Camera normal vector parameters are invalid");
	if (error_nbr == 28)
		printf("Camera Field of View must be between 0.0 and 180.0");
	if (error_nbr == 29)
		printf("Lighting must have 4 parameters: l, x,y,z(coordinates), o (brightness) and RGB");
	if (error_nbr == 30)
		printf("Lighting coordinates invalid");
	if (error_nbr == 31)
		printf("Lighting brightness value must be between 0.0 and 1.0");
	if (error_nbr == 32)
		printf("Lighting color invalid");
	if (error_nbr == 33)
		printf("A Plane must have 4 parameters: pl, x,y,z (its coordinates), its normal and its RGB color");
	if (error_nbr == 34)
		printf("Plane has invalid coordinates");
	if (error_nbr == 35)
		printf("Plane has an invalid normal coordinate");
	if (error_nbr == 36)
		printf("Plane has an invalid color");
	if (error_nbr == 37)
		printf("Spheres must have 4 parameters: sp, its coordinates, its diameter, and its color");
	return (0);
}
