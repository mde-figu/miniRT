/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_on.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:19:22 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/18 21:16:25 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

void	save_on(int argc, t_initpara *initpara)
{
	if (argc == 3)
		initpara->save = initpara->save + 1;
}
