/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:16:26 by yasbelgh          #+#    #+#             */
/*   Updated: 2024/03/26 15:06:54 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define WIDTH 1000.0
# define HEIGHT 1000.0
# define MAX_ITER 100.0

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct control
{
	double	zoom;
	double	move_x;
	double	move_y;
	int		color;
	double	mouse_x;
	double	mouse_y;
	double	re_start;
	double	re_end;
	double	im_start;
	double	im_end;
}		t_control;

typedef struct mlx_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}		t_data;

typedef struct s_fract
{
	t_data							img;
	void							*mlx;
	void							*win;
	t_control						control;
	int								(*f)(struct s_fract *, int, int);
}	t_fract;

int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
void	init(t_fract *data);
int		zoom(int button, int x, int y, t_fract *fract);
void	zoom_in(t_fract *fract, int x, int y);
void	zoom_out(t_fract *fract, int x, int y);
int		julia_mouse(int x, int y, t_fract *fract);
void	parse_args(char **av, t_fract *data);
void	error(void);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		mandelbrot(t_fract *fract, int x, int y);
int		julia(t_fract *fract, int x, int y);
int		tricorn(t_fract *fract, int x, int y);
int		key(int keycode, t_fract *fract);
void	color_shift(int k_code, t_fract *fract);
void	arrows_keys(int k_code, t_fract *fract);

#endif
