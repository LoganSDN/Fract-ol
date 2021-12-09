/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:23:17 by lsidan            #+#    #+#             */
/*   Updated: 2021/11/07 12:2 by lsidan           	  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_w(char const *s, char c)
{
	int		i;
	size_t	w;

	i = 1;
	w = 0;
	if (s[0] == 0)
		return (0);
	while (s[i])
	{
		if (s[i] != c && (s[i - 1] == c || i - 1 == 0))
			w++;
		i++;
	}
	return (w);
}

static char	**ft_free(char	**tab, int nbmot)
{
	int	i;

	i = 0;
	while (i < nbmot)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static char	**ft_split2(int nbmot, const char *s, char c, char **splitted)
{		
	int		i;
	int		y;
	int		tab;

	i = 0;
	tab = 0;
	if (!splitted || !s)
		return (NULL);
	while (tab < nbmot && s[i])
	{
		y = 0;
		while (s[i] == c)
			i++;
		while (s[i + y] != c && s[i + y] != '\0')
			y++;
		splitted[tab] = ft_substr((char *) s, i, y);
		if (splitted[tab] == 0)
			return (ft_free(splitted, nbmot));
		i += y;
		tab++;
	}
	splitted[tab] = NULL;
	return (splitted);
}

char	**ft_split(char const *s, char c)
{
	int		nbmot;
	char	**splitted;

	if (!s)
		return (NULL);
	nbmot = ft_count_w(s, c);
	splitted = (char **)malloc((nbmot + 1) * sizeof(char *));
	if (splitted == NULL)
		return (NULL);
	return (ft_split2(nbmot, s, c, splitted));
}
