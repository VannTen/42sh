/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heynard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 18:36:25 by heynard           #+#    #+#             */
/*   Updated: 2017/01/06 13:34:52 by heynard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strchr_spec(char *s, int c, char spec)
{
	int		bracket;
	int		bslash;

	bslash = 0;
	bracket = 0;
	while (*s != '\0' || (*s == spec && bracket == 0))
	{
		if (*s == c && bslash == 0 && bracket == 0)
			return (s);
		if (*s == '\\' && bslash == 0)
		{
			bslash = 1;
			continue ;
		}
		if (*s == '{' && bslash == 0)
			bracket++;
		if (*s == '}' && bslash == 0 && bracket > 0)
			bracket--;
		s++;
		bslash = 0;
	}
	return (NULL);
}
