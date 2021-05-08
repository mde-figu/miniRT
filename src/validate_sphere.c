/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirkios <mirkios@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 20:54:14 by mirkios           #+#    #+#             */
/*   Updated: 2021/05/07 21:16:59 by mirkios          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

int	validate_sphere(char **entry_t)
{
	if (ft_str_dlen(entry_t) != 4)
		return (error_list(37));
	if (!check_coordinate(entry_t[1]))
		return (error_list(38));
	if (!is_num(entry_t[2]))
		return (error_list(39));
	if (atof(entry_t[2]) < 0)
		return (error_list(40));
	if (check_color(entry_t[3]))
		return (error_list(41));
	return (1);
}
