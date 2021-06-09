/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entries.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:23:16 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/08 01:05:56 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTRIES_H
# define ENTRIES_H
# define EPSILON 0.00001
# include "../libft/libft.h"
# include "../get_next_line/get_next_line_bonus.h"
# include "../minilibx/minilibx-linux/mlx.h"
# include "../minilibx/minilibx-linux/mlx_int.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdint.h>
# include <string.h>
# include <math.h>
# include "components.h"
# include "canvas.h"
# include "parameters.h"

typedef struct s_initpara
{
	int			res_x;
	int			res_y;
	int			num_objects;
	int			save;
	bool		lightonoff;
	t_color		init_color;
	t_color		ambient;
	t_camera	*cams;
	t_canvas	*canvas;
	t_lights	*lighting;
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

typedef struct s_shadepar
{
	t_initpara			world;
	t_comps				comps;
	bool				shadowed;
}						t_shadepar;



int			error_list(int error_nbr);
bool		validate(int argc, char *argv[]);
bool		rt_preparser(char *rt_file);
int			validate_res(char **entry_t);
int			validate_amb(char **entry_t);
int			validate_cam(char **entry_t);
int			str_ptr_len(char **s);
int			validate_light(char **entry_t);
int			validate_plane(char **entry_t);
int			validate_sphere(char **entry_t);
int			validate_square(char **entry_t);
int			validate_cylinder(char **entry_t);
int			validate_triangle(char **entry_t);

int			check_coordinate(char *str);
int			check_normal(char *str);
int			check_color(char *str);
int			is_unit(double x, double y, double z);
int			is_num(char *str);
bool		float_compare(float a, float b);

t_object	plane(void);
t_object	square(void);
t_object	sphere(void);
t_object	cylinder(void);

t_color		list_color(t_initpara initpara, t_ray ray);
void		config_res(t_initpara *initpara, char *res_x, char *res_y);
t_list		*intersect_world(t_initpara w, t_ray r);
int			free_entry(char ***entry);
void		image(t_initpara *conf);
void		save(t_initpara conf);

void		set_world(t_world *world, t_initpara initpara);

void		bubblesort(t_list **xs);

#endif