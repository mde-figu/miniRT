/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirkios <mirkios@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 21:38:03 by mirkios           #+#    #+#             */
/*   Updated: 2021/05/07 22:07:20 by mirkios          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

int	validate_square(char **entry_t)
{
	if (ft_str_dlen(entry_t) != 5)
		return (error_list(42));
	if (!check_coordinate(entry_t[1]))
		return (error_list(43));
	if (!check_normal(entry_t[2]))
		return (error_list(44));
	if (!is_num(entry_t[3]))
		return (error_list(45));
	if (atof(entry_t[3]) < 0)
		return (error_list(46));
	if (!check_color(entry_t[4]))
		return (error_list(47));
	return (1);
}
