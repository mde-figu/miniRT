/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 23:07:25 by mde-figu          #+#    #+#             */
/*   Updated: 2021/03/22 23:18:24 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLES_H
# define TUPLES_H

#include <stdio.h>
#include <string.h>

typedef struct
{
	char strVal[21];
	int intVal;
} tTuple;

void	deleteTuple(char *str);
void	addTuple(char *str, int val);
void	listTuples(void);


#endif