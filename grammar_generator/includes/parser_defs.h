/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_defs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:55:25 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/18 17:55:25 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_DEFS_H
# define PARSER_DEFS_H
# include "parser_interface.h"
# include "grammar_interface.h"

enum
{
	PARSE,
	EXEC
};

struct	s_parse_state
{
	t_lst	*parse_stack;
	t_lst	*exec_stack;
	void	*token;
};

struct	s_parser
{
	t_grammar	*grammar;
	void const	**tokens;
	size_t		(*get_token_id)(void const *token);
};

#endif
