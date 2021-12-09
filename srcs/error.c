/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:00:06 by lsidan            #+#    #+#             */
/*   Updated: 2021/11/29 12:02:55 by lsidan           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_no_args(void)
{
	ft_putstr_fd("No fractal name given", 1);
	return (EXIT_FAILURE);
}

int	ft_wrong_f(void)
{
	ft_putstr_fd("Invalid fractal name\n\n============\n\nFractals available :\
	\n\t- mandelbrot\n\t- julia\n\t- burning ship", 1);
	return (EXIT_FAILURE);
}
