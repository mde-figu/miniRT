/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:55:20 by mde-figu          #+#    #+#             */
/*   Updated: 2021/05/31 21:20:31 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

static int closew(int keycode, t_config *config)
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
	//if (keycode == 0xFF1B)
	//	exit(0);
	if (keycode !=0x20)
		return (0);
	if (conf->img->next)
	{
		conf->img = conf->img->next;
		mlx_put_image_to_window(conf->mlx, conf->win,
								conf->img->content.img, 0, 0);
	}
	else
	{
		conf->img = conf->img_init;
		mlx_put_image_to_window(conf->mlx, conf->win,
								conf->img->content.img, 0, 0);
	}
	return (1);
}

static int	expose_hook(t_initpara *conf)
{
	return (mlx_put_image_to_window(conf->mlx, conf->win,
			conf->img->content.img, 0, 0));
}

void	load_screen(t_initpara conf, bool save)
{
	conf.mlx = mlx_init();
	if (config.c_cameras == NULL)
		error_list(58);
	if (config.objects == NULL)
		error_list(59);
	image(&conf);
	if (save)
		ft_save(conf);
	else
	{
		conf.win = mlx_new_window(conf.mlx, conf.r_x, conf.r_y, "miniRT");
		mlx_hook(conf.win, 33, 1L << 17, closew, &conf);
		mlx_hook(conf.win, 2, 1, next_cam, &conf);
		mlx_expose_hook(conf.win, expose_hook, &conf);
		mlx_loop(conf.mlx);
	}
}
