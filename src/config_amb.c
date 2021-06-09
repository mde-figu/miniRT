/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_amb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 20:51:04 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/06 23:22:40 by mde-figu         ###   ########.fr       */
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

	ratio = atof(amb_ratio);
	tmp = ft_split(amb_color, ',');
	r = (double)ft_atoi(tmp[0]);
	g = (double)ft_atoi(tmp[1]);
	b = (double)ft_atoi(tmp[2]);
	initpara->ambient = create_color((r / 255) * ratio, (g / 255)
			* ratio, (b / 255) * ratio);
	free_entry(&tmp);
}
