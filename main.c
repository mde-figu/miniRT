/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 18:10:01 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/21 22:36:48 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/entries.h"

int	main(int argc, char *argv[])
{
	t_initpara	initpara;

	splash();
	if (validate(argc, argv))
		exit (0);
	if (!readfile(&initpara, argv))
		exit (0);
	//intro goes here
	if (initpara.objects != NULL)
		set_world(&initpara);
	make_canvas(&initpara);
	save_on(argc, &initpara);
	load_screen(initpara);
	return (0);
}
