/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:06:26 by lsidan            #+#    #+#             */
/*   Updated: 2021/12/08 22:12:11 by lsidan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <math.h>

# define WIDTH 700

//STRUCTS

// Fract_nb :	
//			1 = Mandelbrot
// 			2 = julia
// 			3 = Burning Ship
typedef struct s_data {
	int		x;
	int		y;
	double	i;
	double	j;
	double	_i;
	double	_j;
	double	i_temp;
	double	re;
	double	im;
	double	zoom;
	double	x1;
	double	y1;
	int		fract_nb;
	int		iter_max;
	int		enable_m_julia;
	void	*fract_ft;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*img_ptr;
	int		sl;
	int		endian;
	int		bpp;
	int		alpha;
	int		red;
	int		green;
	int		blue;
}	t_data;

//INIT FUNCTIONS
void	ft_init_data(t_data *d);
int		ft_init_mlx(t_data *d);
int		ft_init_img(t_data *d);
void	ft_init_mandel(t_data *d);
void	ft_julia_init(t_data *d);
void	ft_burning_ship_init(t_data *d);

//DRAW FUNCTIONS
void	put_pxl_to_img(t_data *d, int color);
void	ft_draw(t_data *d, int (*f)(t_data *));

//KEYS / MOUSE INPUT FUNCTIONS
int		dial_key(int keycode, t_data *d);
int		dial_key_julia(int keycode, t_data *d);
int		dial_key_julia2(int keycode, t_data *d);
int		dial_key_change_fract(int keycode, t_data *d);
int		dial_key_move(int keycode, t_data *d);
int		dial_key_color(int keycode, t_data *d);
int		mouse_key(int button, int x, int y, t_data *d);

//PROCESS FUNCTIONS
int		ft_strcmp_pimp(char *av);
void	ft_show_help(t_data *d);
int		ft_strcmp(char *s1, char *s2);
int		ft_which_f(int i, t_data *d);
void	ft_zoom(int x, int y, t_data *d);
void	ft_dezoom(int x, int y, t_data *d);

//FRACTALS FUNCTIONS
int		mandelbrot(t_data *d);
int		julia(t_data *d);
int		mouse_julia(int x, int y, t_data *d);
int		burning_ship(t_data *d);

//ERRORS FUNCTIONS
int		ft_wrong_f(void);
int		ft_no_args(void);
int		ft_close(t_data *d);

#endif