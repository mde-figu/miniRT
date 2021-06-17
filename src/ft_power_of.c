/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power_of.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 23:09:24 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/17 17:44:42 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_pow(int x, int y)
{
	double temp;
	if( y == 0)
		return (1);
	temp = ft_pow(x, y/2);
	if (y % 2 == 0)
		return (temp * temp);
	else
	{
		if(y > 0)
			return (x * temp * temp);
		else
			return (temp*temp)/x;
	}
} 
 