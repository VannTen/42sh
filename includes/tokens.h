/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 17:58:23 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/26 13:16:40 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENS_H
# define TOKENS_H
# include "libft.h"

enum
{
	WORD,
	NEWLINE,
	IO_NUMBER,
	DLESS,
	DGREAT,
	LESSAND,
	GREATAND,
	LESS,
	GREAT,
	AND_IF,
	OR_IF,
	SEMI,
	AND,
	PIPE,
	CLOBBER,
	LESS_GREAT,
	DLESSDASH,
};

typedef struct		s_token
{
	char			*value;
	size_t			type;
	struct s_token	*next;
	struct s_token	*prev;
}					t_token;
#endif
