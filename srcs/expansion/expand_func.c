/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:05:33 by bjanik            #+#    #+#             */
/*   Updated: 2017/12/07 12:10:25 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

void		realloc_exp_buffer(t_expander *exp)
{
	char	*tmp;

	tmp = exp->buffer;
	if (!(exp->buffer = (char*)malloc((exp->buffer_size * 2) * sizeof(char))))
		ft_error_msg("Realloc_exp_buffer failed\n");
	exp->buffer_size *= 2;
	ft_bzero(exp->buffer, exp->buffer_size);
	ft_strcpy(exp->buffer, tmp);
	free(tmp);
}

inline void	append(t_expander *exp)
{
	if (exp->buffer_len == exp->buffer_size)
		realloc_exp_buffer(exp);
	exp->buffer[exp->buffer_len++] = *(exp->tmp);
}

inline void	skip(t_expander *exp)
{
	(void)exp;
}

inline void	handle_bckslsh(t_expander *exp)
{
	exp->tmp++;
	if (*(exp->tmp) != '\n')
		append(exp);
}

inline void	handle_bckslsh_dquote(t_expander *exp)
{
	char	*s;

	s = exp->tmp + 1;
	if (*s == '\\' || *s == '"' || *s == '\n')
		exp->tmp++;
	if (*(exp->tmp) != '\n')
		append(exp);
}
