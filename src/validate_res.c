/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_res.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 19:34:22 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/22 00:19:38 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

static int	config_para_check(char **entry_t)
{
	int	len;

	if (!entry_t)
		return (0);
	len = 0;
	while (*entry_t++)
		len++;
	if (len != 3)
	{
		error_list(12);
		return (0);
	}
	return (1);
}

int	validate_res(char **entry_t)
{
	if (config_para_check(entry_t) == 0)
		return (0);
	else if (!ft_isdigit(*entry_t[1]) || !ft_isdigit(*entry_t[2]))
	{
		error_list(12);
		return (0);
	}
	else if (ft_atof(entry_t[1]) < 0 || ft_atof(entry_t[2]) < 0)
	{
		error_list(12);
		return (0);
	}
	return (1);
}
