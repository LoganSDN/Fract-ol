/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:24:29 by lsidan            #+#    #+#             */
/*   Updated: 2021/12/08 13:44:56 by lsidan           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_show_help(t_data *d)
{
	(void) d;
	ft_putstr_fd("\n=== Need some help ? ===\
		\n\n\t- To navigate use the arrows. \
		\n\n\t- To change the fractal : \
			\n\t\t- 'M' -> Mandelbrot\
			\n\t\t- 'J' -> Julia\
			\n\t\t\t (Hint : by pressing 'S' you can change the shape of Julia. Press 'S' again to freeze your creation)\
			\n\t\t- 'B' -> Burning ship\
		\n\n\t- To play with color :\
			\n\t\t- 'R' -> Increase the amount of RED\
			\n\t\t- 'G' -> Increase the amount of GREEN\
			\n\t\t- 'B' -> Increase the amount of BLUE\
		\n\n\t- To zoom : Just left-click whenever you want to zoom, and right click to dezoom\
		\n\n\tENJOY :)\n", 1);
}
