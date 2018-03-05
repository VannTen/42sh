/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 18:57:04 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/05 17:23:08 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "bleberr_macros.h"
#include "io_here.h"
#include "shell.h"

static int		increment_id(char *id)
{
	uint8_t	const	id_len = ft_strlen(id);
	char const		*tmp;
	uint8_t			i;
	char			alnum[10 + 26 + 26 + 1];

	ft_strcpy(alnum, "013456789"
			"abcdefghijklmnopqrstuvwxyz"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	i = id_len - 1;
	while (0 < i && id[i] == 'Z')
		i -= 1;
	if (i == 0 && id[i] == 'Z')
		if (id_len == HEREDOC_MAX_ID_LEN)
			return (1);
		else
		{
			ft_memset(id, '0', id_len + 1);
			id[id_len + 1] = 0;
		}
	else if ((tmp = ft_strchr(alnum, id[i])) == NULL || *tmp == 0)
		return (1);
	else
		id[i] = tmp[1];
	return (0);
}

static int		open_heredoc(char **const doc_name_loc)
{
	int				crea_flags;
	uint8_t const	prefix_len = sizeof(HEREDOC_PREFIX) - 1;
	char			*doc_name;
	int				doc_fd;

	if ((doc_name = ft_strnew(prefix_len + HEREDOC_MAX_ID_LEN)) != NULL)
	{
		crea_flags = O_WRONLY | O_CREAT | O_TRUNC | O_NOFOLLOW | O_EXCL;
		ft_strncpy(doc_name, HEREDOC_PREFIX, prefix_len);
		doc_name[prefix_len] = '0';
		doc_name[prefix_len + 1] = 0;
		while ((doc_fd = open(doc_name, crea_flags, 0644)) == -1)
			if (increment_id(doc_name + prefix_len) != 0)
			{
				free(doc_name);
				return (-1);
			}
		*doc_name_loc = doc_name;
		return (doc_fd);
	}
	else
		return (-1);
}

char			*create_heredoc(char *here_end, t_bool is_dlessdash)
{
	t_bsh *const	bsh = get_shell_data();
	char			*doc_name;
	int				doc_fd;
	int				ret;

	here_end = bsh && here_end ?
		expanded_str(&bsh->exp, here_end, HERE_END_EXP) : NULL;
	if (here_end != NULL && (doc_fd = open_heredoc(&doc_name)) != -1)
	{
		ret = fill_heredoc(doc_fd, here_end, ft_strlen(here_end), is_dlessdash);
		ft_strdel(&here_end);
		close(doc_fd);
		if (ret)
			return (doc_name);
		else
		{
			close(doc_fd);
			unlink(doc_name);
			ft_strdel(&doc_name);
		}
	}
	return (NULL);
}
