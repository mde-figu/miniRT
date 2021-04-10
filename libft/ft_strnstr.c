/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirkios <mirkios@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:17:55 by mirkios           #+#    #+#             */
/*   Updated: 2021/02/20 17:38:27 by mirkios          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t needle_len;

	needle_len = ft_strlen(small);
	if (!needle_len)
		return ((char *)big);
	while (*big && len >= needle_len)
	{
		if (!ft_strncmp(big, small, needle_len))
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
