/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_defs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 19:33:25 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/12 18:34:13 by mgautier         ###   ########.fr       */
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

struct s_symbol
{
	char const		*name;
	t_lst			*prods;
	t_lst			*first;
	t_lst			*follow;
	t_prod			**parse_row;
	t_exec const	*exec_functions;
	size_t		token_id;
};

#endif
