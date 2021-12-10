/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:46:57 by lsidan            #+#    #+#             */
/*   Updated: 2021/12/10 16:38:45 by lsidan           ###   ########.fr       */
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
	d->bpp /= 8;
	return (EXIT_SUCCESS);
}

t_pal	*get_pal(void)
{
	static t_pal	tab[MAX_PAL];

	tab[0] = \
		(t_pal){15, {0x2a4858, 0x255566, 0x1c6373, \
						0x0b717e, 0x007f86, 0x008d8c, \
						0x009c8f, 0x23aa8f, 0x3fb78d, \
						0x5bc489, 0x77d183, 0x95dd7d, \
						0xb5e877, 0xd7f171, 0xfafa6e}};
	tab[1] = \
		(t_pal){5, {0x000764, 0x206BCB, 0xFFFFFF, \
						0xFFAA00, 0x000200}};
	tab[2] = \
		(t_pal){5, {0xF8F8FF, 0xCAC9CD, 0x9B9A9C, \
						0x6D6A6A, 0x3E3B39}};
	tab[3] = \
		(t_pal){5, {0x3E3B39, 0xCAC9CD, 0x6D6A6A, \
						0x9B9A9C, 0xF8F8FF}};
	tab[4] = \
		(t_pal){7, {0xFF0000, 0xFFFF00, 0x00FF00, \
						0x00FFFF, 0x0000FF, 0xFF00FF, \
						0xFF0000}};
	return (tab);
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
	d->re = 0;
	d->im = 0;
	d->zoom = 1.0;
	d->iter_max = 128;
	d->w_or_b = 0;
	d->s_help = 0;
	d->pal = get_pal();
}
