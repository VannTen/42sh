/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 13:48:37 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/29 12:33:35 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLETION_H
# define COMPLETION_H
# include "lexer.h"
# include "input.h"
# include "tokens.h"

# define DIRECTORY 0
# define PATH 1

typedef struct		s_comp
{
	char			*prefix;
	char			*dirname;
	char			*basename;
	size_t			basename_len;
	t_list			*matches;
	int				nb_matches;
	size_t			search_location;
}					t_comp;

int					completion(t_input *input);
t_list				*open_and_read_directory(const char *directory,
					const char *basename, const int len);

#endif
