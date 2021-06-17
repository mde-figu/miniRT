/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 21:38:03 by mirkios           #+#    #+#             */
/*   Updated: 2021/06/17 16:22:32 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

int	validate_square(char **entry_t)
{
	if (str_ptr_len(entry_t) != 5)
		return (error_list(42));
	if (!check_coordinate(entry_t[1]))
		return (error_list(43));
	if (!check_normal(entry_t[2]))
		return (error_list(44));
	if (!is_num(entry_t[3]))
		return (error_list(45));
	if (ft_atof(entry_t[3]) < 0)
		return (error_list(46));
	if (!check_color(entry_t[4]))
		return (error_list(47));
	return (1);
}
