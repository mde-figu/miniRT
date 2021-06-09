/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:55:20 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/07 23:28:06 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

static int closew(int keycode, t_initpara *config)
{
	if (keycode == 0xFF1B)
	{
		mlx_destroy_window(config->mlx, config->win);
		exit(0);
	}
	return (0);
}

static int	next_cam(int keycode, t_initpara *conf)
{
	if (keycode == 0xFF1B)
		exit(0);
	if (keycode !=0x20)
		return (0);
	if (conf->img->next)
	{
		conf->img = conf->img->next;
		mlx_put_image_to_window(conf->mlx, conf->win,
								conf->img->content.image, 0, 0);
	}
	else
	{
		conf->img = conf->img_init;
		mlx_put_image_to_window(conf->mlx, conf->win,
								conf->img->content.image, 0, 0);
	}
	return (1);
}

static int	expose_hook(t_initpara *conf)
{
	return (mlx_put_image_to_window(conf->mlx, conf->win,
			conf->img->content.image, 0, 0));
}

void	load_screen(t_initpara conf, bool savei)
{
	conf.mlx = mlx_init();
	if (conf.cams == NULL)
		error_list(58);
	if (conf.objects == NULL)
		error_list(59);
	image(&conf);
	if (savei)
		save(conf);
	else
	{
		conf.win = mlx_new_window(conf.mlx, conf.res_x, conf.res_y, "miniRT");
		mlx_hook(conf.win, 33, 1L << 17, closew, &conf);
		mlx_hook(conf.win, 2, 1, next_cam, &conf);
		mlx_expose_hook(conf.win, expose_hook, &conf);
		mlx_loop(conf.mlx);
	}
}
