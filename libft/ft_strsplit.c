/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:15:02 by bjanik            #+#    #+#             */
/*   Updated: 2017/05/20 17:55:04 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_words(char const *str, char c)
{
	int	nb_words;

	nb_words = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
			nb_words++;
		while (*str != c && *str)
			str++;
	}
	return (nb_words);
}

static int	ft_nb_ltr(char const *str, char c)
{
	int	nb_ltr;

	nb_ltr = 0;
	while (*str != c && *str)
	{
		nb_ltr++;
		str++;
	}
	return (nb_ltr);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	nb_ltr;

	i = 0;
	nb_ltr = 0;
	tab = NULL;
	if (s == NULL || ((tab = (char**)malloc((ft_nb_words(s, c) + 1) *
						sizeof(char*))) == NULL))
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		if (*s)
		{
			nb_ltr = ft_nb_ltr(s, c);
			tab[i++] = ft_strndup(s, nb_ltr);
		}
		s += nb_ltr;
	}
	tab[i] = NULL;
	return (tab);
}
