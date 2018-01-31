/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 13:48:37 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/31 17:21:57 by bjanik           ###   ########.fr       */
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
	t_list			*current;
	size_t			nb_matches;
	size_t			search_location;
}					t_comp;

int					completion(t_input *input);
t_list				*open_and_read_directory(t_comp *comp,
					const char *directory);
int					completion_search_path(t_comp *comp);
t_list				*completion_search_in_env(t_comp *comp);
int					completion_display(t_comp comp, t_input *input);

char				*ft_basename(const char *path);
char				*ft_dirname(const char *path);

#endif
