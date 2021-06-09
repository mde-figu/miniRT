/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 20:37:15 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/07 21:55:22 by mde-figu         ###   ########.fr       */
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

static void touch_header(t_initpara conf, t_bmpheader *header)
{
	header->type = 0x4D42;
	header->size = ((conf.res_x + conf.res_y) * 4) + 54;
	header->reserved = 0x0;
	header->offset = 54;
	header->dib_header_size = 40;
	header->width_px = conf.res_x;
	header->height_px = conf.res_y;
	header->num_planes = 1;
	header->bpp = 32;
	header->compression = 0;
	header->img_size_bytes = ((conf.res_x + conf.res_y) * 4);
	header->x_resolution_ppm = 2000;
	header->y_resolution_ppm = 2000;
	header->num_colors = 0;
	header->important_colors = 0;
}
static int	touch_bmp(char *filename)
{
	int		fd;
	char	*name;

	name = ft_strjoin(filename, ".bmp");
	fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0666); //mode tem a mesma caracteristica que o chmod
	if(!fd)
		return (error_list(60));
	free(name);
	return (fd);
}

static void	save_it(t_initpara conf, t_data mlx, int tag)
{
	char		*name;
	t_bmpheader	head;
	int			fd;
	int			y;

	y = conf.res_y;
	name = ft_strjoin("camera_", ft_itoa(tag));
	fd = touch_bmp(name);
	touch_header(conf, &head);
	init_bmpheader(fd, head);
	while (--y >= 0)
	{
		write(fd, &mlx.address[y * mlx.line_length], mlx.line_length);
	}
	close(fd);
	free(name);
}

void	save(t_initpara conf)
{
	int		tag;
	t_imgg	*tmp;

	tag = 1;
	tmp = conf.img;
	while (tmp->next)
	{
		save_it(conf, tmp->content, tag);
		tag++;
		tmp = tmp->next;
	}
	save_it(conf, tmp->content, tag);
}
