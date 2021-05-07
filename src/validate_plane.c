/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_plane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:45:51 by mde-figu          #+#    #+#             */
/*   Updated: 2021/05/07 17:31:34 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

int	validate_plane(char **entry_t)
{
	if (ft_str_dlen(entry_t) != 4)
		return (error_list(33));
	if (!check_coordinate(entry_t[1]))
		return (error_list(34));
	if (!check_normal(entry_t[2]))
		return (error_list(35));
	if (!check_color(entry_t[3]))
		return (error_list(36));
	return (1);
}
