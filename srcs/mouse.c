/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:05:15 by lsidan            #+#    #+#             */
/*   Updated: 2021/12/10 15:23:10 by lsidan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	mouse_key(int button, int x, int y, t_data *d)
{
	if (button == 4 || button == 1)
		ft_zoom(x, y, d);
	else if (button == 5 || button == 2)
		ft_dezoom(x, y, d);
	if (button == 4 || button == 1 || button == 5 || button == 2)
		ft_draw(d, d->fract_ft);
	return (0);
}

int	mouse_julia(int x, int y, t_data *d)
{
	if (d->fract_nb == 2 && d->enable_m_julia == 1)
	{
		d->re = 4 * ((double)x / WIDTH - 0.5);
		d->im = 4 * ((double)(WIDTH - y) / WIDTH - 0.5);
		ft_draw(d, d->fract_ft);
	}
	return (0);
}

void	ft_zoom(int x, int y, t_data *d)
{
	d->x1 = (x / d->zoom + d->x1) - (x / (d->zoom * 1.3));
	d->y1 = (y / d->zoom + d->y1) - (y / (d->zoom * 1.3));
	d->zoom *= 1.3;
	d->iter_max += 5;
}

void	ft_dezoom(int x, int y, t_data *d)
{
	d->x1 = (x / d->zoom + d->x1) - (x / (d->zoom / 1.3));
	d->y1 = (y / d->zoom + d->y1) - (y / (d->zoom / 1.3));
	d->zoom /= 1.3;
	d->iter_max -= 5;
}
