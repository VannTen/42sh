/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shx_simple_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:09:31 by ble-berr          #+#    #+#             */
/*   Updated: 2018/01/24 16:04:30 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	call_external(char *const extbin, char **const args,
		int const already_forked)
{
	WIP;
	if (!already_forked)
	{
	}
	EXECVE_HERE;
	return (-1);
}

static int	launch_utility(char **const args, int const already_forked)
{
	union u_utility	utility;
	int				ret;
	pid_t			child;

	if (args != NULL && *args != NULL)
	{
		if (!ft_strchr(*args, "/")
				&& (utility.builtin = get_builtin_utility(*args)) != NULL)
			return (utility.builtin(args));
		if ((utility.external = get_external_utility(*args)) != NULL)
			return (call_external(utility.external, args, already_forked));
	}
	return (0);
}

int			shx_simple_command(struct s_simple_command *const simple_command)
{
	t_list	*fd_backups;
	int		ret;

	if (simple_command != NULL)
	{
		redirection_reset = NULL;
		if (apply_redirections(simple_command->redirs, &fd_backups) == 0)
			ret = launch_utility(simple_command->args, simple_command->child);
		undo_redirections(&fd_backups);
		return (ret);
	}
	return (0);
}
