/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:58:40 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/16 16:37:55 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H
# include "libft.h"
# include "pwd.h"
# include "sys/types.h"
# include "uuid/uuid.h"

typedef struct	s_history
{
	char		**history;
	char		*histfile;
	size_t		current;
	size_t		len;
	size_t		size;
}				t_history;

int				import_history_from_file(t_history *history);
int				display_history(t_history history);
int				add_cmd_to_history(t_history *history, char *const command);
int				remove_cmd_from_history(t_history *history, const int offset);
int				clear_all_history(t_history *history);
char			*search_in_history_by_num(t_history *history, const int number);
char			*search_in_history_by_str(t_history *history,
										const char *const str);

#endif
