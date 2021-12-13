/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:06:26 by lsidan            #+#    #+#             */
/*   Updated: 2021/12/13 19:49:39 by lsidan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "key_map.h"
# include <stdio.h>
# include <math.h>

# define WIDTH 700
# define MAX_PAL 10

//STRUCTS

typedef unsigned char	t_char;

typedef struct s_pal
{
	int			count;
	int			colors[16];
}					t_pal;

typedef struct s_rgba
{
	t_char	r;
	t_char	b;
	t_char	g;
	t_char	a;
}	t_rgba;

typedef union s_color {
	t_rgba	rgba;
	int		value;
}	t_color;

// Fract_nb :	
//			1 = Mandelbrot
// 			2 = julia
// 			3 = Burning Ship
typedef struct s_data {
	int			x;
	int			y;
	double		i;
	double		j;
	double		_i;
	double		_j;
	double		re;
	double		im;
	double		zoom;
	double		x1;
	double		y1;
	int			fract_nb;
	int			iter_max;
	int			enable_m_julia;
	void		*fract_ft;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		*img_ptr;
	t_pal		*pal;
	int			sl;
	int			endian;
	int			bpp;
	int			w_or_b;	
	int			s_help;
}	t_data;

//INIT FUNCTIONS
void		ft_init_data(t_data *d);
int			ft_init_mlx(t_data *d);
int			ft_init_img(t_data *d);
void		ft_init_mandel(t_data *d);
void		ft_julia_init(t_data *d);
void		ft_burning_ship_init(t_data *d);

//DRAW FUNCTIONS
void		put_pxl_to_img(t_data *d, int color);
void		ft_draw(t_data *d, int (*f)(t_data *));
t_color		linear_color(double i, int iter_max, t_pal *p);
t_color		color_lerp(t_color c1, t_color c2, double p);
int			lerp(int v0, int v1, double p);
t_pal		*get_pal(void);
t_color		smooth(t_data *d, int iter);

//KEYS / MOUSE INPUT FUNCTIONS
int			dial_key(int keycode, t_data *d);
int			dial_key_julia(int keycode, t_data *d);
int			dial_key_julia2(int keycode, t_data *d);
int			dial_key_change_fract(int keycode, t_data *d);
int			dial_key_move(int keycode, t_data *d);
int			dial_key_color(int keycode, t_data *d);
int			mouse_key(int button, int x, int y, t_data *d);

//PROCESS FUNCTIONS
int			ft_strcmp_pimp(char *av);
void		ft_show_help(t_data *d);
int			ft_strcmp(char *s1, char *s2);
int			ft_which_f(int i, t_data *d);
void		ft_zoom(int x, int y, t_data *d);
void		ft_dezoom(int x, int y, t_data *d);

//FRACTALS FUNCTIONS
int			mandelbrot(t_data *d);
int			julia(t_data *d);
int			mouse_julia(int x, int y, t_data *d);
int			burning_ship(t_data *d);

//ERRORS FUNCTIONS
int			ft_wrong_f(void);
int			ft_no_args(void);
int			ft_close(t_data *d);

#endif
