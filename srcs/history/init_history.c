/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 12:39:42 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/24 13:14:49 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libft.h"
#include <unistd.h>
#include <stddef.h>

/*
** Returns HOME directory.
*/

static char	*get_home_dir(void)
{
	struct passwd	*pw;

	if (!(pw = (struct passwd*)getpwuid(getuid())))
		return (NULL);
	return (pw->pw_dir);
}

int			init_history(t_history *history, int size)
{
	if (size < 0 || size > DEFAULT_HISTSIZE)
		size = DEFAULT_HISTSIZE;
	if (!(history->history = (char**)malloc(sizeof(char*) * (size + 1))))
		return (MALLOC_FAIL);
	ft_memset(history->history, 0, (size + 1) * sizeof(char*));
	history->file = ft_strvajoin(3, get_home_dir(), "/", ".42sh_history");
	if (history->file == NULL)
		return (MALLOC_FAIL);
	history->current = 0;
	history->len = 0;
	history->size = size;
	return (0);
}
