/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:58:46 by tglandai          #+#    #+#             */
/*   Updated: 2018/10/11 13:13:06 by tglandai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include "libft.h"
# include "mlx.h"
# include "math.h"
# include "pthread.h"
# define WIDTH 600
# define THREAD_WIDTH 5
# define THREAD_NUMBER 120

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
	int			julia_mouse;
	int			x;
	int			y;
	int			y_max;
	int			it;
	int			it_max;
	int			show_text;
	double		zoom;
	double		x1;
	double		y1;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		tmp;
}				t_fractol;

int				key_hook(int keycode, t_fractol *data);
int				key_hook2(int keycode, t_fractol *data);
void			ft_zoom(int x, int y, t_fractol *data);
void			ft_dezoom(int x, int y, t_fractol *data);
int				mouse_hook(int mousecode, int x, int y, t_fractol *data);

void			mandelbrot_init(t_fractol *data);
void			mandelbrot_calc(t_fractol *data);
void			*mandelbrot(void *tab);
void			mandelbrot_pthread(t_fractol *data);

int				mouse_julia(int x, int y, t_fractol *data);
void			julia_init(t_fractol *data);
void			julia_calc(t_fractol *data);
void			*julia(void *tab);
void			julia_pthread(t_fractol *data);

void			burningship_init(t_fractol *data);
void			burningship_calc(t_fractol *data);
void			*burningship(void *tab);
void			burningship_pthread(t_fractol *data);

int				ft_close(void);
void			put_pxl_to_img(t_fractol *data, int x, int y, int color);
void			put_text(t_fractol *data);

void			fract_calc(t_fractol *data);
void			fract_init(t_fractol *data);
void			mlx_win_init(t_fractol *data);
int				fract_comp(char **av, t_fractol *data);
#endif
