/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_triangle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirkios <mirkios@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 13:28:02 by mirkios           #+#    #+#             */
/*   Updated: 2021/05/08 13:37:19 by mirkios          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

int validate_triangle(char **entry_t)
{
    if (ft_str_dlen(entry_t) != 5)
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
