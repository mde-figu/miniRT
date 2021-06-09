/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_res.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:59:29 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/06 22:05:17 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

void	config_res(t_initpara *initpara, char *res_x, char *res_y)
{
	int		sizex;
	int		sizey;
	int		x;
	int		y;
	void	*mlx;

	mlx = mlx_init();
	mlx_get_screen_size(mlx, &sizex, &sizey);
	x = ft_atoi(res_x);
	y = ft_atoi(res_y);
	if (x > sizex)
		initpara->res_x = sizex;
	else
		initpara->res_x = x;
	if (y > sizey)
		initpara->res_y = sizey;
	else
		initpara->res_y = y;
}
