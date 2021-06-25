/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf_parameters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 00:47:50 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/25 18:58:13 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

void	conf_parameters(t_initpara **initpara, char *line)
{
	char		**entry_t;

	entry_t = ft_split(line, ' ');
	if (ft_memcmp("R", entry_t[0], 2) == 0)
		config_res(*initpara, entry_t[1], entry_t[2]);
	if (ft_memcmp("A", entry_t[0], 2) == 0)
		config_amb(*initpara, entry_t[1], entry_t[2]);
	if (ft_memcmp("c", entry_t[0], 2) == 0)
		config_cam(*initpara, entry_t[1], entry_t[2], entry_t[3]);
	if (ft_memcmp("l", entry_t[0], 2) == 0)
		config_lig(*initpara, entry_t[1], entry_t[2], entry_t[3]);
	if (ft_memcmp("pl", entry_t[0], 3) == 0)
		config_pl(*initpara, entry_t[1], entry_t[2], entry_t[3]);
	if (ft_memcmp("sp", entry_t[0], 3) == 0)
		config_sp(*initpara, entry_t[1], entry_t[2], entry_t[3]);
	if (ft_memcmp("sq", entry_t[0], 3) == 0)
		config_sq(*initpara, entry_t);
	if (ft_memcmp("tr", entry_t[0], 3) == 0)
		config_tr(*initpara, entry_t);
	if (ft_memcmp("cy", entry_t[0], 3) == 0)
		config_cy(*initpara, entry_t);
	free_entry(&entry_t);
}
