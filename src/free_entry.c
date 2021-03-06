/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_entry.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 19:26:48 by mde-figu          #+#    #+#             */
/*   Updated: 2021/05/04 09:59:04 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

int	free_entry(char ***entry)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = *entry;
	while (tmp[i] != NULL)
	{
		free(tmp[i]);
		tmp[i] = NULL;
		i++;
	}
	free(tmp);
	tmp = NULL;
	return (0);
}
