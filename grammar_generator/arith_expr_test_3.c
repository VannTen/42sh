/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arith_expr_test_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heynard <heynard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:34:07 by heynard           #+#    #+#             */
/*   Updated: 2018/03/02 17:47:29 by heynard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test_interface.h"

void		inner_get_token(char **str, t_token *new_token)
{
	if (*str != new_token->start)
		new_token->type = INTEGER;
	else if ((**str) == '(')
		new_token->type = LEFT_PAR;
	else if ((**str) == ')')
		new_token->type = RIGHT_PAR;
	else if ((**str) == '+')
		new_token->type = PLUS;
	else if ((**str) == '*')
		new_token->type = MULT;
	else if ((**str) == '\0')
		new_token->type = END_OF_INPUT;
	else
		destroy_token(&new_token);
}
