/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:12:09 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/25 20:37:17 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <unistd.h>

static int	export_usage(const char opt, const int usage_reason)
{
	ft_dprintf(STDERR_FILENO, "export: usage: export [-n] [name [value]] \n");
	return (1);
}

static int	export_option_n(char *arg)
{
	t_env_list	*var;

	if ((var = ft_getenv(arg))
		var->exportable = 0;
	return (0);
}

int	builtin_export(char **argv, t_env *env)
{
	char const	export_options[] = "n";
	char		options[2];
	int			i;

	if (!argv[1])
		return (display_global_env((*env)->env_list));
	i = 0;
	while (args[++i] && args[i][0] == '-' && ft_strcmp("--", args[i]))
	{
		if (!args[i][1])
		{
			ft_putendl_fd("42sh: history: `-': not a valid identifier",
						STDERR_FILENO);
				return (1);
		}
		if ((wrong_opt = check_arg_opt(args[i] + 1, HISTORY_OPTIONS, options)))
			return (export_usage(wrong_opt, INVALID_OPT));
	}
	if (ft_strchr(options, 'n'))
		return (export_option_n(argv[i]));
	else if (is_valid_env_variable_name(argv[1]))
		return (add_variable_to_env(argv[1], argv[2] ? argv[2] : ""));
	else
		return (ft_dprintf(STDERR_FILENO, "%s: not a valid variable name\n",
					argv[1]);
}
