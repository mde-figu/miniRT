/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_canvas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:44:33 by mde-figu          #+#    #+#             */
/*   Updated: 2021/05/19 20:20:40 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

void	make_canvas(t_initpara *initpara)
{
	t_canvas	c;
	t_camera		*cam;

	if (initpara->cams == NULL || initpara->objects == NULL)
	{
		c = create_canvas(initpara->res_x, initpara->res_y);
		list_canvas(&initpara->canvas, c);
	}
	else
	{
		cam = initpara->cams;
		while (cam->next)
		{
			c = render(cam->content, initpara);
			list_canvas(&config->canvas, c);
			cam = cam->next;
		}
		c = render(cam->content, initpara);
		list_canvas(&initpara->canvas, c);
	}
}