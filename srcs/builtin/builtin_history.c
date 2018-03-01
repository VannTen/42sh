/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:53:10 by bjanik            #+#    #+#             */
/*   Updated: 2018/03/01 19:41:48 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

#define INT_MAX_STR "2147483647"
#define INVALID_OPT 0
#define NUMERIC_ARG_REQUIRED 1

static int	history_usage(const char opt, const int usage_reason)
{
	if (usage_reason == NUMERIC_ARG_REQUIRED)
		ft_dprintf(STDERR_FILENO,
				"42sh: history: option requires an argument\n");
	if (usage_reason == INVALID_OPT)
		ft_dprintf(STDERR_FILENO, "42sh: history: -%c: invalid option\n", opt);
	ft_dprintf(STDERR_FILENO, "history: usage: history [-c] [-d offset] [n]\n");
	return (1);
}

static int	num_is_eligible_to_be_an_entry(char *num)
{
	(num[0] == '+') ? num++ : 0;
	if (ft_str_isdigit(num))
	{
		if (ft_strlen(num) > 10
				|| (ft_strlen(num) == 10 && ft_strcmp(num, INT_MAX_STR)))
			return (0);
	}
	else
		ft_dprintf(STDERR_FILENO, "42sh: history: -d: history position out of"
		" range\n");
	return (1);
}

static int	history_del_one_entry(t_history *history, char *num)
{
	int	n;

	n = 0;
	if (num)
	{
		if (!num_is_eligible_to_be_an_entry(num) || (n = ft_atoi(num)))
			if (remove_cmd_from_history(history, n))
				ft_dprintf(STDERR_FILENO, "42sh: history: -d: history position "
						"out of range\n");
	}
	else
		ft_dprintf(STDERR_FILENO, "42sh: history: -d: option requires an "
					"argument");
	return (0);
}

int			builtin_history(char **args, t_env *env)
{
	t_history	*history;
	char		wrong_opt;
	char		options[3];
	int			i;

	(void)env;
	history = &get_shell_data()->history;
	i = 0;
	while (args[++i] && args[i][0] == '-' && ft_strcmp("--", args[i]))
	{
		if (!args[i][1])
		{
			ft_putendl_fd("bsh: history: `-': not a valid identifier", 2);
			return (1);
		}
		if ((wrong_opt = check_arg_opt(args[i] + 1, "cd", options)))
			return (history_usage(wrong_opt, INVALID_OPT));
	}
	if (ft_strchr(options, 'c'))
		clear_all_history(history);
	else if (ft_strchr(options, 'd'))
		history_del_one_entry(history, args[i]);
	(i == 1) ? display_history(history) : 0;
	return (0);
}
