/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasbelgh <yasbelgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 06:23:06 by yasbelgh          #+#    #+#             */
/*   Updated: 2023/03/07 21:39:16 by yasbelgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	error(void)
{
	ft_putstr_fd("\e[1;31musage: ./fractol [fractal name]\n", 1);
	ft_putstr_fd("\e[1;31mfractal name: mandelbrot, julia, tricorn\n", 1);
	exit (1);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	key(int k_code, t_fract *data)
{
	arrows_keys(k_code, data);
	color_shift(k_code, data);
	if (k_code == 53)
		exit(1);
	if (k_code == 17)
		data->f = &tricorn;
	if (k_code == 38)
		data->f = &julia;
	if (k_code == 46)
		data->f = &mandelbrot;
	return (0);
}

void	arrows_keys(int k_code, t_fract *data)
{
	double	x;

	x = (data->control.re_end - data->control.re_start) / 10;
	if (k_code == 123)
	{
		data->control.re_start -= x;
		data->control.re_end -= x;
	}
	if (k_code == 124)
	{
		data->control.re_start += x;
		data->control.re_end += x;
	}
	if (k_code == 125)
	{
		data->control.im_start -= x;
		data->control.im_end -= x;
	}
	if (k_code == 126)
	{
		data->control.im_start += x;
		data->control.im_end += x;
	}
}

void	color_shift(int k_code, t_fract *data)
{
	if (k_code == 4)
		data->control.color = 20 * 259 * 256;
	if (k_code == 5)
		data->control.color = 10 * 265;
	if (k_code == 3)
		data->control.color = 256 * 256 * 230;
}
