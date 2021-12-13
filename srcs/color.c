/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:50:28 by lsidan            #+#    #+#             */
/*   Updated: 2021/12/13 19:28:21 by lsidan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	lerp(int v0, int v1, double t)
{
	return ((int)((double)v0 + t * (v1 - v0)));
}

t_color	color_lerp(t_color col1, t_color col2, double t)
{
	t_color	col;

	// dprintf(1, "R : %d, G : %d, B : %d\n", 
		// col1.rgba.r, col1.rgba.g, col1.rgba.b);
	if (col1.value == col2.value)
		return (col1);
	col.rgba.r = lerp((int)col1.rgba.r, (int)col2.rgba.r, t);
	col.rgba.g = lerp((int)col1.rgba.g, (int)col2.rgba.g, t);
	col.rgba.b = lerp((int)col1.rgba.b, (int)col2.rgba.b, t);
	col.rgba.a = 0x00;
	return (col);
}

t_color	linear_color(double i, int iter_max, t_pal *pal)
{
	double		_i;
	double		p;
	int			c;

	_i = i / iter_max;
	c = pal->count - 1;
	p = fmod(_i, 1.0f / c) * c;
	return (color_lerp((t_color)(pal->colors[(int)(_i * c) + 1]), \
						(t_color)(pal->colors[(int)(_i * c)]), (1 - p)));
}

t_color	smooth(t_data *d, int iter)
{
	double	i;
	double	smooth;

	smooth = log(d->i * d->i + d->j * d->j) / 2.0f;
	i = (double) iter + (1 - (log(smooth / log(2)) / log(2)));
	if (i < 0)
		i = 0;
	return (linear_color(i, d->iter_max, d->pal));
}
