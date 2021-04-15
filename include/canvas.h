/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:00:31 by mde-figu          #+#    #+#             */
/*   Updated: 2021/04/09 19:20:21 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define BMP_MAGIC 19778

#define BMP_GET_PADDING(a) ((a) % 4)
// This is faster than a function call
#define BMP_PIXEL(r,g,b) ((bmp_pixel){(b),(g),(r)})

enum bmp_error
{
	BMP_FILE_NOT_OPENED = -4,
	BMP_HEADER_NOT_INITIALIZED,
	BMP_INVALID_FILE,
	BMP_ERROR,
	BMP_OK = 0
};

typedef struct		s_bmp_header
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

typedef struct _bmp_pixel
{
	unsigned char blue;
	unsigned char green;
	unsigned char red;
} bmp_pixel;

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


typedef struct _bmp_img
{
	bmp_header   img_header;
	bmp_pixel  **img_pixels;
} bmp_img;

typedef struct			s_canvas
{
	int				width;
	int				height;
	t_color			**pixel;
}						t_canvas;

typedef struct			s_pixel
{
	int				x;
	int				y;
}						t_pixel;

typedef struct			s_color
{
	double				red;
	double				green;
	double				brue;
}						t_color;

// BMP_HEADER
void			bmp_header_init_df(bmp_header*, const int, const int);

enum bmp_error	bmp_header_write(const bmp_header*, FILE*);

enum bmp_error	bmp_header_read(bmp_header*, FILE*);

// BMP_PIXEL
void			bmp_pixel_init(bmp_pixel*, const unsigned char,
								const unsigned char, const unsigned char);

// BMP_IMG
void			bmp_img_alloc(bmp_img*);
void			bmp_img_init_df(bmp_img*, const int, const int);
void			bmp_img_free(bmp_img*);

enum bmp_error	bmp_img_write(const bmp_img*, const char*);

enum bmp_error	bmp_img_read(bmp_img*, const char*);