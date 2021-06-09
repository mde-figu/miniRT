/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_normal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:40:55 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/08 01:07:42 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

int	is_num(char *str)
{
	int i;

	if (!(str[0] == '-' || ft_isdigit(str[0])))
		return (0);
	i = 1;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
		{
			if (!(str[i] == '.'))
				return (0);
		}
		i++;
	}
	return (1);
}

int	is_unit(double x, double y, double z)
{
	if (fabs(sqrt(x * x + y * y + z * z) - 1) < EPSILON)
		return (1);
	return (0);
}

int	check_normal(char *str)
{
	char	**tmp;
	t_tuple t;

	tmp = ft_split(str, ',');
	if (str_ptr_len(tmp) != 3)
		return (free_entry(&tmp));
	if (!(is_num(tmp[0]) || is_num(tmp[1]) || is_num(tmp[2])))
		return (free_entry(&tmp));
	t.x = atof(tmp[0]);
	t.y = atof(tmp[1]);
	t.z = atof(tmp[2]);
	if (!is_unit(t.x, t.y, t.z))
		return (free_entry(&tmp));
	free_entry(&tmp);
	return (1);
}