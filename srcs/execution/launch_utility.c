/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_utility.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 11:39:12 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/25 19:59:25 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "execution.h"
#include "hashtable.h"
#include "builtins.h"

static char			*find_external(char *const name,
		struct s_shx_global *const global)
{
	char	*external;

	external = get_path_table(global->hashtable, name);
	if (external != NULL)
	{
		if ((external = ft_strdup(external)) == NULL)
			ft_putstr_fd("42sh: allocation error\n", 2);
	}
	else
		external = sh_path_search(global->env, name);
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

int					launch_utility(char **argv, t_bool is_child,
		struct s_shx_global *const global)
{
	t_builtin	builtin;
	char		*external;
	int			ret;

	if (argv != NULL && argv[0] != NULL)
	{
		if (ft_strchr(argv[0], '/'))
			return (launch_external(argv[0], argv, global, is_child));
		builtin = find_builtin(argv[0]);
		if (builtin != NULL)
			return(builtin(argv, global->env));
		external = find_external(argv[0], global);
		if (external != NULL)
		{
			ret = launch_external(external, argv, global, is_child);
			free(external);
			return (ret);
		}
		ft_dprintf(2, "42sh: %s: command not found\n", argv[0]);
	}
	return (-1);
}
