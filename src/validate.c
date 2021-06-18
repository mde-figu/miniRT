/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 19:55:47 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/17 19:23:45 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

bool	rt_preparser(char *rt_file)
{
	char	*tmp;
	bool	ret;

	ret = false;
	tmp = ft_strchr(rt_file, '.');
	if (tmp == NULL)
		return (ret);
	if (ft_memcmp(".rt", tmp, 4) == 0)
		ret = true;
	return (ret);
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

int	validate_line(char *line)
{
	char	**entry_t;
	int		ret;

	ret = 0;
	entry_t = ft_split(line, ' ');
	if (ret == 0)
		ret = validate_config(entry_t);
	if (ret == 0)
		ret = validate_geometry(entry_t);
	else
		error_list(20);
	free_entry(&entry_t);
	return (ret);
}

bool	validate(int argc, char *argv[])
{
	if (argc < 2)
	{
		error_list(1);
		return (true);
	}
	if (argc > 3)
	{
		error_list(2);
		return (true);
	}
	if (!rt_preparser(argv[1]))
	{
		error_list(3);
		return (true);
	}
	if (argc == 3 && ft_memcmp("--save", argv[2], 7) != 0)
	{
		error_list(4);
		return (true);
	}
	return (false);
}
