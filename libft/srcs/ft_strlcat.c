/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 18:02:39 by tglandai          #+#    #+#             */
/*   Updated: 2016/11/20 19:04:30 by tglandai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (size > 0)
	{
		while (dst[i] && i < size)
			i++;
		j = i;
		while (src[i - j] != '\0' && i < size - 1)
		{
			dst[i] = src[i - j];
			i++;
		}
		if (j < size)
			dst[i] = '\0';
	}
	return (j + ft_strlen(src));
}
