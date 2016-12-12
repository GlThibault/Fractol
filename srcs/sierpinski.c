/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 18:51:45 by tglandai          #+#    #+#             */
/*   Updated: 2016/12/12 19:26:11 by tglandai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

void	sierpinski_init(t_fractol *data)
{
	data->it_max = 1;
	data->zoom = 200;
	data->x1 = -2.1;
	data->y1 = -1.2;
	data->color = 1;
}

void	sierpinski_calc(t_fractol *data, int x, int y)
{
	data = 0;
	x = y;
}

void	sierpinski(t_fractol *data)
{
	double	x;
	double	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < WIDTH)
		{
			sierpinski_calc(data, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	ft_bzero(data->img_ptr, data->sl * data->bpp);
}
