/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasbelgh <yasbelgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:09:14 by yasbelgh          #+#    #+#             */
/*   Updated: 2023/03/07 09:30:32 by yasbelgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	while (s[c])
		c++;
	return (c);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void	init(t_fract *data)
{
	data->control.zoom = 0.01;
	data->control.move_x = 0.0;
	data->control.move_y = 0.0;
	data->control.re_end = 2.0;
	data->control.re_start = -2.0;
	data->control.im_start = -2.0;
	data->control.im_end = 2.0;
	data->control.color = 27070;
	data->control.mouse_x = -0.4;
	data->control.mouse_y = 0.6;
}

void	parse_args(char **av, t_fract *data)
{
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		data->f = &mandelbrot;
	else if (ft_strcmp(av[1], "julia") == 0)
		data->f = &julia;
	else if (ft_strcmp(av[1], "tricorn") == 0)
		data->f = &tricorn;
	else
	{
		ft_putstr_fd("\e[1;31mInvalid fractal name\n", 1);
		ft_putstr_fd("\e[0;34m{usage: ./fractol [fractal name]}\n", 1);
		exit (1);
	}
}
