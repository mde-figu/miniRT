/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readnparse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 12:09:58 by mirkios           #+#    #+#             */
/*   Updated: 2021/04/30 13:50:08 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/entries.h"
#include "include/canvas.h"
#include "include/components.h"
#include "include/parameters.h"

static	void	init_para(t_initpara *initpara)
{
	t_initpara->cams = NULL;
	t_initpara->lighting = NULL;
	t_initpara->objects = NULL;
	t_initpara->canvas = NULL;
	t_initpara->img = NULL;
	t_initpara->img_init = NULL;

}

int	readfile(t_initpara *initpara, char *[])
{
	int		fd;
	int		hasline;
	int		obj_num;
	char	*entry;

	entry = NULL;
	init_para(initpara);
	if (!(fd = open(argv[1], O_RDONLY)))
		error_list(0);
	obj_num = 0;
	while ((hasline = get_next_line(fd, &entry)) > 0)
	{
		if ((entry != NULL && *entry != '\0' && *entry != '#')
			|| (entry != NULL && *entry != '\0'))
		{
			if(!validate_line(entry))
				return(false);
			initiate_parameters(&initpara, entry, obj_num);
			free(entry);
		}
		obj_num++;
	}
	obj_num++;
	return(true);
}