/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_cam.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 13:31:40 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/23 13:57:17 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

int	validate_cam(char **entry_t)
{
	if (str_ptr_len(entry_t) != 4)
		return (error_list(15));
	if (!check_coordinate(entry_t[1]))
		return (error_list(16));
	if (!check_normal(entry_t[2]))
		return (error_list(17));
	if (!is_num(entry_t[3]))
		return (error_list(18));
	if (ft_atof(entry_t[3]) < 0 || ft_atof(entry_t[3]) > 180)
		return (error_list(18));
	return (1);
}
