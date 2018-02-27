/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol_interface.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 10:49:41 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/07 11:45:29 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOL_INTERFACE_H
# define SYMBOL_INTERFACE_H
# include "arithmetic_expr_sym_list.h"
# include <stddef.h>

typedef struct s_symbol	t_symbol;

t_symbol_type	*generate_one_production(size_t nb, ...);
void			print_symbol(t_symbol const *sym);
void			destroy_symbol(t_symbol **to_destroy);

# define SYMBOL_END NB_SYMBOLS

#endif
