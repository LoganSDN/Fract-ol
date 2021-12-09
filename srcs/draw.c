/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:49:07 by lsidan            #+#    #+#             */
/*   Updated: 2021/12/08 22:17:54 by lsidan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	put_pxl_to_img(t_data *d, int color)
{
	if (d->x < WIDTH && d->y < WIDTH)
		*(int *)(d->img_ptr + (((d->sl * d->y) + (d->x * d->bpp / 8)))) = color;
}

void	ft_create_color(t_data *d, int iter)
{
	double	k;
	int		color;

	k = iter * log(2);
	if (iter != d->iter_max)
		color = (int)(d->red * k) | (int)(d->green * k) << 8 | \
			(int)(d->blue * k) << 16;
	else
		color = 0xFFFFFF;
	put_pxl_to_img(d, color);
}

void	ft_draw(t_data *d, int (*f)(t_data *))
{
	d->y = 0;
	d->x = 0;
	while (d->y < WIDTH)
	{
		while (d->x < WIDTH)
		{
			ft_create_color(d, f(d));
			d->x++;
		}
		d->x = 0;
		d->y++;
	}
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img, 0, 0);
}
