/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_of_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 20:20:19 by bjanik            #+#    #+#             */
/*   Updated: 2017/10/19 15:59:17 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	end_of_input(t_lexer *lexer)
{
	if (delimitate_token(lexer) == MALLOC_FAIL
			|| append_char(lexer) == MALLOC_FAIL
			|| delimitate_token(lexer) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	return (0);
}
