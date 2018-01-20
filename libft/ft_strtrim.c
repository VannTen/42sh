/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:48:33 by bjanik            #+#    #+#             */
/*   Updated: 2017/04/24 16:23:01 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*trim_blank_str(void)
{
	char	*str;

	str = NULL;
	if ((str = (char*)malloc(1)) == NULL)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	char	*save;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	if (*s == '\0')
		return (trim_blank_str());
	save = (char*)s;
	while (*s)
		s++;
	s--;
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s--;
	if ((str = (char*)malloc(s - save + 2)) == NULL)
		return (NULL);
	while (save != s + 1)
		str[i++] = *save++;
	str[i] = '\0';
	return (str);
}
