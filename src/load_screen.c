/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:55:20 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/17 18:35:34 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

static int	closew(t_initpara *initpara)
{
	mlx_destroy_window(initpara->mlx, initpara->win);
	exit(0);
	return (0);
}

static int	next_cam(int keycode, t_initpara *initpara)
{
	if (keycode == 0xFF1B)
		exit(0);
	if (keycode !=0x20)
		return (0);
	if (initpara->img->next)
	{
		initpara->img = initpara->img->next;
		mlx_put_image_to_window(initpara->mlx, initpara->win,
			initpara->img->content.image, 0, 0);
	}
	else
	{
		initpara->img = initpara->img_init;
		mlx_put_image_to_window(initpara->mlx, initpara->win,
			initpara->img->content.image, 0, 0);
	}
	return (1);
}

static int	expose_hook(t_initpara *initpara)
{
	return (mlx_put_image_to_window(initpara->mlx, initpara->win,
			initpara->img->content.image, 0, 0));
}

void	load_screen(t_initpara initpara, bool savei)
{
	initpara.mlx = mlx_init();
	if (initpara.cams == NULL)
		error_list(58);
	if (initpara.objects == NULL)
		error_list(59);
	image(&initpara);
	if (savei)
		save(initpara);
	else
	{
		initpara.win = mlx_new_window(initpara.mlx, initpara.res_x, initpara.res_y, "miniRT");
		mlx_hook(initpara.win, 33, 1L << 17, closew, &initpara);
		mlx_hook(initpara.win, 2, 1, next_cam, &initpara);
		mlx_expose_hook(initpara.win, expose_hook, &initpara);
		mlx_loop(initpara.mlx);
	}
}
