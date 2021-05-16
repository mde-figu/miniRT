/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entries.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:23:16 by mde-figu          #+#    #+#             */
/*   Updated: 2021/05/11 14:18:13 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTRIES_H
# define ENTRIES_H
# include "../libft/libft.h"
# include "../get_next_line/get_next_line_bonus.h"
# include "canvas.h"
# include "components.h"
# include "parameters.h"
# include <stdio.h>
# include <string.h>
# include <math.h>

typedef struct s_initpara
{
	int			res_x;
	int			res_y;
	int			num_objects;
	int			save;
	bool		lightonoff;
	t_color		init_color;
	t_color		ambient;
	t_cam		*cams;
	t_canvas	*canvas;
	t_light		*lighting;
	t_objects	*objects;
	t_imgg		*img;
	t_imgg		*img_init;
	void		*mlx;
	void		*win;
}				t_initpara;

typedef struct s_line_fd
{
	int		fd;
	int		ii;
	char	*line;
}				t_line_fd;

bool	validate(int argc, char *argv[]);
bool	rt_preparser(char *rt_file);