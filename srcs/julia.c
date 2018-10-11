/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 20:11:04 by tglandai          #+#    #+#             */
/*   Updated: 2018/10/11 12:02:38 by tglandai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_julia(int x, int y, t_fractol *data)
{
	if (data->fract == 1 && data->julia_mouse == 1)
	{
		data->c_r = x * 2;
		data->c_i = y * 2 - 800;
		fract_calc(data);
	}
	return (0);
}

void	julia_init(t_fractol *data)
{
	data->it_max = 50;
	data->zoom = 200;
	data->x1 = -2.0;
	data->y1 = -1.9;
	data->color = 265;
	data->c_r = 0.285;
	data->c_i = 0.01;
	data->julia_mouse = 1;
}

void	julia_calc(t_fractol *data)
{
	data->z_r = data->x / data->zoom + data->x1;
	data->z_i = data->y / data->zoom + data->y1;
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
		put_pxl_to_img(data, data->x, data->y, 0x000000);
	else
		put_pxl_to_img(data, data->x, data->y, (data->color * data->it));
}

void	*julia(void *tab)
{
	int		tmp;
	t_fractol	*data;

	data = (t_fractol *)tab;
	data->x = 0;
	tmp = data->y;
	while (data->x < WIDTH)
	{
		data->y = tmp;
		while (data->y < data->y_max)
		{
			julia_calc(data);
			data->y++;
		}
		data->x++;
	}
	return (tab);
}

void	julia_pthread(t_fractol *data)
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
		pthread_create(&t[i], NULL, julia, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
