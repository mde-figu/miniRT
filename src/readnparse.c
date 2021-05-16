/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readnparse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 12:09:58 by mirkios           #+#    #+#             */
/*   Updated: 2021/05/11 15:31:52 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/entries.h"
#include "include/canvas.h"
#include "include/components.h"
#include "include/parameters.h"

static	void	init_para(t_initpara *initpara, t_line_fd *l)
{
	t_initpara->cams = NULL;
	t_initpara->lighting = NULL;
	t_initpara->objects = NULL;
	t_initpara->canvas = NULL;
	t_initpara->img = NULL;
	t_initpara->img_init = NULL;
	l->line = NULL;

}

static int	ft_aux(char *line, t_initpara *initpara)
{
	if (line != NULL && *line != '\0')
	{
		if (!validate_line(line))
			return (0);
		conf_parameters(&config, line);
		free(line);
	}
	return (1);
}

int	readfile(t_initpara *initpara, char *[])
{
	t_line_fd l;

	init_para(initpara, &l);
	l.fd = open(argv[1], O_RDONLY);
	if (!l.fd)
		error_list(0);
	l.ii = get_next_line(p.fd, &p.line)
	while ((l.line > 0)
	{
		if (l.line != NULL && *l.line != '\0' && *l.line != '#')
		{
			if(!validate_line(entry))
				return(false);
			conf_parameters(&initpara, entry, obj_num);
			free(entry);
		}
		l.ii = get_next_line(l.fd, &l.line)
	}
	return(ft_aux(l.line, initpara)
}
