/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unix_usage_param_opt.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 16:43:52 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/31 14:32:36 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unix_usage_defs.h"
#include <stddef.h>

static t_apply_opt			select_no_param_opt(
		char opt_char,
		const t_synopsis *syn)
{
	size_t	index;

	index = 0;
	while (opt_char != syn->options_char[index]
			&& syn->options_char[index] != '\0')
		index++;
	if (syn->options_char[index] != '\0')
		return (*(syn->options + index));
	else
		return (NULL);
}

static t_apply_opt_param	select_param_opt(
		char opt_char,
		const t_synopsis *syn)
{
	size_t		index;

	index = 0;
	while (opt_char != syn->options_param_char[index]
			&& syn->options_param_char[index] != '\0')
		index++;
	if (syn->options_param_char[index] != '\0')
		return (*(syn->options_param + index));
	else
		return (NULL);
}

enum e_opt_return			apply_arg_opt(
		const size_t opt_char_index,
		char const *const *argv,
		const t_synopsis *syn,
		void *params)
{
	enum e_opt_return	opt_ret;
	t_apply_opt_param	apply_opt;
	const char			*arg;

	if (syn->options_param != NULL)
	{
		apply_opt = select_param_opt(argv[0][opt_char_index], syn);
		if (apply_opt != NULL)
		{
			if (argv[0][opt_char_index + 1] != '\0')
				arg = argv[0] + opt_char_index + 1;
			else
			{
				arg = argv[1];
				if (arg == NULL)
					return (REQ_ARG);
			}
			opt_ret = arg == argv[1] ? NEXT_CONSUMED : CURRENT_CONSUMED;
			return (syn->is_valid(apply_opt(params, arg)) ?
					opt_ret : OPT_INTERN_ERROR);
		}
	}
	return (NO_OPTION);
}

enum e_opt_return			apply_no_arg_opt(
		const char opt_char,
		const t_synopsis *syn,
		void *params)
{
	t_apply_opt	apply_opt;

	if (syn->options != NULL)
	{
		apply_opt = select_no_param_opt(opt_char, syn);
		if (apply_opt != NULL && syn->is_valid(apply_opt(params)))
			return (NOTHING_CONSUMED);
	}
	return (NO_OPTION);
}
