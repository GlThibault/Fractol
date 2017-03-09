/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linelen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 15:50:16 by tglandai          #+#    #+#             */
/*   Updated: 2017/01/04 17:32:10 by tglandai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_linelen(const char *s)
{
	size_t count;

	count = 0;
	if (!s)
		return (-1);
	while (s[count] && s[count] != '\n')
		count++;
	return (count);
}
