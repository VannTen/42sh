/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 17:40:47 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/22 15:37:59 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H
# include "libft.h"
# include "lexer.h"
# include "history.h"

int		handle_bang(t_history *history, char **input, t_string *exp_input);
int		get_expanded_input(t_lexer *lexer, t_history *history, char *input,
							t_string *exp_input);
#endif
