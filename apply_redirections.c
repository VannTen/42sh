/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 10:38:54 by ble-berr          #+#    #+#             */
/*   Updated: 2018/01/24 16:07:33 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

static struct s_fd_backup	create_fd_backup(int const fd)
{
	struct s_fd_backup	*new_backup;
	int					save;

	if (fcntl(fd, F_GETFD) == - 1)
		save = -1;
	else if ((save = dup(fd)) == -1)
	{
		ft_putstr_fd("42sh: failed to duplicate filedescriptor.\n", 2);
		return (NULL);
	}
	new_backup = (struct s_redir_backup*)malloc(sizeof(*new_backup));
	if (new_backup != NULL)
	{
		new_backup->origin = fd;
		new_backup->save = backup_fd;
	}
	else
		ft_putstr_fd("42sh: allocation attempt failed.\n", 2);
	return (new_backup);
}

static int					add_fd_backup(int const fd,
		t_list **const fd_backups)
{
	void	*backup;
	t_list	*new_elem;

	backup = create_fd_backup(fd);
	if (backup != NULL)
		if ((new_elem = (t_list *)malloc(sizeof(*new_elem))) != NULL)
		{
			new_elem->content = backup;
			ft_lstadd(fd_backups, backup);
			return (0);
		}
		else
			ft_putstr_fd("42sh: allocation attempt failed.\n", 2);
	ft_putstr_fd("42sh: unable to backup filedescriptor.\n", 2);
	return (1);
}

int							apply_redirections(t_list *redirection_list,
		t_list **const fd_backups)
{
	struct s_redirection	*redir;

	while (redirection_list != NULL)
	{
		redir = redirection_list->content;
		if (redir != NULL && redir->ft != NULL
				&& add_fd_backup(redir->ionum) != 0
				&& redir->ft(redir->ionum, redir->target, *fd_backups) != 0)
			redirection_list = redirection_list->next;
		else
			return (1);
	}
	return (0);
}
