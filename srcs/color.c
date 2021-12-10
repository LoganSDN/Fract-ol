/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:50:28 by lsidan            #+#    #+#             */
/*   Updated: 2021/12/10 16:38:37 by lsidan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	lerp(int v0, int v1, double p)
{
	return ((int)((double)v0 + (v1 - v0) * p));
}

t_color	color_lerp(t_color col1, t_color col2, double p)
{
	t_color	col;

	if (col1.value == col2.value)
		return (col1);
	col.rgba.r = (t_char)lerp((int)col1.rgba.r, (int)col2.rgba.r, p);
	col.rgba.g = (t_char)lerp((int)col1.rgba.g, (int)col2.rgba.g, p);
	col.rgba.b = (t_char)lerp((int)col1.rgba.b, (int)col2.rgba.b, p);
	col.rgba.a = (t_char)0x00;
	return (col);
}

t_color	linear_color(double i, int max, t_pal *pal)
{
	double		index;
	double		p;
	int			c;

	index = i / max;
	c = pal->count - 1;
	p = fmod(index, 1.0f / c) * c;
	return (color_lerp((t_color)(pal->colors[(int)(index * c) + 1]), \
						(t_color)(pal->colors[(int)(index * c)]), (1 - p)));
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
