/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_res.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:59:29 by mde-figu          #+#    #+#             */
/*   Updated: 2021/05/16 16:51:17 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

void	config_res(t_initpara *initpara, char **res)
{
	int		sizex;
	int		sizey;
	int		x;
	int		y;
	void	*mlx;
	char	*tmpx;
	char	*tmpy;

	tmpx = res[1];
	tmpy = res[2];
	mlx = mlx_init();
	mlx_get_screen_size(mlx, &sizex, &sizey);
	x = ft_atoi(tmpx);
	y = ft_atoi(tmpy);
	if (x > sizex)
		initpara->res_x = sizex;
	else
		initpara->res_x = x;
	if (y > sizey)
		initpara->res_y = sizey;
	else
		initpara->res_y = y;
	free_entry(&tmpx);
	free_entry(&tmpy);
}
