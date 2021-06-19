/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 20:37:15 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/18 21:21:56 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

static void	init_bmpheader(int fd, t_bmpheader header)
{
	write(fd, &header.type, 2);
	write(fd, &header.size, 4);
	write(fd, &header.reserved, 4);
	write(fd, &header.offset, 4);
	write(fd, &header.dib_header_size, 4);
	write(fd, &header.width_px, 4);
	write(fd, &header.height_px, 4);
	write(fd, &header.num_planes, 2);
	write(fd, &header.bpp, 2);
	write(fd, &header.compression, 4);
	write(fd, &header.img_size_bytes, 4);
	write(fd, &header.x_resolution_ppm, 4);
	write(fd, &header.y_resolution_ppm, 4);
	write(fd, &header.num_colors, 4);
	write(fd, &header.important_colors, 4);
}

static void	touch_header(t_initpara initpara, t_bmpheader *header)
{
	header->type = 0x4D42;
	header->size = ((initpara.res_x + initpara.res_y) * 4) + 54;
	header->reserved = 0x0;
	header->offset = 54;
	header->dib_header_size = 40;
	header->width_px = initpara.res_x;
	header->height_px = initpara.res_y;
	header->num_planes = 1;
	header->bpp = 32;
	header->compression = 0;
	header->img_size_bytes = ((initpara.res_x + initpara.res_y) * 4);
	header->x_resolution_ppm = 2000;
	header->y_resolution_ppm = 2000;
	header->num_colors = 0;
	header->important_colors = 0;
}

static int	touch_bmp(char *name)
{
	int		fd;
	char	*filename;

	filename = ft_strjoin(name, ".bmp");
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	free(filename);
	return (fd);
}

static void	save_it(t_initpara initpara, t_data mlx, int tag)
{
	char		*name;
	t_bmpheader	header;
	int			fd;
	int			y;

	y = initpara.res_y;
	name = ft_strjoin("cam_", ft_itoa(tag));
	fd = touch_bmp(name);
	touch_header(initpara, &header);
	init_bmpheader(fd, header);
	while (--y >= 0)
	{
		write(fd, &mlx.address[y * mlx.line_length], mlx.line_length);
	}
	close(fd);
	free(name);
}

void	save(t_initpara initpara)
{
	int		tag;
	t_imgg	*tmp;

	tag = 1;
	tmp = initpara.img;
	while (tmp->next)
	{
		save_it(initpara, tmp->content, tag);
		tag++;
		tmp = tmp->next;
	}
	save_it(initpara, tmp->content, tag);
}
