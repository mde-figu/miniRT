/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:55:01 by mde-figu          #+#    #+#             */
/*   Updated: 2021/04/27 15:23:25 by mde-figu         ###   ########.fr       */
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
	if ()
}