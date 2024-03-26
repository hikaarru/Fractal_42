/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasbelgh <yasbelgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 06:28:45 by yasbelgh          #+#    #+#             */
/*   Updated: 2023/03/07 21:40:18 by yasbelgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	mandelbrot(t_fract *data, int x, int y)
{
	t_complex	c;
	t_complex	z;
	int			i;
	double		tmp;

	z.real = 0;
	z.imag = 0;
	c.real = ((x / WIDTH) * (data->control.re_end - data->control.re_start))
		+ data->control.re_start - 0.5 + data->control.move_x;
	c.imag = ((-y / HEIGHT) * (data->control.im_end - data->control.im_start))
		+ data->control.im_end + data->control.move_y;
	i = 0;
	while (z.real * z.real + z.imag * z.imag < 4 && i < MAX_ITER)
	{
		tmp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = tmp;
		i++;
	}
	if (i == MAX_ITER)
		my_mlx_pixel_put(&data->img, x, y, 0xFFFFFF);
	else
		my_mlx_pixel_put(&data->img, x, y, i * data->control.color);
	return (0);
}

int	julia(t_fract *data, int x, int y)
{
	t_complex	c;
	t_complex	z;
	int			i;
	double		tmp;

	z.real = ((x / WIDTH) * (data->control.re_end \
		- data->control.re_start)) + data->control.re_start \
		+ data->control.move_x;
	z.imag = ((-y / HEIGHT) * (data->control.im_end \
		- data->control.im_start)) + data->control.im_end \
		+ data->control.move_y;
	c.real = data->control.mouse_x;
	c.imag = data->control.mouse_y;
	i = 0;
	while (z.real * z.real + z.imag * z.imag < 4 && i++ < MAX_ITER)
	{
		tmp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = tmp;
	}
	if (i == MAX_ITER)
		my_mlx_pixel_put(&data->img, x, y, 0xFFFFFF);
	else
		my_mlx_pixel_put(&data->img, x, y, i * data->control.color);
	return (0);
}

int	tricorn(t_fract *data, int x, int y)
{
	t_complex	c;
	t_complex	z;
	int			i;
	double		tmp;

	z.real = 0;
	z.imag = 0;
	c.real = ((x / WIDTH) * (data->control.re_end - data->control.re_start))
		+ data->control.re_start + data->control.move_x;
	c.imag = ((-y / HEIGHT) * (data->control.im_end - data->control.im_start))
		+ data->control.im_end + data->control.move_y;
	i = 0;
	while (z.real * z.real + z.imag * z.imag < 4 && i < MAX_ITER)
	{
		tmp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = -2 * z.real * z.imag + c.imag;
		z.real = tmp;
		i++;
	}
	if (i == MAX_ITER)
		my_mlx_pixel_put(&data->img, x, y, 0xFFFFFF);
	else
		my_mlx_pixel_put(&data->img, x, y, i * data->control.color);
	return (0);
}
