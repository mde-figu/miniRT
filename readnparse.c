/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readnparse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirkios <mirkios@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 12:09:58 by mirkios           #+#    #+#             */
/*   Updated: 2021/04/11 17:02:23 by mirkios          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entries.h"
#include "src/canvas.h"
#include "src/components.h"
#include "src/parameters.h"

bool    readfile(t_initpara initpara, char *[])
{
	int     fd;
	int     hasline;
	int     obj_num;
	char    *entry;

	t_initpara->cams = NULL;
	t_initpara->lighting = NULL;
	t_initpara->objects = NULL;
	t_initpara->canvas = NULL;
	t_initpara->img = NULL;
	t_initpara->img_init = NULL;
	entry = NULL;
	if (!(fd = open(argv[1], O_RDONLY)))
		error_list(0);
	obj_num = 0;
	while ((hasline = get_next_line(fd, &entry)) > 0)
	{
		if ((entry != NULL && *entry != '\0' && *entry != '#')
			|| (entry != NULL && *entry != '\0'))
		{
			if(!validline(entry))
				return(false);
			initiate_parameters(&initpara, entry, obj_num);
			free(entry);
		}
		obj_num++;
	}
	obj_num++;
	return(true);
}