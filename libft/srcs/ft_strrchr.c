/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:23:22 by tglandai          #+#    #+#             */
/*   Updated: 2016/11/07 18:02:37 by tglandai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	while (*s)
		s++;
	if ((char)c == '\0')
		return ((char *)s);
	s--;
	while (*s != (char)c && *s)
		s--;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
