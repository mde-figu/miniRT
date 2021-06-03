/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:00:31 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/03 17:09:39 by mde-figu         ###   ########.fr       */
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

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	t_cam			*cam;
	t_cam			*begin;
	int				bpp;
	int				line_leng;
	int				endian;
	t_rt			*rt;
}					t_mlx;

typedef struct	s_imgg
{
	t_data		content
	struct	s_imgg *next;
}				t_imgg;

typedef struct	s_data
{
	void		*image;
	char		*address;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data

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

typedef struct s_color
{
	double				red;
	double				green;
	double				brue;
}						t_color;

typedef struct s_material
{
	t_color				color;
	double				ambient;
	double				diffuse;
	double				specular;
	double				shininess;
}						t_material;

typedef struct s_canvas
{
	int					width;
	int					height;
	t_color				**pixel;
}						t_canvas;

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

typedef struct s_ray
{
	t_tuple				origin;
	t_tuple				direction;
}						t_ray;

typedef struct s_intersect
{
	double				t;
	t_object			object;
	bool				valid;
}						t_intersect;

typedef struct s_sphinter
{
	t_intersection		i1;
	t_intersection		i2;
	t_tuple				sphere_to_ray;
	t_tuple				p;
	double				discriminant;
	t_matrix			inv;
}						t_sphinter;

typedef struct s_trinter
{
	t_intersection		i1;
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
	t_intersection		i1;
	int					cc;
}						t_cyinter;

typedef struct s_capinter
{
	t_list				*xs;
	t_list				*xs_cap;
}						t_capinter;

typedef struct s_camera
{
	int					hsize;
	int					vsize;
	double				field_of_view;
	t_matrix			transform;
	double				half_width;
	double				half_height;
	double				pixel_size;
}						t_camera;

#endif