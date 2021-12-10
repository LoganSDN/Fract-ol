/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:12:35 by lsidan            #+#    #+#             */
/*   Updated: 2021/12/09 10:34:07 by lsidan           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_init_mandel(t_data *d)
{
	d->iter_max = 50;
	d->zoom = WIDTH / 4;
	d->x1 = -2;
	d->y1 = -2;
}

int	mandelbrot(t_data *d)
{
	int	iter;

	iter = 0;
	d->re = d->x / d->zoom + d->x1;
	d->im = d->y / d->zoom + d->y1;
	d->i = 0;
	d->j = 0;
	d->_i = d->i * d->i;
	d->_j = d->j * d->j;
	while (d->_i + d->_j <= 4 && iter < d->iter_max)
	{
		d->_i = d->i * d->i;
		d->_j = d->j * d->j;
		d->j = d->i * d->j;
		d->j = d->j + d->j + d->im;
		d->i = d->_i - d->_j + d->re;
		iter++;
	}
	return (iter);
}
