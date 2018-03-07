/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_match_square_bracket.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heynard <heynard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:38:16 by heynard           #+#    #+#             */
/*   Updated: 2018/02/02 15:38:17 by heynard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ft_glob.h"

static void				init_square_bracket(t_square_bracket *sqb)
{
	sqb->i = 0;
	sqb->n = 0;
	sqb->no = 0;
	sqb->bslash = 0;
	while (sqb->i < 4096)
		sqb->tabl[(sqb->i)++] = '\0';
	sqb->i = 0;
}

static int				check_in_square_bracket_tab(t_square_bracket *sqb,
													char *tmp,
													char **pattern,
													char s)
{
	sqb->i = 0;
	while (sqb->tabl[sqb->i] != '\0')
	{
		if (sqb->tabl[sqb->i] == s)
		{
			if (sqb->no)
				return (2);
			*pattern = tmp;
			return (0);
		}
		sqb->i++;
	}
	if (sqb->no)
	{
		*pattern = tmp;
		return (0);
	}
	return (2);
}

static void				add_char_in_square_bracket(char *tmp,
													char **pattern,
													t_square_bracket *sqb)
{
	char				c;

	if (*tmp == '-' && (tmp - 1 != *pattern) &&
		*(tmp + 1) != '\0' && *(tmp + 1) != ']'
		&& sqb->bslash == 0 && *(tmp - 1) < *(tmp + 1))
	{
		c = *(tmp - 1);
		while (c <= *(tmp + 1))
		{
			sqb->tabl[(sqb->i)++] = c;
			c++;
		}
	}
	else
		sqb->tabl[(sqb->i)++] = *(tmp);
}

static void				iterate_square_bracket(t_square_bracket *sqb,
												int bslash)
{
	sqb->bslash = bslash;
	sqb->n++;
}

int						ft_glob_match_sqbracket(char s,
												char **pattern)
{
	t_square_bracket	sqb;
	char				*tmp;

	init_square_bracket(&sqb);
	tmp = *pattern + 1;
	while (1)
	{
		if (*tmp == '\0' || *tmp == ' ')
			return (1);
		else if (*tmp == '^' && sqb.n == 0)
			sqb.no = 1;
		else if (*tmp == '\\' && sqb.bslash == 0)
		{
			iterate_square_bracket(&sqb, 1);
			tmp++;
			continue ;
		}
		else if (*tmp == ']' && sqb.bslash == 0)
			break ;
		else
			add_char_in_square_bracket(tmp, pattern, &sqb);
		iterate_square_bracket(&sqb, 0);
		tmp++;
	}
	return (check_in_square_bracket_tab(&sqb, tmp, pattern, s));
}
