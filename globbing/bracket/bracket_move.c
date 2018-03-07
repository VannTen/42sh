/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bracket_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heynard <heynard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 16:38:04 by heynard           #+#    #+#             */
/*   Updated: 2018/02/11 16:38:07 by heynard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ft_glob.h"

void					glob_move_to_next_char(char *str, size_t *i, char n)
{
	int					bslash;
	int					bracket;

	bracket = 0;
	bslash = 0;
	while (1)
	{
		if ((str[*i] == n && bslash == 0 && bracket == 0) || str[*i] == '\0')
			break ;
		if (str[*i] == '\\' && bslash == 0)
		{
			bslash = 1;
			(*i)++;
			continue ;
		}
		if (str[*i] == '{' && bslash == 0)
			bracket++;
		if (str[*i] == '}' && bslash == 0 && bracket > 0)
			bracket--;
		(*i)++;
	}
	(*i)++;
}
