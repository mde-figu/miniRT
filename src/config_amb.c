/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_amb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 20:51:04 by mde-figu          #+#    #+#             */
/*   Updated: 2021/05/15 21:12:26 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

void	config_amb(t_initpara *initpara, char *amb_ratio, char *amb_color)
{
	char	**tmp;
	t_color tmpc;
	double	ratio;

	ratio = atof(a_ratio);
	tmp = ft_split(a_color, ',');
	tmpc.red = (double)ft_atoi(tmp[0]);
	tmpc.green = (double)ft_atoi(tmp[1]);
	tmpc.blue = (double)ft_atoi(tmp[2]);
	initpara->a_color = scalar_color(tmpc, 0.003921569);
	free_entry(&tmp);
	free_entry(&tmpc);
}
