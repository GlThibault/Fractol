/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:58:46 by tglandai          #+#    #+#             */
/*   Updated: 2016/12/12 18:51:09 by tglandai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include "libft.h"
# include "mlx.h"
# define WIDTH 800

typedef struct	s_fractol
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*img_ptr;
	int			endian;
	int			sl;
	int			bpp;
	int			fract;
	int			color;
	double		zoom;
	double		it_max;
	double		x1;
	double		y1;
	double		x;
	double		y;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		it;
	double		tmp;
}				t_fractol;

void			put_text(t_fractol *data);
int				key_hook(int keycode, t_fractol *data);
int				mouse_julia(int x, int y, t_fractol *data);
int				mouse_hook(int mousecode, int x, int y, t_fractol *data);
void			mandelbrot(t_fractol *data);
void			mandelbrot_calc(t_fractol *data, int x, int y);
void			mandelbrot_init(t_fractol *data);
void			julia(t_fractol *data);
void			julia_calc(t_fractol *data, int x, int y);
void			julia_init(t_fractol *data);
void			sierpinski(t_fractol *data);
void			sierpinski_calc(t_fractol *data, int x, int y);
void			sierpinski_init(t_fractol *data);
void			put_pxl_to_img(t_fractol *data, int x, int y, int color);
void			fract_calc(t_fractol *data);
void			fract_init(t_fractol *data);
void			mlx_win_init(t_fractol *data);
#endif
