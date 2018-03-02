/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_defs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 19:33:25 by mgautier          #+#    #+#             */
/*   Updated: 2018/03/02 18:17:01 by heynard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAM_GEN_SYM_DEFS_H
# define GRAM_GEN_SYM_DEFS_H
# include "sym_interface.h"
# include "prods_interface.h"
# include "exec_interface.h"
# include <stddef.h>
# define DERIVATION_SIGN ':'
# define PROD_SEP_SIGN '|'

/*
** prods member is a list of t_prod
*/

struct				s_symbol
{
	char const		*name;
	t_lst			*prods;
	t_lst			*first;
	t_lst			*follow;
	t_prod			**parse_row;
	t_exec const	*exec_functions;
	size_t			token_id;
};

void				iter_del_sym(void **sym);
t_bool				prod_follow(void *prod);
t_bool				add_first_set_to_set(
						t_symbol const *sym,
						t_lst **add_to,
						t_bool *sym_added);
t_bool				add_symbol_to_first_set(
						t_symbol const *sym,
						t_symbol *add_to,
						t_bool *sym_added);
t_bool				add_one_to_follow(
						t_symbol *add_to,
						t_symbol const *sym,
						t_bool *sym_added);
t_bool				compute_follow_sym_step_3(t_symbol *sym,
						t_bool *sym_added);
t_bool				compute_follow_from_first_in_sym(t_symbol *sym);
t_bool				prod_va(void *prod, va_list args);

#endif
