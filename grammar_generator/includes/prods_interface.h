/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prods_interface.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 14:06:36 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/12 16:10:50 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAM_GEN_PRODS_INTERFACE_H
# define GRAM_GEN_PRODS_INTERFACE_H
# include "libft.h"
# include <stddef.h>

/*
** A production is one sequence of symbols which can derivate a non-terminal
** symbols
*/

typedef struct s_prod		t_prod;

typedef struct s_symbol		t_symbol;

/*
** Some prods functions take a symbol as and address, so I have to include that
** forward declaration to make it compile. That does not grant access to the
** internals of sym.
** However, I wonder if there could be a better way...
** TODO: Search for another way. Right now C11 is required to compile
** (c99 throw : redefinition of typedef).
** using void pointers instead of t_symbol pointers might do the trick
*/

/*
** Ressources management
** Implementation file : prod_ressources.c
*/

void		destroy_prod(t_prod	**to_destroy);
void		iter_del_prod(void **prod);
t_prod		*create_prod(void);
t_prod		*dup_prod(t_prod const *prod);

/*
** Testing prod
** Implementation file : prod_test.c
** gen_prod -> to be used with "higher order" variadic functions.
*/

t_bool		is_left_recursive(t_prod const *prod, t_symbol const *sym);
t_bool		gen_prod_is_left_recursive(void const *prod, va_list args);

/*
** Getters
** Implementation file : prod_get.c
*/

size_t		get_prod_len(t_prod const *prod);
const char	*get_sym_name_n(t_prod const *prod, size_t index);
void const	*get_sym_of_prod(t_prod const *prod, size_t index);

/*
** Setting prod
** Implementation file : prod_set.c
*/

t_bool		append_to_prod(t_prod *prod, t_symbol const *type);
t_bool		prefix_to_prod(t_prod *prod, t_symbol const *type);
t_prod		*join_prods(t_prod const *prod_1, t_prod const *prod_2);
void		remove_symbols_head(t_prod *prod, size_t nb_sym);
void		remove_symbols_tail(t_prod *prod, size_t nb_sym);

/*
** Generic for prod_set (to be used by iterators)
** Implementaion file : prod_set_gen.c
*/

t_bool		gen_append_to_prod(void *prod, va_list args);
t_bool		gen_prefix_to_prod(void *prod, va_list args);
void		gen_remove_symbols_head(void *prod, va_list args);
void		gen_remove_symbols_tail(void *prod, va_list args);

/*
** Printing prods
** Implemenation file : prod_print.c
*/

void		print_prod(t_prod const *prod, int fd);
void		print_prod_back(t_prod const *prod, int fd);

/*
** Parsing a prod
** Implementation file : prod_parse.c
*/

t_prod		*parse_prod(char const *one_str_prod,
		t_fifo const *sym_parsed,
		t_fifo *sym_pending);

/*
** Prod transformation
** Implementation file : prod_transform.c
*/

t_prod		*produce_developed_prod(t_prod const *developed_sym,
		t_prod const *prod_to_develop);

/*
** Equality (test if two prods are the same, useful for test purposes)
** Implementation file : prod_equality.c
*/

t_bool		prod_are_identical(t_prod const *prod_1, t_prod const *prod_2);
t_bool		prods_set_identical(t_prod const **prod_1, t_prod const **prod_2);

/*
** Comparison
** Implementation file : prod_cmp.c
*/

t_bool		prod_are_equ(t_prod const *prod_1, t_prod const *prod_2);

/*
** Relay to sym
** Functions applied from one sym to the sym contained in its productions
** Implementation file : prod_sym_relay.c
*/

t_bool		add_firsts_of_sub_symbols(
		t_prod const *prod,
		t_symbol *add_to,
		t_bool *sym_added);

/*
** Prod : FOLLOW set computation
** Give to each prod in a sym the FIRST set of the string of grammar symbols
** following it in that prod.
** Implementation file : prod_compute_follow.c
*/

t_bool		compute_follow_prod(t_prod *prod);
t_bool		compute_follow_prod_step_3(
		t_prod *prod, t_symbol const *parent_sym, t_bool *sym_added);

/*
** Check the FIRST set of a prod and eventually the FOLLOW set of its left-hand
** (aka the symbol derived) to fill the entries in a parse table row.
** Implementation file : prod_first_set.c
*/

t_lst		*create_first_set_prod(t_prod const *prod);

/*
** Prod execution
** Implementation file : prod_exec.c
*/

t_bool		add_prod_to_stack(t_prod const *prod, t_lst **stack);

#endif
