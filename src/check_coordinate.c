/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_coordinate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:03:10 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/25 16:47:55 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

int	check_coordinate(char *str)
{
	char	**tmp;

	tmp = ft_split(str, ',');
	if (str_ptr_len(tmp) != 3)
	{
		free_entry(&tmp);
		return (0);
	}
	if (!is_num(tmp[0]) || !is_num(tmp[1]) || !is_num(tmp[2]))
	{
		free_entry(&tmp);
		return (0);
	}
	free_entry(&tmp);
	return (1);
}
