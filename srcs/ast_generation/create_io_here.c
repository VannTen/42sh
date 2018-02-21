/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_io_here.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:35:19 by ble-berr          #+#    #+#             */
/*   Updated: 2018/01/09 12:43:05 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <fcntl.h>
#include <unistd.h>

static int		io_here_prompt(int const fd, char const *delim,
		int const io_here_id)
{
	size_t const	delim_len = (delim != NULL) ? ft_strlen(delim) : 0;
	char			*prompted;
	char			*str;

	if (!isatty(0))
		return (-1);
	while ((prompted = command_line("heredoc> ")) != NULL)
	{
		str = prompted;
		if (io_here_id == e_redirop_id_dlessdash)
			while (*str == '\t')
				str += 1;
		else if (ft_strncmp(str, delim, delim_len) != 0
				|| ft_strchr("\n", str[delim_len]) == NULL)
			(void)write(fd, str, ft_strlen(str));
		else
		{
			ft_strdel(&prompted);
			return (0);
		}
		ft_strdel(&prompted);
	}
	return (-1);
}

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
		if (id_len == TMPFILE_MAX_ID_LEN)
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

static int		get_heredoc_filedesc(int fd[2])
{
	int				crea_flags;
	uint8_t const	prefix_len = sizeof(SHELL_HEREDOC_PREFIX) - 1;
	char			name[prefix_len + TMPFILE_MAX_ID_LEN];

	crea_flags = O_WRONLY | O_CREAT | O_TRUNC | O_NOFOLLOW | O_EXCL;
	ft_strncpy(name, SHELL_HEREDOC_PREFIX, ARRLEN(name));
	name[prefix_len] = '0';
	while ((fd[0] = open(name, crea_flags, 0644)) == -1)
		if (increment_id(name + prefix_len))
			return (-1);
	if (fd[0] != -1)
	{
		fd[1] = open(name, O_RDONLY);
		if (fd[1] != -1)
			return (0);
		close(fd[0]);
		fd[0] = -1;
	}
	return (1);
}

int				create_io_here(int const op, t_list *token_list)
{
	int						fd[2];
	int						ret;
	char					*delim;

	ft_memset(fd, -1, sizeof(fd));
	if ((op != e_redirop_id_dless && op != e_redirop_id_dlessdash)
			|| token_list == NULL
			|| token_list->data == NULL
			|| (delim = ((struct s_token *)token_list->data)->str) == NULL
			|| ((struct s_token *)token_list->data)->id == e_tokenid_newline)
		shell_errmsg(e_shell_errmsg_inval, __FUNCTION__);
	else if (!get_heredoc_filedesc(fd))
	{
		ret = io_here_tokens(fd[0], delim, token_list->next, op);
		if (ret == 1 || (ret == 0 && io_here_prompt(fd[0], delim, op) == 0))
			return (fd[1]);
		close(fd[0]);
		close(fd[1]);
	}
	return (-1);
}
