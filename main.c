/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 18:10:01 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/16 17:45:30 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/entries.h"

int	main(int argc, char *argv[])
{
	t_initpara	initpara;

	splash();
	validate(argc, argv);
	initpara.save = save_on(argc);
	readfile(&initpara, argv);
	//intro goes here
	if (initpara.objects != NULL)
		set_world(&initpara);
	make_canvas(&initpara);
	load_screen(initpara, initpara.save);
	return (0);
}
