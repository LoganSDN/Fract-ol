/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:46:57 by lsidan            #+#    #+#             */
/*   Updated: 2021/12/08 16:08:02 by lsidan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_init_mlx(t_data *d)
{
	d->mlx_ptr = mlx_init();
	if (!d->mlx_ptr)
		return (EXIT_FAILURE);
	d->win_ptr = mlx_new_window(d->mlx_ptr, WIDTH, WIDTH, "Fractol");
	if (!d->win_ptr)
		return (EXIT_FAILURE);
	ft_init_img(d);
	return (EXIT_SUCCESS);
}

int	ft_init_img(t_data *d)
{
	d->img = mlx_new_image(d->mlx_ptr, WIDTH, WIDTH);
	if (!d->img)
		return (EXIT_FAILURE);
	d->img_ptr = mlx_get_data_addr(d->img, &d->bpp, \
		&d->sl, &d->endian);
	if (!d->img_ptr)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	ft_init_data(t_data *d)
{
	if (!d)
		return ;
	d->x = 0;
	d->y = 0;
	d->i = 0;
	d->j = 0;
	d->_i = 0;
	d->_j = 0;
	d->i_temp = 0;
	d->re = 0;
	d->im = 0;
	d->zoom = 1.0;
	d->iter_max = 50;
	d->red = 15;
	d->green = 3;
	d->blue = 25;
	d->alpha = 0;
}
