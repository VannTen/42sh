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

#include "bsh.h"

void	end_of_input(t_lexer *lexer)
{
	delimitate_token(lexer);
	append_char(lexer);
	delimitate_token(lexer);
}
