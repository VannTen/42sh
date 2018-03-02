/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unix_usage_interface.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:38:27 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/31 14:25:47 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIX_USAGE_INTERFACE_H
# define UNIX_USAGE_INTERFACE_H
# include "bool_interface.h"
# define USAGE_ERROR -1

typedef struct s_synopsis	t_synopsis;
typedef	int		(*t_apply_opt)(void *opt);
typedef int		(*t_apply_opt_param)(void *parameters, const char *arg);

/*
** Entry point for programs using the lib
** Implementation file : ft_unix_usage.c
*/

int			apply_cmdline_opt(const t_synopsis *synopsis,
		char const *const *argv, void *params);

/*
** Synopsis initialization
** Implementation file : ft_unix_usage_init.c
*/

t_synopsis	*init_synopsis(const char *simple_opt_syn,
		const t_apply_opt *simple_opt_apply,
		const char *param_opt_syn,
		const t_apply_opt_param *param_opt_apply);
void		deinit_synopsis(t_synopsis **syn);
void		add_opt_validator(t_synopsis *syn, t_bool (*is_valid)(int));
void		add_usage(t_synopsis *syn, void (*usage)(const char*),
		const char *prog_name);
#endif
