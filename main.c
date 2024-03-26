/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 02:28:24 by yasbelgh          #+#    #+#             */
/*   Updated: 2024/03/26 15:07:21 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	pixel_iter(t_fract **data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx_clear_window((*data)->mlx, (*data)->win);
	while (x < WIDTH)
	{
		while (y < HEIGHT)
		{
			(*data)->f(*data, x, y);
			y++;
		}
		y = 0;
		x++;
	}
	mlx_put_image_to_window((*data)->mlx, (*data)->win, (*data)->img.img, 0, 0);
	return (0);
}

int	close_win(t_fract *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit (0);
	return (0);
}

int	glb_mlx(t_fract *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, \
		HEIGHT, WIDTH, "fractol made by yasbelgh");
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp, \
		&data->img.line_length, &data->img.endian);
	mlx_mouse_hook(data->win, zoom, data);
	mlx_hook(data->win, 2, 1L << 2, key, data);
	mlx_hook(data->win, 6, 0L, julia_mouse, data);
	mlx_hook(data->win, 17, 0L, close_win, data);
	mlx_loop_hook(data->mlx, pixel_iter, &data);
	mlx_loop(data->mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_fract	*data;

	if (ac == 2)
	{
		data = malloc(sizeof(t_fract));
		init(data);
		parse_args(av, data);
		glb_mlx(data);
	}
	else
		error();
	while (1)
		;
}
