/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 19:55:47 by mde-figu          #+#    #+#             */
/*   Updated: 2021/04/30 19:02:57 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

bool	rt_preparser(char *rt_file)
{
	char	*tmp;
	bool	ret;

	ret = false;
	tmp = ft_strchr(rt_file, '.');
	if (ft_memcmp(".rt", temp, 4) == 0)
		ret = true;
	return(resp);
}

bool	validate(int argc, char *argv[])
{
	char		*error;

	error = NULL;
	if (argc < 2)
	{
		error_list(1);
		return	(true);
	}
	if (argc > 3)
	{
		error_list(2);
		return	(true);
	}
	if (!rt_preparser(argv[1]))
	{
		error_list(3);
		return	(true);
	}
	if (argc == 3 && ft_memcmp("--save", argv[2],7) != 0)
	{
		error_list(4);
		return	(true);
	}
	return(false);
}

static int	validate_config(char **entry_t)
{
	if (ft_memcmp("R", entry_t[0], 2) == 0)
		return (validate_res(entry_t));
	else if (ft_memcmp("A", entry_t[0], 2) == 0)
		return (validate_amb(entry_t));
	else if (ft_memcmp("c", entry_t[0], 2) == 0)
		return (validate_cam(entry_t));
	else if (ft_memcmp("l", entry_t[0], 2) == 0)
		return (validate_light(entry_t));
	return (0);
}

static int	validate_geometry(char **entry_t)
{
	if (ft_memcmp("pl", entry_t[0], 3) == 0)
		return (validate_plane(entry_t));
	if (ft_memcmp("sp", entry_t[0], 3) == 0)
		return (validate_sphere(entry_t));
	if (ft_memcmp("sq", entry_t[0], 3) == 0)
		return (validate_square(entry_t));
	if (ft_memcmp("cy", entry_t[0], 3) == 0)
		return (validate_cylinder(entry_t));
	if (ft_memcmp("tr", entry_t[0], 3) == 0)
		return (validate_triangle(entry_t));
	return (0);
}

int	validate_line(char *entry)
{
	char	**entry_t;
	int		ret;

	ret = 0;
	entry_t = ft_split(entry, ' ');
	if (ret == 0)
		ret = validate_config(entry_t);
	else if (ret == 0)
		ret = validate_geometry(entry_t);
	else
		error_list(20);
	free_entry(&entry_t);
	return (ret);
}
