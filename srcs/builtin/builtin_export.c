/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:12:09 by bjanik            #+#    #+#             */
/*   Updated: 2018/03/04 18:14:26 by bjanik           ###   ########.fr       */
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

static int	export_option_n(t_env *env, char **argv)
{
	t_env_list	*var;

	if (argv[0])
	{
		if ((var = ft_getenv(env->env_list, argv[0])))
			var->exportable = 0;
		env->has_changed = TRUE;
	}
	append_variable_to_env(env, argv[0], argv[1] ? argv[1] : "",
			LOCAL);
	return (0);
}

int			builtin_export(char **av, t_env *env)
{
	char const	*export_options = "n";
	char		options[2];
	char		wrong_opt;
	int			i;

	if (!av[1])
		return (display_global_env(env->env_list));
	i = 0;
	while (av[++i] && av[i][0] == '-' && ft_strcmp("--", av[i]))
	{
		if (!av[i][1])
		{
			ft_putendl_fd("42sh: history: `-': not a valid identifier", 2);
			return (1);
		}
		if ((wrong_opt = check_arg_opt(argv[i] + 1, export_options, options)))
			return (export_usage(wrong_opt, 0));
	}
	if (ft_strchr(options, 'n'))
		return (export_option_n(env, av + i));
	else if (is_valid_variable_name(av[1]))
		return (append_variable_to_env(env, av[1], av[2] ? av[2] : "", GLOBAL));
	return (ft_dprintf(STDERR_FILENO, "%s: not a valid variable name\n",
				av[1]));
}
