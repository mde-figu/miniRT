/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_plane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:45:51 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/23 14:11:49 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

int	validate_plane(char **entry_t)
{
	if (str_ptr_len(entry_t) != 4)
		return (error_list(23));
	if (!check_coordinate(entry_t[1]))
		return (error_list(24));
	if (!check_normal(entry_t[2]))
		return (error_list(25));
	if (!check_color(entry_t[3]))
		return (error_list(26));
	return (1);
}
