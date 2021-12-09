/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 08:27:48 by lsidan            #+#    #+#             */
/*   Updated: 2021/12/08 13:02:02 by lsidan           ###   ########lyon.fr   */
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
	d->_i = pow(d->i, 2);
	d->j = d->y / d->zoom + d->y1;
	d->_j = pow(d->j, 2);
	while (d->_i + d->_j < 4 && iter < d->iter_max)
	{
		d->_i = pow(d->i, 2);
		d->_j = pow(d->j, 2);
		d->i_temp = d->_i - d->_j;
		d->j = 2 * d->i * d->j + d->im;
		d->i = d->i_temp + d->re;
		iter++;
	}
	return (iter);
}
