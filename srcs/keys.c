/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:51:13 by lsidan            #+#    #+#             */
/*   Updated: 2021/12/10 16:38:41 by lsidan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	dial_key(int keycode, t_data *d)
{
	if (keycode == KEY_H)
		d->s_help = !d->s_help;
	if (d->s_help)
		ft_show_help(d);
	else
	{
		if (keycode == KEY_ESC)
			ft_close(d);
		if (keycode == KEY_I)
			d->iter_max += 50;
		dial_key_move(keycode, d);
		dial_key_julia(keycode, d);
		dial_key_change_fract(keycode, d);
		dial_key_color(keycode, d);
		ft_draw(d, d->fract_ft);
	}
	return (0);
}

int	dial_key_move(int keycode, t_data *d)
{
	if (keycode == KEY_LEFT)
		d->x1 = d->x1 - (0.03f * (WIDTH / d->zoom));
	if (keycode == KEY_RIGHT)
		d->x1 = d->x1 + (0.03f * (WIDTH / d->zoom));
	if (keycode == KEY_DOWN)
		d->y1 = d->y1 + (0.03f * (WIDTH / d->zoom));
	if (keycode == KEY_UP)
		d->y1 = d->y1 - (0.03f * (WIDTH / d->zoom));
	if (keycode == KEY_SPACE)
		d->enable_m_julia = !d->enable_m_julia;
	return (0);
}

int	dial_key_color(int keycode, t_data *d)
{
	if (keycode >= KEY_1 && keycode <= KEY_9)
	{
		d->pal = &get_pal()[keycode - KEY_1];
		if (keycode == KEY_1)
			d->w_or_b = 0;
		if (keycode == KEY_2)
			d->w_or_b = 1;
	}
	if (keycode == KEY_W)
		d->w_or_b = !d->w_or_b;
	return (0);
}

int	dial_key_change_fract(int keycode, t_data *d)
{
	if (keycode == KEY_A)
	{
		ft_init_mandel(d);
		d->fract_nb = 1;
		d->fract_ft = &mandelbrot;
	}
	if (keycode == KEY_Z)
	{
		ft_julia_init(d);
		d->fract_nb = 2;
		d->fract_ft = &julia;
	}
	if (keycode == KEY_E)
	{
		ft_burning_ship_init(d);
		d->fract_nb = 3;
		d->fract_ft = &burning_ship;
	}
	return (0);
}

int	dial_key_julia(int keycode, t_data *d)
{
	if (keycode == KEY_J && d->fract_nb == 2)
	{
		ft_julia_init(d);
		d->re = -0.8;
		d->im = 0.156;
	}
	if (keycode == KEY_K && d->fract_nb == 2)
	{
		ft_julia_init(d);
		d->re = 0.285;
		d->im = 0.01;
	}
	if (keycode == KEY_L && d->fract_nb == 2)
	{
		ft_julia_init(d);
		d->re = -0.835;
		d->im = -0.2321;
	}
	return (0);
}
