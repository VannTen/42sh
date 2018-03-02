/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:21:34 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/27 17:40:25 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_buffer_interface.h"
#include "lst_interface.h"
#include "string_interface.h"
#include "custom_stddef.h"
#include <unistd.h>
#include <stdlib.h>

static char const	g_string_file[] =
"One line\n"
"\n "
"Two lines\n"
"\n "
"\n ";

static t_bool		is_empty(char const *str)
{
	size_t	index;

	index = 0;
	while (str[index] == '\n' || str[index] == ' ')
		index++;
	return (str[index] == '\0');
}

int					main(void)
{
	int		pipes[2];
	t_lst	*lst;
	t_bool	result;

	pipe(pipes);
	ft_putstr_fd(g_string_file, pipes[WRITE_END]);
	close(pipes[WRITE_END]);
	lst = get_no_empty_elem_list(pipes[READ_END], '\n', is_empty);
	result = f_lst_len(lst) == 2;
	f_lstdel(&lst, ft_gen_strdel);
	return (result ? EXIT_SUCCESS : EXIT_FAILURE);
}
