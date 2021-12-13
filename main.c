/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:28:07 by lsidan            #+#    #+#             */
/*   Updated: 2021/12/13 19:45:32 by lsidan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

int	main(int ac, char **av)
{
	t_data		*d;

	if (ac < 2)
		return (ft_no_args());
	if (ft_strcmp_pimp(av[1]) == -1)
		return (ft_wrong_f());
	else
	{
		d = (t_data *) malloc(sizeof(t_data));
		ft_init_data(d);
		if (ft_init_mlx(d) || !d)
			return (EXIT_FAILURE);
		ft_which_f(ft_strcmp_pimp(av[1]), d);
		mlx_string_put(d->mlx_ptr, d->win_ptr, 0, 0, 0xF0FFFF, "HELLO \n WORLD");
		mlx_key_hook(d->win_ptr, dial_key, d);
		mlx_mouse_hook(d->win_ptr, mouse_key, d);
		mlx_hook(d->win_ptr, 17, 1L << 2, ft_close, d);
		mlx_hook(d->win_ptr, 6, 1L << 6, mouse_julia, d);
		mlx_loop(d->mlx_ptr);
	}
	return (0);
}
