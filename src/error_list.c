/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:55:01 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/21 17:19:04 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

int		error_list(int error_nbr)
{
	char	*filename;
	char	*errstring;
	int		fd;
	int		i;

	filename = "misc/error.txt";
	fd = open(filename, O_RDONLY);
	i = 0;
	while ((get_next_line(fd, &errstring) == 1))
	{
		if (i == error_nbr)
			return (0);
		free(errstring);
		i++;
	}
	if (errstring)
		ft_putstr_fd(errstring, 2);
	else
		ft_putstr_fd("ERROR: Error file not found", 2);
	write(1, "\n", 2);
	close(fd);
	return (0);
}
