/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 15:48:45 by bjanik            #+#    #+#             */
/*   Updated: 2017/05/18 19:01:20 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(char const *str, const char *s)
{
	int	nb_words;

	nb_words = 0;
	while (*str)
	{
		while (ft_strchr(s, *str))
			str++;
		if (*str)
			nb_words++;
		while (!ft_strchr(s, *str) && *str)
			str++;
	}
	return (nb_words);
}

static int	ft_nb_ltr(char const *str, const char *s)
{
	int	nb_ltr;

	nb_ltr = 0;
	while (!ft_strchr(s, *str) && *str)
	{
		nb_ltr++;
		str++;
	}
	return (nb_ltr);
}

char		**ft_strtok(char const *str, const char *s)
{
	char	**tab;
	size_t	i;
	size_t	nb_ltr;

	i = 0;
	tab = NULL;
	if (str == NULL)
		return (NULL);
	if ((tab = (char**)malloc((ft_words(str, s) + 1) * sizeof(char*))) == NULL)
		return (NULL);
	while (*str)
	{
		while (ft_strchr(s, *str))
			str++;
		if (!*str)
			break ;
		if (*str)
		{
			nb_ltr = ft_nb_ltr(str, s);
			tab[i++] = ft_strndup(str, nb_ltr);
		}
		str += nb_ltr;
	}
	tab[i] = NULL;
	return (tab);
}
