/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:28:35 by lsidan            #+#    #+#             */
/*   Updated: 2021/12/08 13:50:50 by lsidan           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_burning_ship_init(t_data *d)
{
	d->zoom = WIDTH / 4;
	d->x1 = -2;
	d->y1 = -2;
}

int	burning_ship(t_data *d)
{
	int	iter;

	iter = 0;
	d->re = d->x / d->zoom + d->x1;
	d->im = d->y / d->zoom + d->y1;
	d->i = 0;
	d->j = 0;
	d->_i = pow(d->i, 2);
	d->_j = pow(d->j, 2);
	while (d->_i + d->_j <= 4 && iter < d->iter_max)
	{
		d->_i = pow(d->i, 2);
		d->_j = pow(d->j, 2);
		d->i_temp = d->_i - d->_j + d->re;
		d->j = fabs(2.0 * d->i * d->j) + d->im;
		d->i = d->i_temp;
		iter++;
	}
	return (iter);
}
