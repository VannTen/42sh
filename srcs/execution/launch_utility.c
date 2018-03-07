/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_utility.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 11:39:12 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/07 11:03:27 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "execution.h"
#include "hashtable.h"
#include "builtins.h"
#include "shell.h"

static char			*find_external(char *const name, t_bsh *const bsh)
{
	char			*external;

	external = get_path_table(&bsh->hashtable, name);
	if (external != NULL)
	{
		if ((external = ft_strdup(external)) == NULL)
			ft_putstr_fd("42sh: allocation error\n", 2);
	}
	else
		external = sh_path_search(&bsh->env, name);
	if (external && bsh && add_hash_table(&bsh->hashtable, name, external))
		ft_dprintf(STDERR_FILENO, "42sh: failed to add %s to hashtable\n",
				external);
	return (external);
}

static t_builtin	find_builtin(char *name)
{
	size_t	i;

	i = 0;
	while (i < BUILTIN_COUNT)
	{
		if (!ft_strcmp(name, g_builtin_array[i].name))
			return (g_builtin_array[i].ft);
		i += 1;
	}
	return (NULL);
}

int					launch_utility(char **argv, t_bool is_child)
{
	t_bsh *const	bsh = get_shell_data();
	t_builtin		builtin;
	char			*external;

	if (bsh && argv != NULL)
	{
		if (!argv[0])
			bsh->exit_status = 0;
		else if (ft_strchr(argv[0], '/'))
			return (launch_external(argv[0], argv, &bsh->env, is_child));
		else if ((builtin = find_builtin(argv[0])))
			bsh->exit_status = builtin(argv, &bsh->env);
		else if ((external = find_external(argv[0], bsh)))
		{
			(void)launch_external(external, argv, &bsh->env, is_child);
			free(external);
		}
		else
		{
			bsh->exit_status = -1;
			ft_dprintf(2, "42sh: %s: command not found\n", argv[0]);
		}
		return (bsh->exit_status);
	}
	return (-1);
}
