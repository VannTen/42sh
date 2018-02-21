/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 18:57:04 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/21 22:51:08 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "bleberr_macros.h"
#include "io_here.h"

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

static t_bool	fill_until_here_end(int const doc_fd, char *const read_buf,
		char const *const here_end, size_t const here_end_len)
{
	int 	read_ret;
	t_bool	fresh_line;

	fresh_line = TRUE;
	while (42)
	{
		if (fresh_line)
			ft_dprintf(STDERR_FILENO, "heredoc>");
		if (1 < (read_ret = read(STDIN_FILENO, read_buf, here_end_len + 1)))
			if ((size_t)read_ret == here_end_len + 1 && fresh_line
					&& ft_memcmp(read_buf, here_end, read_ret - 1)
					&& read_buf[read_ret] != '\n')
				return (TRUE);
			else
			{
				write(doc_fd, read_buf, read_ret);
				fresh_line = (size_t)read_ret < here_end_len + 1;
			}
		else
			return (read_ret == 0);
	}
}

static t_bool	fill_heredoc(int const doc_fd, char const *const here_end,
		size_t const here_end_len)
{
	t_bool	ret;
	char	*read_buf;

	if ((read_buf = (char*)malloc(sizeof(char) * (here_end_len + 1))) != NULL)
	{
		ret = fill_until_here_end(doc_fd, read_buf, here_end, here_end_len);
		ft_strdel(&read_buf);
		return (ret);
	}
	else
		return (FALSE);
}

char			*create_heredoc(char const *const here_end)
{
	char	*doc_name;
	int		doc_fd;

	if (here_end != NULL && (doc_fd = open_heredoc(&doc_name)) != -1)
	{
		fill_heredoc(doc_fd, here_end, ft_strlen(here_end));
		close(doc_fd);
		return (doc_name);
	}
	else
		return (NULL);
}
