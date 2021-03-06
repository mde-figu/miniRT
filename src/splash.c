/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splash.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 20:39:38 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/21 22:28:28 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/entries.h"

void	splash(void)
{
	int		c;
	char	*filename;
	char	*str;
	int		fd;

	filename = "misc/raytracer.txt";
	fd = open(filename, O_RDONLY);
	c = 0;
	while (c != 35 )
	{
		get_next_line(fd, &str);
		printf("%s", str);
		printf("\n");
		c++;
	}
	close(fd);
}
