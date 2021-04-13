/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirkios <mirkios@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:55:01 by mde-figu          #+#    #+#             */
/*   Updated: 2021/04/11 13:37:05 by mirkios          ###   ########.fr       */
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
	
}