/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:19:10 by lsidan            #+#    #+#             */
/*   Updated: 2021/11/08 17:35:24 by lsidan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != 0)
	{
		if ((unsigned char)*s == (unsigned char) c)
			return ((char *) s);
		s++;
	}
	if (c == 0)
		return ((char *) s);
	return (NULL);
}
