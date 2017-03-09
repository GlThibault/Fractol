/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countlines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 13:06:22 by tglandai          #+#    #+#             */
/*   Updated: 2017/01/04 17:29:35 by tglandai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_linecount(char *str)
{
	int		lines;

	lines = 0;
	if (!str)
		return (-1);
	while (*str)
	{
		if (*str == '\n')
			lines++;
		str++;
	}
	return (lines);
}
