/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 15:43:43 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/02 11:59:06 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

static void	unexpected_token(char *unexpected_token)
{
	ft_putstr_fd("bash: syntax error near unexpected token `", STDERR);
	ft_putstr_fd(unexpected_token, STDERR);
	ft_putendl_fd("'", STDERR);
}

int			syntax_error(t_parser *parser)
{
	int	type;

	type = parser->cur_token->type;
	if (parser->state == 0 || (parser->state > 2 && parser->state < 10) ||
			(parser->state >= 34 && parser->state <= 37 && type != NEWLINE) ||
			parser->state == 11)
		if (type == NEWLINE)
			ft_putendl_fd("bsh: syntax error near unexpected token `\\n'",
					STDERR);
		else
			unexpected_token(parser->cur_token->token);
	else
		return (END_IS_OP);
	get_bsh()->exit_status = 1;
	return (SYNTAX_ERROR);
}
