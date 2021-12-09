/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:04:51 by lsidan            #+#    #+#             */
/*   Updated: 2021/12/08 09:27:23 by lsidan           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] || s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

int	ft_strcmp_pimp(char *av)
{
	size_t	i;
	char	*f_array[3];

	f_array[0] = "mandelbrot";
	f_array[1] = "julia";
	f_array[2] = "burning ship";
	i = 0;
	while (i < 3)
	{
		if (ft_strcmp(av, f_array[i]) == 0)
			return (i);
		else
			i++;
	}
	return (-1);
}

int	ft_which_f(int i, t_data *d)
{
	if (i == 0)
	{
		d->fract_nb = 1;
		ft_init_mandel(d);
		d->fract_ft = &mandelbrot;
		ft_draw(d, d->fract_ft);
	}
	else if (i == 1)
	{
		d->fract_nb = 2;
		ft_julia_init(d);
		d->fract_ft = &julia;
		ft_draw(d, d->fract_ft);
	}
	else if (i == 2)
	{
		d->fract_nb = 3;
		d->fract_ft = &burning_ship;
		ft_burning_ship_init(d);
		ft_draw(d, d->fract_ft);
	}
	else
		return (ft_no_args());
	return (EXIT_SUCCESS);
}

int	ft_close(t_data *d)
{
	mlx_destroy_window(d->mlx_ptr, d->win_ptr);
	free(d);
	exit (0);
}
