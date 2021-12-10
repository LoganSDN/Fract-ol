/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:24:29 by lsidan            #+#    #+#             */
/*   Updated: 2021/12/10 16:38:34 by lsidan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_show_help(t_data *d)
{
	ft_bzero(d->img_ptr, (WIDTH * d->sl) + (WIDTH * d->bpp));
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img, 0, 0);
	mlx_string_put(d->mlx_ptr, d->win_ptr, 290, 70, 0xFFFFFF, \
		"=== CONTROLS ===");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 175, 280, 0xF8F8FF, \
		"Mandelbrot set                 - A");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 175, 310, 0xF8F8FF, \
		"Julia set                      - Z");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 175, 340, 0xF8F8FF, \
		"\"Burning Ship\" set             - E");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 175, 370, 0xF8F8FF, \
		"Zoom                           - Click or Scroll");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 175, 400, 0xF8F8FF, \
		"Iterations                     - I");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 175, 430, 0xF8F8FF, \
		"Color palette                  - (1 - 9)");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 175, 460, 0xF8F8FF, \
		"Mouse Lock (only for Julia)    - Space");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 175, 490, 0xF8F8FF, \
		"Close Help                     - H");
}
