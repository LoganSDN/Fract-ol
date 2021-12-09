/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:37:38 by lsidan            #+#    #+#             */
/*   Updated: 2021/11/07 15:49:42 by lsidan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	long long	nb1;

	nb1 = nb;
	if (nb1 < 0)
	{
		ft_putchar_fd('-', fd);
		nb1 *= -1;
	}
	if (nb1 >= 10)
	{
		ft_putnbr_fd((nb1 / 10), fd);
		ft_putnbr_fd((nb1 % 10), fd);
	}
	else
		ft_putchar_fd(nb1 + 48, fd);
}
