/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirkios <mirkios@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:55:01 by mde-figu          #+#    #+#             */
/*   Updated: 2021/05/01 14:13:56 by mirkios          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entries.h"

void		error_list(int error_nbr)
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
		printf("Invalid code in .rt file, use:R,A,c,l,pl,sp,sq,cy or tr")
	if (error_nbr == 21)
		printf("The resolution prameters must total 3: R Width Height")
	if (error_nbr == 22)
		printf("The resolution prameters Width and Height must be numbers")
	if (error_nbr == 23)
		printf("The ambient light must have 3 parameters: A, x size, y size")
	if (error_nbr == 24)
		printf("The parameters value for ambient light must be 0.0 ~ 1.0")
}
