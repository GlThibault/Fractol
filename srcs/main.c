/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:59:26 by tglandai          #+#    #+#             */
/*   Updated: 2016/12/12 18:50:16 by tglandai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pxl_to_img(t_fractol *data, int x, int y, int color)
{
	if (x < WIDTH && y < WIDTH)
	{
		color = mlx_get_color_value(data->mlx, color);
		ft_memcpy(data->img_ptr + 4 * WIDTH * y + x * 4, &color, sizeof(int));
	}
}

void	fract_calc(t_fractol *data)
{
	if (data->it_max < 0)
		data->it_max = 0;
	if (data->fract == 0)
		mandelbrot(data);
	else if (data->fract == 1)
		julia(data);
	else if (data->fract == 2)
		sierpinski(data);
	put_text(data);
}

void	fract_init(t_fractol *data)
{
	if (data->fract == 0)
		mandelbrot_init(data);
	else if (data->fract == 1)
		julia_init(data);
	else if (data->fract == 2)
		sierpinski_init(data);
	fract_calc(data);
}

void	mlx_win_init(t_fractol *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, WIDTH, "Fractol");
	data->img = mlx_new_image(data->mlx, WIDTH, WIDTH);
	data->img_ptr = mlx_get_data_addr(data->img,
			&data->bpp, &data->sl, &data->endian);
}

int		main(int ac, char **av)
{
	t_fractol	*data;

	if (!(data = (t_fractol *)malloc(sizeof(t_fractol))))
		return (-1);
	if (ac == 2)
	{
		mlx_win_init(data);
		if (ft_strcmp(av[1], "mandelbrot") == 0)
			data->fract = 0;
		else if (ft_strcmp(av[1], "julia") == 0)
			data->fract = 1;
		else if (ft_strcmp(av[1], "sierpinski") == 0)
			data->fract = 2;
		else
		{
			ft_putendl("Usage /fractol \"fractale\"");
			return (0);
		}
		fract_init(data);
		mlx_hook(data->win, 6, 1L < 6, mouse_julia, data);
		mlx_key_hook(data->win, key_hook, data);
		mlx_mouse_hook(data->win, mouse_hook, data);
		mlx_loop(data->mlx);
	}
	else
		ft_putendl("Usage /fractol \"fractale\"");
	return (0);
}
