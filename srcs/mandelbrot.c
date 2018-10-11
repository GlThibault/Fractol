/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:42:53 by tglandai          #+#    #+#             */
/*   Updated: 2018/10/11 13:10:40 by tglandai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_init(t_fractol *data)
{
	data->it_max = 50;
	data->zoom = 300;
	data->x1 = -2.05;
	data->y1 = -1.3;
	data->color = 265;
}

void	mandelbrot_calc(t_fractol *data)
{
	data->c_r = data->x / data->zoom + data->x1;
	data->c_i = data->y / data->zoom + data->y1;
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
		put_pxl_to_img(data, data->x, data->y, 0x000000);
	else
		put_pxl_to_img(data, data->x, data->y, (data->color * data->it));
}

void	*mandelbrot(void *tab)
{
	t_fractol	*data;
	int		tmp;

	data = (t_fractol *)tab;
	data->x = 0;
	tmp = data->y;
	while (data->x < WIDTH)
	{
		data->y = tmp;
		while (data->y < data->y_max)
		{
			mandelbrot_calc(data);
			data->y++;
		}
		data->x++;
	}
	return (tab);
}

void	mandelbrot_pthread(t_fractol *data)
{
	t_fractol	tab[THREAD_NUMBER];
	pthread_t	t[THREAD_NUMBER];
	int			i;

	i = 0;
	while (i < THREAD_NUMBER)
	{
		ft_memcpy((void*)&tab[i], (void*)data, sizeof(t_fractol));
		tab[i].y = THREAD_WIDTH * i;
		tab[i].y_max = THREAD_WIDTH * (i + 1);
		pthread_create(&t[i], NULL, mandelbrot, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
