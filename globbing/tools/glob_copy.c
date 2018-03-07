/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_spec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heynard <heynard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 13:52:21 by heynard           #+#    #+#             */
/*   Updated: 2017/06/21 15:09:35 by heynard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ft_glob.h"

static size_t		glob_strlen_spec(const char *str,
										char spec,
										size_t i,
										int bracket)
{
	int				bslash;

	bslash = 0;
	while (1)
	{
		if (str[i] == '\0')
			break ;
		if (str[i] == spec && bslash == 0 && bracket == 0)
			break ;
		if (str[i] == '\\' && bslash == 0)
		{
			bslash = 1;
			i++;
			continue ;
		}
		if (str[i] == '{' && bslash == 0)
			bracket++;
		if (str[i] == '}' && bslash == 0 && bracket > 0)
			bracket--;
		bslash = 0;
		i++;
	}
	return (i);
}

static void			glob_fill_recursive_string(char *str, char *new, char spec,
												int bracket)
{
	size_t			i;
	int				bslash;

	i = 0;
	bslash = 0;
	while (1)
	{
		if ((str[i] == spec && bslash == 0 && bracket == 0) || str[i] == '\0')
			break ;
		if (str[i] == '\\' && bslash == 0)
		{
			bslash = 1;
			new[i] = str[i];
			i++;
			continue ;
		}
		if (str[i] == '{' && bslash == 0)
			bracket++;
		if (str[i] == '}' && bslash == 0 && bracket > 0)
			bracket--;
		new[i] = str[i];
		bslash = 0;
		i++;
	}
	new[i] = '\0';
}

char				*glob_strcpy_spec(char *str, char spec)
{
	char			*new;

	if ((new = (char *)malloc(sizeof(char) *
					glob_strlen_spec(str, spec, 0, 0) + 1))
							== NULL)
		return (NULL);
	glob_fill_recursive_string(str, new, spec, 0);
	return (new);
}
