/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unix_usage_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 12:27:13 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/26 14:02:18 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unix_usage_defs.h"
#include "printf.h"
#include "bool_interface.h"
#include <unistd.h>

void	print_option_error(const char *prog_name, const char option,
		enum e_opt_return error)
{
	const char	*error_strings[] = {
		"%s: illegal option -- %c\n",
		"%s: option requires an argument -- %c\n",
		"%s: option encountederd an error -- %c\n"
	};

	ft_dprintf(STDERR_FILENO, error_strings[error], prog_name, option);
}

t_bool	option_had_trouble(enum e_opt_return error)
{
	return (error >= NO_OPTION && error <= OPT_INTERN_ERROR);
}
