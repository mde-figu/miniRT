/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 19:55:47 by mde-figu          #+#    #+#             */
/*   Updated: 2021/04/09 20:19:49 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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