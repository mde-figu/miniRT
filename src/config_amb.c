/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_amb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 20:51:04 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/25 21:05:59 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

void	config_amb(t_initpara *initpara, char *amb_ratio, char *amb_color)
{
	char	**tmp;
	double	r;
	double	g;
	double	b;
	double	ratio;

	ratio = ft_atof(amb_ratio);
	tmp = ft_split(amb_color, ',');
	r = ft_atoi(tmp[0]);
	g = ft_atoi(tmp[1]);
	b = ft_atoi(tmp[2]);
	initpara->init_color = create_color((r / 255) * ratio, (g / 255)
			* ratio, (b / 255) * ratio);
	free_entry(&tmp);
}
