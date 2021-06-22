/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:55:01 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/22 00:16:53 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

int	error_list(int error_nbr)
{
	char	*filename;
	char	*errstring;
	int		fdd;
	int		i;

	errstring = NULL;
	filename = "misc/errors.txt";
	fdd = open(filename, O_RDONLY);
	i = 0;
	while ((get_next_line(fdd, &errstring) == 1))
	{
		if (i - 6 == error_nbr)
			break ;
		free(errstring);
		i++;
	}
	if (errstring)
		ft_putstr_fd(errstring, 2);
	else
		ft_putstr_fd("ERROR: No file found", 2);
	write(1, "\n", 2);
	close(fdd);
	exit (0);
}
