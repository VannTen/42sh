/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_of_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 20:20:19 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/22 15:14:54 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	end_of_input(t_lexer *lexer)
{
	if (delimitate_token(lexer) == MALLOC_FAIL
			|| append_char(lexer) == MALLOC_FAIL
			|| delimitate_token(lexer) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	return (0);
}
