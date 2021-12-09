/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:42:41 by lsidan            #+#    #+#             */
/*   Updated: 2021/11/08 10:12:53 by lsidan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	size_t	j;

	j = 0;
	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	j = ft_strlen(s1);
	while (j > 0 && ft_strchr(set, s1[j]))
		j--;
	new = ft_substr(s1, 0, j + 1);
	if (new == NULL)
		return (NULL);
	new[ft_strlen(new)] = '\0';
	return (new);
}
