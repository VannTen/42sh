/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 12:43:34 by bjanik            #+#    #+#             */
/*   Updated: 2018/03/01 17:16:15 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			realloc_exp_buffer(t_expander *exp)
{
	char	*tmp;

	tmp = exp->buffer;
	if (!(exp->buffer = ft_strnew(exp->buffer_size * 2)))
	{
		ft_strdel(&tmp);
		return (MALLOC_FAIL);
	}
	exp->buffer_size *= 2;
	ft_strcpy(exp->buffer, tmp);
	ft_strdel(&tmp);
	return (0);
}

inline int	append(t_expander *exp)
{
	if (exp->buffer_len >= exp->buffer_size)
		if (realloc_exp_buffer(exp) == MALLOC_FAIL)
			return (MALLOC_FAIL);
	exp->buffer[exp->buffer_len++] = *(exp->tmp);
	return (0);
}

inline int	skip(t_expander *exp)
{
	(void)exp;
	return (0);
}

inline int	handle_bckslsh(t_expander *exp)
{
	exp->tmp++;
	return (append(exp));
}

inline int	handle_bckslsh_dquote(t_expander *exp)
{
	char	*s;

	s = exp->tmp + 1;
	if (*s == '\\' || *s == '"' || *s == '\n')
		exp->tmp++;
	return (append(exp));
}
