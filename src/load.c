/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 17:28:04 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/21 19:48:48 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

void	loading_bar(double percent, int total, t_initpara initpara)
{
	int			ten;
	static int	counter;
	char		*camera;

	ten = total * 10;
	if (counter == 0)
		ft_putstr_fd("Rendering... \n▒", 1);
	if (counter == ten)
	{
		ft_putstr_fd("▒", 1);
		counter = 0;
	}
	counter++;
	if (percent == 1)
	{
		camera = ft_itoa(initpara.cams->content.index);
		ft_putstr_fd(" 100%\n", 1);
		ft_putstr_fd("Camera ", 1);
		ft_putstr_fd(camera, 1);
		ft_putstr_fd(" rendered successfully.\n", 1);
		free(camera);
	}
}
