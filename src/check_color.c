/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 18:21:38 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/07 23:35:17 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

int	check_color(char *str)
{
	char	**tmp;
	t_color	cc;

	tmp = ft_split(str, ',');
	if (str_ptr_len(tmp) != 3)
		return (free_entry(&tmp));
	if (!is_num(tmp[0]) || !is_num(tmp[1]) || !is_num(tmp[2]))
		return (free_entry(&tmp));
	cc.red = (float)ft_atoi(tmp[0]);
	cc.green = (float)ft_atoi(tmp[1]);
	cc.blue = (float)ft_atoi(tmp[2]);
	if (cc.red < 0 || cc.red > 255 || cc.green < 0 || cc.green > 255
		|| cc.blue < 0 || cc.blue > 255)
		return(free_entry(&tmp));
	free_entry(&tmp);
	return (1);
}
