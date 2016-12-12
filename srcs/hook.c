/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 20:00:26 by tglandai          #+#    #+#             */
/*   Updated: 2016/12/12 18:20:35 by tglandai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

int		key_hook(int keycode, t_fractol *data)
{
	if (keycode == 53)
		exit(1);
	else if (keycode == 69)
		data->it_max++;
	else if (keycode == 78)
		data->it_max--;
	else if (keycode == 123)
		data->x1 -= 30 / data->zoom;
	else if (keycode == 124)
		data->x1 += 30 / data->zoom;
	else if (keycode == 125)
		data->y1 += 30 / data->zoom;
	else if (keycode == 126)
		data->y1 -= 30 / data->zoom;
	else if (keycode == 49)
		fract_init(data);
	else if (keycode == 18)
		data->color = 256;
	else if (keycode == 19)
		data->color = 300000;
	else if (keycode == 20)
		data->color = 1;
	fract_calc(data);
	return (0);
}

int		mouse_julia(int x, int y, t_fractol *data)
{
	if (data->fract == 1)
	{
		data->c_r = x * 2;
		data->c_i = y * 2 - 800;
		fract_calc(data);
	}
	return (0);
}

int		mouse_hook(int mousecode, int x, int y, t_fractol *data)
{
	if (mousecode == 5 || mousecode == 2)
	{
		data->zoom /= 1.5;
	}
	else if (mousecode == 4 || mousecode == 1)
	{
		data->zoom *= 1.5;
	}
	x = y;
	fract_calc(data);
	return (0);
}
