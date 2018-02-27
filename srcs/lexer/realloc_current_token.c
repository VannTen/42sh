/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_current_token.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 20:22:35 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/11 19:33:54 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		realloc_current_token(t_lexer *lexer)
{
	char	*tmp;

	tmp = lexer->current_token;
	if (!(lexer->current_token = ft_strnew((lexer->token_size * 2)
			* sizeof(char))))
		return (MALLOC_FAIL);
	lexer->token_size *= 2;
	ft_strcpy(lexer->current_token, tmp);
	ft_strdel(&tmp);
	return (0);
}
