/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readnparse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 12:09:58 by mirkios           #+#    #+#             */
/*   Updated: 2021/06/22 15:58:53 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

static	void	init_para(t_initpara *initpara, t_line_fd *l)
{
	initpara->res_x = 10;
	initpara->res_y = 10;
	initpara->num_objects = 0;
	initpara->save = 0;
	initpara->lightonoff = false;
	initpara->init_color = create_color(0, 0, 0);
	initpara->ambient = create_color(0, 0, 0);
	initpara->world_lights = NULL;
	initpara->world_objects = NULL;
	initpara->mlx = NULL;
	initpara->win = NULL;
	initpara->cams = NULL;
	initpara->lighting = NULL;
	initpara->objects = NULL;
	initpara->canvas = NULL;
	initpara->img = NULL;
	initpara->img_init = NULL;
	l->line = NULL;
}

static int	ft_aux(char *line, t_initpara *initpara)
{
	if (line != NULL && *line != '\0')
	{
		if (!validate_line(line))
			return (0);
		conf_parameters(&initpara, line);
		free(line);
	}
	return (1);
}

int	readfile(t_initpara *initpara, char *argv[])
{
	t_line_fd	l;

	init_para(initpara, &l);
	l.fd = open(argv[1], O_RDONLY);
	if (!l.fd)
		error_list(0);
	l.ii = get_next_line(l.fd, &l.line);
	while (l.ii > 0)
	{
		if (l.line != NULL && *l.line != '\0' && *l.line != '#')
		{
			if (!validate_line(l.line))
				return (false);
			conf_parameters(&initpara, l.line);
			free(l.line);
		}
		l.ii = get_next_line(l.fd, &l.line);
	}
	return (ft_aux(l.line, initpara));
}
