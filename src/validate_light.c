/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:20:30 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/23 14:03:41 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

int	validate_light(char **entry_t)
{
	if (str_ptr_len(entry_t) != 4)
		return (error_list(19));
	if (!check_coordinate(entry_t[1]))
		return (error_list(20));
	if (!is_num(entry_t[2]))
		return (error_list(21));
	if (ft_atof(entry_t[2]) < 0 || ft_atof(entry_t[2]) > 1)
		return (error_list(21));
	if (!check_color(entry_t[3]))
		return (error_list(22));
	return (1);
}
