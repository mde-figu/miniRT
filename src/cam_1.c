/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:34:49 by mde-figu          #+#    #+#             */
/*   Updated: 2021/05/16 16:58:32 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/canvas"

void	cameras(t_cameras **l, t_camera c)
{
	t_cameras	*tmp;

	if (list_size_cam(*l) == 0)
		*l = list_new_cam(c);
	else
	{
		tmp = *l;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = list_new_cam(c);
	}
}
