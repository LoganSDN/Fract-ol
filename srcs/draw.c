/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:49:07 by lsidan            #+#    #+#             */
/*   Updated: 2021/12/13 19:07:08 by lsidan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	put_pxl_to_img(t_data *d, int color)
{
	*(int *)(d->img_ptr + (((d->sl * d->y) + (d->x * d->bpp)))) = color;
}

void	ft_create_color(t_data *d, int iter)
{
	int		color;

	if (iter != d->iter_max)
		color = smooth(d, iter).value;
	else
	{
		if (d->w_or_b == 1)
			color = 0x000000;
		else
			color = 0xF8F8FF;
	}
	put_pxl_to_img(d, color);
}

void	ft_draw(t_data *d, int (*f)(t_data *))
{
	d->y = 0;
	while (d->y < WIDTH)
	{
		d->x = 0;
		while (d->x < WIDTH)
		{
			ft_create_color(d, f(d));
			d->x++;
		}
		d->y++;
	}
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img, 0, 0);
	mlx_string_put(d->mlx_ptr, d->win_ptr, 10, 20, 0xFFFFFF, \
					ft_strjoin("Iter : ", ft_itoa(d->iter_max)));
	mlx_string_put(d->mlx_ptr, d->win_ptr, 10, 40, 0xFFFFFF, "H - Help");
	mlx_string_put(d->mlx_ptr, d->win_ptr, WIDTH - 110, 20, 0xFFFFFF, \
					"Esc - To close");
}
