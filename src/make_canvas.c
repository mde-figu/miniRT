/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_canvas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:44:33 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/21 18:22:57 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

void	make_canvas(t_initpara *initpara)
{
	t_canvas	canvas;
	t_cameras	*cam;

	if (initpara->cams == NULL || initpara->objects == NULL)
	{
		create_canvas(&canvas, initpara->res_x, initpara->res_y);
		list_canvas(&initpara->canvas, canvas);
	}
	else
	{
		cam = initpara->cams;
		while (cam->next)
		{
			render(&canvas, cam->content, *initpara);
			list_canvas(&initpara->canvas, canvas);
			loading_bar(1.0, 10, *initpara);
			cam = cam->next;
		}
		render(&canvas, cam->content, *initpara);
		list_canvas(&initpara->canvas, canvas);
	}
}
