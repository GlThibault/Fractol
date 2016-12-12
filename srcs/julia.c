/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 20:11:04 by tglandai          #+#    #+#             */
/*   Updated: 2016/12/12 18:05:16 by tglandai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_init(t_fractol *data)
{
	data->it_max = 50;
	data->zoom = 200;
	data->x1 = -2.0;
	data->y1 = -1.9;
	data->color = 1;
	data->c_r = 0.285;
	data->c_i = 0.01;
}

void	julia_calc(t_fractol *data, int x, int y)
{
	data->z_r = x / data->zoom + data->x1;
	data->z_i = y / data->zoom + data->y1;
	data->it = 0;
	while (data->z_r * data->z_r + data->z_i
			* data->z_i < 4 && data->it < data->it_max)
	{
		data->tmp = data->z_r;
		data->z_r = data->z_r * data->z_r -
			data->z_i * data->z_i - 0.8 + (data->c_r / WIDTH);
		data->z_i = 2 * data->z_i * data->tmp + data->c_i / WIDTH;
		data->it++;
	}
	if (data->it == data->it_max)
		put_pxl_to_img(data, x, y, 0x000000);
	else
		put_pxl_to_img(data, x, y, (255 *
					data->color / data->it_max * data->it));
}

void	julia(t_fractol *data)
{
	double	x;
	double	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < WIDTH)
		{
			julia_calc(data, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	ft_bzero(data->img_ptr, data->sl * data->bpp);
}
