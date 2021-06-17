/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:00:31 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/16 13:52:47 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <stdlib.h>
# include "entries.h"
# include "components.h"
# include "parameters.h"

typedef struct s_bmpheader
{
	uint16_t		type;
	uint32_t		size;
	uint16_t		reserved;
	uint32_t		offset;
	uint32_t		dib_header_size;
	int32_t			width_px;
	int32_t			height_px;
	uint16_t		num_planes;
	uint16_t		bpp;
	uint32_t		compression;
	uint32_t		img_size_bytes;
	int32_t			x_resolution_ppm;
	int32_t			y_resolution_ppm;
	uint32_t		num_colors;
	uint32_t		important_colors;
}					t_bmpheader;

//typedef struct s_mlx
//{
//	void			*mlx;
//	void			*win;
//	t_camera		*cam;
//	t_camera		*begin;
//	int				bpp;
//	int				line_leng;
//	int				endian;
//	t_rt			*rt;
//}					t_mlx;

typedef struct	s_data
{
	void		*image;
	char		*address;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct	s_imgg
{
	t_data		content;
	struct	s_imgg *next;
}				t_imgg;

typedef struct s_canvas
{
	int				width;
	int				height;
	t_color			**pixel;
}						t_canvas;

typedef struct s_pixel
{
	int				x;
	int				y;
}						t_pixel;

typedef struct s_canvasl
{
	t_canvas			content;
	struct s_canvasl	*next;
}						t_canvasl;

typedef struct s_beamoffset
{
	t_ray				r;
	double				xoffset;
	double				yoffset;
	double				world_x;
	double				world_y;
}						t_beamoffset;

typedef struct s_intersect
{
	double				t;
	t_object			object;
	bool				valid;
}						t_intersect;

typedef struct s_interl
{
	t_intersect		content;
	struct s_interl		*next;
}						t_interl;

typedef struct s_sphinter
{
	t_intersect			i1;
	t_intersect			i2;
	t_tuple				sphere_to_ray;
	t_tuple				p;
	double				discriminant;
	t_matrix			inv;
}						t_sphinter;

typedef struct s_trinter
{
	t_intersect			i1;
	double				det;
	double				f;
	double				u;
	double				v;
	double				t;
}						t_trinter;

typedef struct s_cyinter
{
	double				a;
	double				b;
	double				c;
	double				t0;
	double				t1;
	double				temp;
	double				y0;
	double				y1;
	double				discriminant;
	t_intersect			i1;
	int					cc;
}						t_cyinter;

typedef struct s_capinter
{
	t_interl			*xs;
	t_interl			*xs_cap;
}						t_capinter;

void				create_canvas(t_canvas *canvas, int width, int height);
void				free_canvas(t_canvas canvas);
void				list_canvas(t_canvasl **l, t_canvas canvas);
t_ray				ray_to_pixel(t_camera camera, double px, double py);
void				write_pixel(t_canvas *canvas,
						int width, int height, t_color color_init);
void				cameras(t_cameras **l, t_camera c);
int					list_size_cam(t_cameras *lst);
t_cameras			*list_new_cam(t_camera content);
int					lst_size_img(t_imgg *img);
int					list_size_inter(t_interl *lst);
void				list_clear_inter(t_interl **lst);
t_interl			*list_new_inter(t_intersect content);
void				list_addback_inter(t_interl **lst, t_interl *new);
void				list_clear_inter(t_interl **lst);
t_imgg				*list_new_img(t_data img);
void				list_clear_img(t_imgg **img);
int					list_size_img(t_imgg *img);

t_ray				ray(t_tuple origin, t_tuple direction);
t_tuple				posit(t_ray ray, double t);
t_intersect			ray_hit(t_interl *xs);

t_color				lighting(t_colcomp p);

t_intersect			intersection(double t, t_object o);
t_interl			*intersect(t_object s, t_ray ray);
t_interl			*intersect_plane(t_object p, t_ray ray);
t_interl			*intersect_square(t_object p, t_ray ray);
t_interl			*intersect_triangle(t_object triangle, t_ray ray);
t_interl			*intersect_sphere(t_object s, t_ray ray);
t_interl			*intersect_cylinder(t_object cyl, t_ray ray);
t_interl			*cyl_inter_aux(t_cyinter p, t_ray ray, t_capinter *c,
					t_object cy1);
t_interl			*intersect_caps(t_object cyl, t_ray ray);
t_comps				pre_comp(t_intersect i, t_ray r);
void				list_clear_inter(t_interl **lst);

void				arrange_pixels(t_data *data, int x, int y, int color);
void				store_img(t_imgg **l, t_data img);

#endif