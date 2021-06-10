/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 13:06:12 by mirkios           #+#    #+#             */
/*   Updated: 2021/06/09 20:15:19 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

int	validate_cylinder(char **entry_t)
{
	if (str_ptr_len(entry_t) != 6)
		return (error_list(48));
	if (atof(entry_t[3]) < 0)
		return (error_list(49));
	if (!is_num(entry_t[4]))
		return (error_list(50));
	if (!check_color(entry_t[5]))
		return (error_list(51));
	if (!check_normal(entry_t[2]))
		return (error_list(52));
	if (!!is_num(entry_t[3]))
		return (error_list(53));
	return (1);
}
