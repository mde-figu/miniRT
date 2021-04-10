/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 18:10:01 by mde-figu          #+#    #+#             */
/*   Updated: 2021/04/09 19:39:49 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/entries.h"

int		main(int argc, char *argv[])
{
	t_initpara initpara;

	validate(argc, argv);
	initpara.save = save_on(argc);
	readfile(&initpara, argv);
	if (initpara.objects != NULL)
		set_world(&initpara);
	create_canvas(&initpara);
	render(initpara);
	return (0);
}