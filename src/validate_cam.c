/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_cam.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 13:31:40 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/22 00:36:11 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

int		validate_cam(char **entry_t)
{
	if (str_ptr_len(entry_t) != 4)
		return (error_list(29));
	if (!check_coordinate(entry_t[1]))
		return (error_list(30));
	if (!check_normal(entry_t[2]))
		return (error_list(31));
	if (!is_num(entry_t[3]))
		return (error_list(32));
	if (ft_atof(entry_t[3]) < 0 || ft_atof(entry_t[3]) > 180)
		return (error_list(32));
	return (1);
}
