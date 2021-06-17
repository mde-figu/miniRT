/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 20:54:14 by mirkios           #+#    #+#             */
/*   Updated: 2021/06/17 16:22:24 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

int	validate_sphere(char **entry_t)
{
	if (str_ptr_len(entry_t) != 4)
		return (error_list(37));
	if (!check_coordinate(entry_t[1]))
		return (error_list(38));
	if (!is_num(entry_t[2]))
		return (error_list(39));
	if (ft_atof(entry_t[2]) < 0)
		return (error_list(40));
	if (check_color(entry_t[3]))
		return (error_list(41));
	return (1);
}
