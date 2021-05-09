/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_cam.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 13:31:40 by mde-figu          #+#    #+#             */
/*   Updated: 2021/05/05 17:03:58 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

int		validate_cam(char **entry_t)
{
	if (ft_str_dlen(entry_t) != 4)
		return (error_list(25));
	if (!check_coordinate(entry_t[1]))
		return (error_list(26));
	if (!check_normal(entry_t[2]))
		return (error_list(27));
	if (!is_num(entry_t[3]))
		return (error_list(28));
	if (atof(entry_t[3]) < 0 || atof(entry_t[3]) > 180)
		return (error_list(28));
	return (1);
}