/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_string_tab.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 13:38:28 by bjanik            #+#    #+#             */
/*   Updated: 2017/04/06 13:49:39 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_create_string_tab(int size)
{
	char	**tab;
	int		i;

	i = 0;
	if ((tab = (char**)malloc(size * sizeof(char *))) == NULL)
		return (NULL);
	while (i < size)
		tab[i++] = NULL;
	return (tab);
}
