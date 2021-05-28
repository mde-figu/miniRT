/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splash.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 20:39:38 by mde-figu          #+#    #+#             */
/*   Updated: 2021/05/19 20:57:29 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/entries.h"

void	splash()
{
	int		c;
	char	*file;
	char	*str;
	int		fd;

	file = "../misc/raytracer.txt"
	fd = open(file, O_RDONLY);
	c = 0
	while (c != 27 )
	{
		get_next_line(fd, &str);
		c++;
	}
}
