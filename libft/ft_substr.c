/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 09:32:19 by lsidan            #+#    #+#             */
/*   Updated: 2021/11/09 10:49:27 by lsidan           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= (unsigned int) ft_strlen(s))
	{
		new = (char *) malloc(sizeof(char) + 1);
		if (!new)
			return (NULL);
		new[0] = '\0';
		return (new);
	}
	if (len > (size_t) ft_strlen(s))
		len = (size_t) ft_strlen(s) + 1;
	new = (char *) malloc(len * sizeof(char) + 1);
	if (!new)
		return (NULL);
	while (s[i] && i < len)
		new[i++] = s[start++];
	new[i] = '\0';
	return (new);
}
