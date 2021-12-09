/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 14:42:51 by lsidan            #+#    #+#             */
/*   Updated: 2021/11/11 10:34:25 by lsidan           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_digits(int nb)
{
	size_t	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nb)
{
	size_t		digits;
	char		*str;
	long long	nb1;

	nb1 = nb;
	digits = ft_count_digits(nb);
	str = (char *)malloc(digits * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	if (nb == 0)
		str[0] = '0';
	str[digits] = '\0';
	digits -= 1;
	if (nb1 < 0)
	{
		str[0] = '-';
		nb1 *= -1;
	}
	while (nb1 > 0)
	{
		str[digits] = 48 + (nb1 % 10);
		nb1 /= 10;
		digits--;
	}
	return (str);
}
