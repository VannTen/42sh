/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:12:09 by bjanik            #+#    #+#             */
/*   Updated: 2018/03/01 19:41:21 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <unistd.h>
#include "execution.h"

static int	export_usage(const char opt, const int usage_reason)
{
	(void)usage_reason;
	ft_dprintf(STDERR_FILENO, "42sh: export: -%c: invalid option\n", opt);
	ft_dprintf(STDERR_FILENO, "export: usage: export [-n] [name [value]] \n");
	return (1);
}

static int	export_option_n(t_env_list *env_list, char *arg)
{
	t_env_list	*var;

	if (arg)
	{
		if ((var = ft_getenv(env_list, arg)))
			var->exportable = 0;
	}
	return (0);
}

int			builtin_export(char **argv, t_env *env)
{
	char const	*export_options = "n";
	char		options[2];
	char		wrong_opt;
	int			i;

	if (!argv[1])
		return (display_global_env(env->env_list));
	i = 0;
	while (argv[++i] && argv[i][0] == '-' && ft_strcmp("--", argv[i]))
	{
		if (!argv[i][1])
		{
			ft_putendl_fd("42sh: history: `-': not a valid identifier",
						STDERR_FILENO);
			return (1);
		}
		if ((wrong_opt = check_arg_opt(argv[i] + 1, export_options, options)))
			return (export_usage(wrong_opt, 0));
	}
	if (ft_strchr(options, 'n'))
		return (export_option_n(env->env_list, argv[i]));
	else if (is_valid_variable_name(argv[1]))
		return (append_variable_to_env(env, argv[1], argv[2], GLOBAL));
	return (ft_dprintf(STDERR_FILENO, "%s: not a valid variable name\n",
			argv[1]));
}
