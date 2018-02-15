/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:53:10 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/15 17:22:30 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

#define INT_MAX_STR "2147483647"
#define INVALID_OPT 0
#define NUMERIC_ARG_REQUIRED 1

static int	history_usage(const char opt, const int usage_reason)
{
	if (usage_reason == NUMERIC_ARG_REQUIRED)
		ft_dprintf(STDERR_FILENO, "bsh: history: option requires an argument\n");
	if (usage_reason == INVALID_OPT)
		ft_dprintf(STDERR_FILENO, "bsh: history: -%c: invalid option\n", opt);
	ft_dprintf(STDERR_FILENO, "history: usage: history [-c] [-d offset] [n]\n");
	return (1);
}

static int	num_is_eligible_to_be_an_entry(const char *num)
{
	if ((num[0] == '+' && ft_strisdigit(num + 1)) || ft_strisdigit(num))
	{
		if (ft_strlen(num + (num[0] == '+')) > ft_strlen(INT_MAX_STR))
			return (0);
	if (ft_strcmp(num, INT_MAX_STR) >= 0)
}

static int	history_del_one_entry(t_history *history, const char *num)
{
	if (num)
	{
		if (num[0] == '+' ||
	}
	else
	{
		ft_dprintf(STDERR_FILENO, "bsh: history: -d: option requires an "
								"argument");
	}
	return (0);
}

int	builtin_history(char **args, t_env *env)
{
	t_history	*history;
	char const	history_options[] = "cd";
	char		wrong_opt;
	char		options[3];

	history = &get_shell_data()->history;
	i = 0;
	while (args[++i] && args[i][0] == '-' && ft_strcmp("--", args[i]))
	{
		if (!args[i][1])
		{
			ft_putendl_fd("bsh: history: `-': not a valid identifier", STDERR);
				return (1);
		}
		if ((wrong_opt = check_arg_opt(args[i] + 1, HISTORY_OPTIONS, options)))
			return (history_usage(wrong_opt, INVALID_OPT));
	}
	if (ft_strchr(options, 'c'))
		clear_all_history(history);
	if (ft_strchr(options, 'd'))
		history_del_one_entry(history, args[i]);
	(i == 1) ? display_history(history) : 0;
	return (0);
}
