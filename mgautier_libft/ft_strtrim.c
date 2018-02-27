/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:56:56 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 16:22:58 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_interface.h"
#include "bool_interface.h"
#include <stddef.h>

/*
** There is two steps in the function :
** first, go to first non blank character (first word)
** then, mesure the length from that character to the last character followed
** only by blank characters.
** With these two informations, create a duplicate of the substring with
** ft_strsub.
*/

static t_bool	ft_isblank(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
			|| c == '\v' || c == '\f' || c == '\r')
		return (TRUE);
	else
		return (FALSE);
}

static size_t	ft_first_word(const char *s)
{
	size_t	index;

	index = 0;
	while (ft_isblank(s[index]))
		index++;
	if (s[index] != '\0')
		return (index);
	else
		return (0);
}

static size_t	ft_len(const char *s)
{
	size_t	index;
	size_t	index_blank;

	index = 0;
	while (s[index] != '\0')
	{
		if (ft_isblank(s[index]))
		{
			index_blank = 1;
			while (ft_isblank(s[index + index_blank]))
				index_blank++;
			if (s[index + index_blank] == '\0')
				return (index);
			else
				index = index + index_blank - 1;
		}
		index++;
	}
	return (index);
}

char			*ft_strtrim(char const *s)
{
	size_t	first_word;

	if (s == NULL)
		return (NULL);
	first_word = ft_first_word(s);
	return (ft_strsub(s, first_word, ft_len(s + first_word)));
}
