/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_amb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 13:29:37 by mirkios           #+#    #+#             */
/*   Updated: 2021/06/03 19:03:17 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static int	ft_str_dlen(char **s)
{
	int len;

	if (!s)
		return (0);
	len = 0;
	while (*s++)
	{
		len++;
	}
	return (len);
}

static int amb_color(char *amb_para)
{
	char	**tmp;
	t_color amb_color;

	tmp = ft_split(amb_para, ',');
	if (ft_str_dlen(tmp) != 3 || !is_num(tmp[0]) || !is_num(tmp[1]) ||
		!is_num(tmp[2]))
	{
		free_entry(&tmp);
		return (0);
	}
	amb_color.red = (double)ft_atoi(tmp[0]);
	amb_color.green = (double)ft_atoi(tmp[1]);
	amb_color.blue = (double)ft_atoi(tmp[2]);
	if (amb_color.red < 0 || amb_color.red > 255 || amb_color.green < 0 ||
		amb_color.green > 255 || amb_color.blue < 0 || amb_color.blue > 255)
	{
		free_entry(&tmp);
		return (0);
	}
}
int validate_amb(char **entry_t)
{
	if (ft_str_len(entry_t) != 3)
	{
		error_list(23);
		return (0);
	}
	if (!ft_isdigit(*entry_t[1]) || atof(entry_t) < 0 || atof(entry_t) > 1)
	{
		error_list(24);
		return (0);
	}
	if (!amb_color(entry_t[2]))
	{
		error_list(25);
		return (0);
	}
	return (1);
}
