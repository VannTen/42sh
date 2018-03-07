/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_parse_bracket.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heynard <heynard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 17:23:47 by heynard           #+#    #+#             */
/*   Updated: 2018/02/11 17:23:48 by heynard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ft_glob.h"

int					glob_parse_bracket(char *str, size_t *i, t_bracket *b)
{
	t_blist			*new;
	t_biglist		*newbig;
	char			*symbol;

	if (bracket_verify(&str[(*i) + 1], 0) == 0)
		return (0);
	(*i)++;
	if (ft_strchr_spec(&(str[*i]), ',', '}'))
	{
		if ((newbig = malloc(sizeof(t_biglist))) == NULL)
		{
			ft_putendl_fd("42sh: memory allocation failed", STDERR_FILENO);
			return (0);
		}
		newbig->blist = NULL;
		newbig->next = NULL;
		while ((symbol = ft_strchr_spec(&(str[*i]), ',', '}')) != NULL)
		{
			newbig = create_blist_recursive(str, *i, newbig, ',');
			glob_move_to_next_char(str, i, ',');
		}
		symbol = ft_strchr(&str[*i], '}');
		if ((new = malloc(sizeof(t_blist))) == NULL)
		{
			ft_putendl_fd("42sh: memory allocation failed", STDERR_FILENO);
			return (0);
		}
		newbig = create_blist_recursive(str, *i, newbig, '}');
		glob_move_to_next_char(str, i, '}');
		b->current++;
		b->pos = 0;
		new = NULL;
		b->biglist = add_biglist(b, newbig);
		bracket_result_alloc(b, ft_strlen(&(str[*i])));
	}
	return (1);
}
