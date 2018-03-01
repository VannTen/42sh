/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shx_simple_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:09:31 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/01 16:51:49 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "shell.h"

static char	*resolved_arg(char *arg)
{
	t_bsh *const	bsh = get_shell_data();
	char			*ret;

	ret = bsh && arg ? expanded_str(&bsh->exp, arg, NOT_HERE_END_EXP) : NULL;
	return (ret);
}

static void	delete_argv(char **argv)
{
	size_t	i;

	if (argv != NULL)
	{
		i = 0;
		while (argv[i] != NULL)
		{
			free(argv[i]);
			i += 1;
		}
		free(argv);
	}
}

static char	**create_argv(t_lst *arglist, size_t const argc)
{
	char	**argv;
	size_t	i;

	argv = (char**)malloc((argc + 1) * sizeof(char*));
	if (argv != NULL)
	{
		i = 0;
		while (i < argc)
		{
			argv[i] = resolved_arg((void*)get_lst_elem(arglist, 0));
			if (argv[i] == NULL)
			{
				delete_argv(argv);
				return (NULL);
			}
			arglist = advance_list(arglist, 1);
			i += 1;
		}
		argv[i] = NULL;
	}
	return (argv);
}

int			shx_simple_command(struct s_sh_simple_command *const simple_command)
{
	char	**argv;
	t_lst	*fd_backups;
	int		ret;

	if (simple_command != NULL)
	{
		argv = create_argv(simple_command->arglist, simple_command->argc);
		if (argv == NULL)
			return (0);
		fd_backups = NULL;
		if (apply_redirections(simple_command->redirs, &fd_backups) == 0)
			ret = launch_utility(argv, simple_command->child);
		else
			ret = 42;
		undo_redirections(&fd_backups);
		delete_argv(argv);
		return (ret);
	}
	return (0);
}
