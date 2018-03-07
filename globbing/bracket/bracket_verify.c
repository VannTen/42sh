/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bracket_verify.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heynard <heynard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 16:35:36 by heynard           #+#    #+#             */
/*   Updated: 2018/01/31 16:35:38 by heynard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ft_glob.h"

static void			back_slash_handler(char *str, size_t *i)
{
	int				bs;

	bs = 0;
	while (str[(*i)] == '\\')
	{
		bs++;
		(*i)++;
	}
	if (bs % 2)
		(*i)++;
}

int					bracket_verify(char *str, size_t i)
{
	int				brack;
	int				found;

	brack = 1;
	found = 0;
	while (str[i] && brack)
	{
		if (str[i] == '\\')
			back_slash_handler(str, &i);
		else if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r')
			return (0);
		else if (str[i] == ',' && brack == 1)
		{
			found = 1;
			i++;
		}
		else if (str[i] == '{' || str[i] == '}')
		{
			brack = str[i] == '{' ? brack + 1 : brack - 1;
			i++;
		}
		else
			i++;
	}
	if (brack || !found)
		return (0);
	return (1);
}
