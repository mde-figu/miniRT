/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_triangle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 13:28:02 by mirkios           #+#    #+#             */
/*   Updated: 2021/06/08 00:59:53 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

int validate_triangle(char **entry_t)
{
	if (str_ptr_len(entry_t) != 5)
		return (error_list(54));
	if (!check_coordinate(entry_t[1]))
		return (error_list(55));
	if (!check_coordinate(entry_t[2]))
		return (error_list(55));
	if (!check_coordinate(entry_t[3]))
		return (error_list(55));
	if (!check_color(entry_t[4]))
		return (error_list(56));
	return (1);
}
