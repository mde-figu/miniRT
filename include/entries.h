/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entries.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:23:16 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/18 00:36:24 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTRIES_H
# define ENTRIES_H
# define EPSILON 0.0001
# define PIE 3.14159265358979323846264338
# include "../libft/libft.h"
# include "../get_next_line/get_next_line_bonus.h"
# include "../minilibx/minilibx-linux/mlx.h"
# include "../minilibx/minilibx-linux/mlx_int.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdint.h>
# include <unistd.h>
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
	t_cameras	*cams;
	t_canvasl	*canvas;
	t_lights	*lighting;
	t_lights	*world_lights;
	t_objects	*objects;
	t_objects	*world_objects;
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

typedef struct s_pixiter
{
	int					yy;
	int					xx;
}						t_pixiter;

void		splash(void);

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
int			validate_line(char *entry);

void		conf_parameters(t_initpara **initpara, char *line);
void		config_res(t_initpara *initpara, char *res_x, char *res_y);
void		config_amb(t_initpara *initpara, char *amb_ratio, char *amb_color);
void		config_cam(t_initpara *initpara, char *ps, char *n, char *fov);
void		config_cy(t_initpara *initpara, char **entry_t);
void		config_lig(t_initpara *initpara, char *ps, char *br, char *col);
void		config_pl(t_initpara *initpara, char *pos, char *n, char *col);
void		config_sp(t_initpara *initpara, char *pos, char *dia, char *col);
void		config_sq(t_initpara *initpara, char *pos, char *n,
						char *s, char *col);
void		config_tr(t_initpara *initpara, char **entry_t);

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
t_object	triangle(int id, t_tuple p1, t_tuple p2, t_tuple p3);


t_color		list_color(t_initpara initpara, t_ray ray);
t_interl	*intersect_world(t_initpara w, t_ray r);
int			free_entry(char ***entry);
void		image(t_initpara *conf);
void		save(t_initpara conf);
int			save_on(int argc);
void		set_world(t_initpara *initpara);
void		ini_world(t_initpara *initpara, t_object content);
void		create_light(t_initpara *initpara, t_light light);
void		make_canvas(t_initpara *initpara);
void		load_screen(t_initpara conf, bool savei);
void		render(t_canvas *canvas, t_camera camera, t_initpara initpara);
t_color		shadding(t_initpara w, t_comps comp);
int			readfile(t_initpara *initpara, char *argv[]);


void		bubblesort(t_interl **xs);

#endif