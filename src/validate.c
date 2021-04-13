/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirkios <mirkios@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 19:55:47 by mde-figu          #+#    #+#             */
/*   Updated: 2021/04/11 11:51:25 by mirkios          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

bool	rt_preparser(char *rt_file)
{
	char *tmp;
	bool ret;

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