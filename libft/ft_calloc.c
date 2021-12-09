/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:18:10 by lsidan            #+#    #+#             */
/*   Updated: 2021/11/05 11:41:45 by lsidan           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	char	*ptr;

	ptr = malloc(elementCount * elementSize);
	if (ptr == NULL)
		return (NULL);
	else
		ft_bzero(ptr, elementCount * elementSize);
	return (ptr);
}
