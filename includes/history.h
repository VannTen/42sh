/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 17:57:36 by bjanik            #+#    #+#             */
/*   Updated: 2017/12/09 13:09:15 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H

# define INVALID_OPT 0
# define MISSING_ARG 1

typedef struct	s_history
{
	int			len;
	t_dlst		*head;
	t_dlst		*end;
	t_dlst		*current;
	char		*hist_file;
	int			fd;
}				t_history;

t_history		*init_history(void);
void			append_history(t_history *history, char *cmd, int cmd_size);
int				history_usage(char opt, int type);

#endif
