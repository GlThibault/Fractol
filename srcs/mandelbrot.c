/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractale.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:42:53 by tglandai          #+#    #+#             */
/*   Updated: 2016/12/12 14:28:07 by tglandai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_init(t_fractol *data)
{
	data->it_max = 20;
	data->zoom = 300;
	data->x1 = -2.05;
	data->y1 = -1.3;
	data->color = 1;
}

void	mandelbrot_calc(t_fractol *data, int x, int y)
{
	data->c_r = x / data->zoom + data->x1;
	data->c_i = y / data->zoom + data->y1;
	data->z_r = 0;
	data->z_i = 0;
	data->it = 0;
	while (data->z_r * data->z_r + data->z_i *
			data->z_i < 4 && data->it < data->it_max)
	{
		data->tmp = data->z_r;
		data->z_r = data->z_r * data->z_r -
			data->z_i * data->z_i + data->c_r;
		data->z_i = 2 * data->z_i * data->tmp + data->c_i;
		data->it++;
	}
	if (data->it == data->it_max)
		put_pxl_to_img(data, x, y, 0x000000);
	else
		put_pxl_to_img(data, x, y, (255 *
			data->color / data->it_max * data->it));
}

void	mandelbrot(t_fractol *data)
{
	double	x;
	double	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < WIDTH)
		{
			mandelbrot_calc(data, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	ft_bzero(data->img_ptr, data->sl * data->bpp);
}
