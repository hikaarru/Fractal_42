/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 02:01:39 by yasbelgh          #+#    #+#             */
/*   Updated: 2024/03/26 14:24:22 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	zoom(int click, int x, int y, t_fract *data)
{
	if (click == 3)
	{
		init(data);
		return (0);
	}
	if (click == 4)
		zoom_out(data, x, y);
	if (click == 5)
		zoom_in(data, x, y);
	return (0);
}

void	zoom_in(t_fract *data, int x, int y)
{
	double	mouse_position[2];
	double	tmp;

	mouse_position[0] = ((x / WIDTH) * (data->control.re_end - \
		data->control.re_start)) + data->control.re_start;//url stackoverflow for the formula of the mouse position ==> https://stackoverflow.com/questions/929103/convert-a-number-range-to-another-range-maintaining-ratio
	mouse_position[1] = ((-y / HEIGHT) * (data->control.im_end - \
		data->control.im_start)) + data->control.im_end;//calculating the mouse position in the imaginary part
	data->control.zoom = 0.5;
	tmp = (data->control.re_end - data->control.re_start) * data->control.zoom;
	data->control.re_end = mouse_position[0] + \
		(data->control.re_end - mouse_position[0]) * data->control.zoom;
	data->control.re_start = data->control.re_end - tmp;
	data->control.im_end = mouse_position[1] + \
		(data->control.im_end - mouse_position[1]) * data->control.zoom;
	data->control.im_start = data->control.im_end - tmp;
}

void	zoom_out(t_fract *data, int x, int y)
{
	double	mouse_position[2];
	double	tmp;

	mouse_position[0] = ((x / WIDTH) * (data->control.re_end - \
		data->control.re_start)) + data->control.re_start;
	mouse_position[1] = ((-y / HEIGHT) * (data->control.im_end - \
		data->control.im_start)) + data->control.im_end;
	data->control.zoom = 2;
	tmp = (data->control.re_end - data->control.re_start) * data->control.zoom;
	data->control.re_end = mouse_position[0] + \
		(data->control.re_end - mouse_position[0]) * data->control.zoom;
	data->control.re_start = data->control.re_end - tmp;
	data->control.im_end = mouse_position[1] + \
		(data->control.im_end - mouse_position[1]) * data->control.zoom;
	data->control.im_start = data->control.im_end - tmp;
}

int	julia_mouse(int x, int y, t_fract *data)
{
	if (x < WIDTH && y < HEIGHT && x > 0 && y > 0)
	{
		data->control.mouse_x = (double)x / WIDTH * (data->control.re_end - \
			data->control.re_start) + data->control.re_start;
		data->control.mouse_y = (double)y / HEIGHT * (data->control.im_end - \
			data->control.im_start) + data->control.im_start;
	}
	return (0);
}
