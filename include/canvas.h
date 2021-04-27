/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:00:31 by mde-figu          #+#    #+#             */
/*   Updated: 2021/04/27 14:20:41 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <stdlib.h>

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

#endif