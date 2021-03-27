/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 12:22:31 by mde-figu          #+#    #+#             */
/*   Updated: 2021/03/26 13:51:51 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "launcher.h"

void		launcher(t_wind w1, t_gravity g1, t_projectile p1)
{
	int tempo;
	
	tempo = 0;
	while (tempo <= 100)
	{
		p1.x = p1.x + p1.vx * tempo;
		p1.y = p1.y + p1.vy * tempo;
		p1.z = p1.z + p1.vz * tempo;

		p1.vx = p1.vx + g1.ax * tempo;
		p1.vy = p1.vy + g1.ay * tempo;
		p1.vz = p1.vz + g1.az * tempo;

		p1.vx = p1.vx - w1.ax * tempo;
		p1.vy = p1.vy - w1.ay * tempo;
		p1.vz = p1.vz - w1.az * tempo;

		printf("   %s\n", "1");
		printf("filme\n");
		printf(" %c  %E  %E  %E\n", 'O', p1.x, p1.y, p1.z);
		tempo++;
	}
}

void		main(void)
{

		t_projectile p1;
		t_wind	w1;
		t_gravity g1;
		p1.x = 0;
		p1.y = 0;
		p1.z = 0;
		p1.vx = 50;
		p1.vy = 0;
		p1.vz = 220;
		g1.ax = 0;
		g1.ay = 0;
		g1.az = -9.8;
		w1.ax = 0;
		w1.ay = 1; 
		w1.az = 0;

		launcher(w1, g1, p1);
		
}
