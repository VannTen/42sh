/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_here_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 10:32:04 by ble-berr          #+#    #+#             */
/*   Updated: 2017/12/14 11:23:23 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static t_list	*find_next_newline(t_list *start)
{
	struct s_token	*token;

	while (start != NULL)
	{
		token = start->data;
		if (token == NULL)
		{
			shell_errmsg(e_shell_errmsg_inval, __FUNCTION__);
			return (NULL);
		}
		if (token->id == e_tokenid_newline)
			return (start);
		else
			start = start->next;
	}
	return (start);
}

static int		write_to_io_here(int const fd, char const *delim,
		int const io_here_id, char const *str)
{
	if (io_here_id == e_redirop_id_dlessdash)
	{
		while (*str == '\t')
			str += 1;
	}
	else if (ft_strcmp(str, delim) != 0)
		write(fd, str, ft_strlen(str));
	else
		return (1);
	return (0);
}

int				io_here_tokens(int const fd, char const *delim,
		t_list *start, int const io_here_id)
{
	t_list		*end;
	char const	*str;

	if ((start = find_next_newline(start)) == NULL)
		return (0);
	else if (start->data == NULL)
		return (-1);
	end = start->next;
	while (end != NULL)
		if (end->data == NULL
				|| (str = ((struct s_token *)end->data)->str) == NULL)
		{
			shell_errmsg(e_shell_errmsg_inval, __FUNCTION__);
			return (-1);
		}
		else if (write_to_io_here(fd, delim, io_here_id, str))
		{
			ft_lstdel_to(&start->next, end, &tokendel);
			return (1);
		}
		else
			end = end->next;
	ft_lstdel_to(&start->next, end, &tokendel);
	return (0);
}
