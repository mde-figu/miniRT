/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 21:38:03 by mirkios           #+#    #+#             */
/*   Updated: 2021/06/25 22:19:38 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

int	validate_square(char **entry_t)
{
	if (str_ptr_len(entry_t) != 5)
		return (error_list(32));
	if (!check_coordinate(entry_t[1]))
		return (error_list(33));
	if (!check_normal(entry_t[2]))
		return (error_list(34));
	if (!is_num(entry_t[3]))
		return (error_list(35));
	if (ft_atof(entry_t[3]) < 0)
		return (error_list(36));
	if (!check_color(entry_t[4]))
		return (error_list(37));
	return (1);
}
