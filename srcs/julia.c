/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 08:27:48 by lsidan            #+#    #+#             */
/*   Updated: 2021/12/10 16:38:47 by lsidan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_julia_init(t_data *d)
{
	d->iter_max = 50;
	d->zoom = WIDTH / 4;
	d->x1 = -2.0;
	d->y1 = -2.0;
	d->re = -0.8;
	d->im = 0.156;
	d->enable_m_julia = 0;
}

int	julia(t_data *d)
{
	int		iter;

	iter = 0;
	d->i = d->x / d->zoom + d->x1;
	d->j = d->y / d->zoom + d->y1;
	d->_i = d->i * d->i;
	d->_j = d->j * d->j;
	while (d->_i + d->_j < 4 && iter < d->iter_max)
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
