/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:20:30 by mde-figu          #+#    #+#             */
/*   Updated: 2021/05/05 17:43:48 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

int validate_light(char **entry_t)
{
	if (ft_str_dlen(entry_t) != 4)
		return(error_list(29));
	if (!check_coordinate(entry_t[1]))
		return(error_list(30));
	if (!is_num(entry_t[2]))
		return(error_list(31));
	if (atof(entry_t[2]) < 0 || atof(entry_t[2]) > 1)
		return(error_list(31));
	if (!is_color(entry_t[3]))
		return(error_list(32))
	return (1);
}