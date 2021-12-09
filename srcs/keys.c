/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:51:13 by lsidan            #+#    #+#             */
/*   Updated: 2021/12/08 23:18:00 by lsidan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	dial_key(int keycode, t_data *d)
{
	if (keycode == 53)
		ft_close(d);
	if (keycode == 34)
		d->iter_max += 50;
	if (keycode == 4)
		ft_show_help(d);
	dial_key_move(keycode, d);
	dial_key_julia(keycode, d);
	dial_key_change_fract(keycode, d);
	dial_key_color(keycode, d);
	ft_draw(d, d->fract_ft);
	return (0);
}

int	dial_key_move(int keycode, t_data *d)
{
	if (keycode == 123)
		d->x1 = d->x1 - (0.03f * (WIDTH / d->zoom));
	if (keycode == 124)
		d->x1 = d->x1 + (0.03f * (WIDTH / d->zoom));
	if (keycode == 125)
		d->y1 = d->y1 + (0.03f * (WIDTH / d->zoom));
	if (keycode == 126)
		d->y1 = d->y1 - (0.03f * (WIDTH / d->zoom));
	if (keycode == 1)
		d->enable_m_julia = !d->enable_m_julia;
	return (0);
}

int	dial_key_color(int keycode, t_data *d)
{
	dprintf(1, "KEYCODE : %d", keycode);
	if (keycode == 12)
		d->alpha++;
	if (keycode == 15)
		d->red++;
	if (keycode == 5)
		d->green++;
	if (keycode == 11)
		d->blue++;
	return (0);
}

int	dial_key_change_fract(int keycode, t_data *d)
{
	if (keycode == 46)
	{
		ft_init_mandel(d);
		d->fract_nb = 1;
		d->fract_ft = &mandelbrot;
	}
	if (keycode == 38)
	{
		ft_julia_init(d);
		d->fract_nb = 2;
		d->fract_ft = &julia;
	}
	if (keycode == 11)
	{
		ft_burning_ship_init(d);
		d->fract_nb = 3;
		d->fract_ft = &burning_ship;
	}
	return (0);
}

int	dial_key_julia(int keycode, t_data *d)
{
	if (keycode == 18 && d->fract_nb == 2)
	{
		ft_julia_init(d);
		d->re = -0.8;
		d->im = 0.156;
	}
	if (keycode == 19 && d->fract_nb == 2)
	{
		ft_julia_init(d);
		d->re = 0.285;
		d->im = 0.01;
	}
	if (keycode == 20 && d->fract_nb == 2)
	{
		ft_julia_init(d);
		d->re = -0.835;
		d->im = -0.2321;
	}
	return (0);
}
