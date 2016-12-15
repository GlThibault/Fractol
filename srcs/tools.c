/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:06:07 by tglandai          #+#    #+#             */
/*   Updated: 2016/12/14 15:32:36 by tglandai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_close(void)
{
	exit(1);
	return (0);
}

void	put_pxl_to_img(t_fractol *data, int x, int y, int color)
{
	if (data->x < WIDTH && data->y < WIDTH)
	{
		color = mlx_get_color_value(data->mlx, color);
		ft_memcpy(data->img_ptr + 4 * WIDTH * y + x * 4,
				&color, sizeof(int));
	}
}

void	put_text(t_fractol *data)
{
	char	*text;
	char	*nb;

	nb = ft_itoa(data->it_max);
	text = ft_strjoin("iterations : ", nb);
	mlx_string_put(data->mlx, data->win, 10, 10, 0xFFFFFF, text);
	ft_strdel(&text);
	ft_strdel(&nb);
}
