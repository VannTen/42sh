/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_interface.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 14:11:44 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/12 18:32:23 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAM_GEN_SYM_INTERFACE_H
# define GRAM_GEN_SYM_INTERFACE_H
# include "prods_interface.h"
# include "exec_interface.h"
# include <stdarg.h>
# include <stddef.h>
# define EMPTY_SYMBOL &g_empty_symbol

typedef struct s_symbol	t_symbol;

/*
** Sym specials symbols
** EMPTY_SYMBOL and END_OF_INPUT_SYMBOL are abstraction that are used in FIRST
** and FOLLOW sets. They respectively means that one symbol might be derived
** into and empty string of grammar symbols, and that one symbol might be
** followed by the end of the input stack.
** Implementation file : sym_special_symbols.c
*/

extern t_symbol const	g_empty_symbol;

/*
** Ressources management
** Implementation file : sym_ressources.c
*/

t_symbol		*create_symbol(char const *name);
void			destroy_symbol(t_symbol **to_destroy);
void			iter_del_sym(void **to_del);
void			iter_del_sym_not_prod(void **to_del);
t_symbol		*derivate_new_sym(t_symbol const *src,
		char const *reason_why);

/*
** Setters
** Implementation file : sym_set.c
**
** add_prod : return NULL on succes, prod on failure.
*/

t_prod			*add_prod(t_symbol *sym, t_prod *prod);
void			set_token_id(t_symbol *token, size_t index);

/*
** Getters
** Take left recursive remove a t_prod object from sym and returns it, or return
** NULL if there is no left recursive production in the symbol.
** Implementation file : sym_get.c
*/

t_prod			*take_left_recursive(t_symbol *sym);
t_bool			has_left_recursion(t_symbol const *sym);
char const		*get_name(t_symbol const *sym);
size_t			get_prod_nb(t_symbol const *sym);

/*
** For debug
*/

t_prod const	*get_prod_number(t_symbol const *sym, size_t number);

/*
** Get sym properties
** Implementation file : sym_get_properties.c
*/

t_bool			has_empty_prod(t_symbol const *sym);
t_bool			has_symbol_in_first(
		t_symbol const *sym_first,
		t_symbol const *sym_is_here);
t_bool			is_terminal(t_symbol const *sym);
size_t			get_token_id(t_symbol const *token);

/*
** Printers
** Implementation file : sym_print.c
*/

void			print_sym_initializer(t_symbol const *sym, int fd);

/*
** Printers debug
** Implementation file : sym_print_back.c
*/

void			print_sym_back(t_symbol const *sym, int fd);

/*
** Parsing one symbol
** Implementation file : sym_parse.c
*/

t_symbol		*parse_symbol(char const *str_sym,
		t_fifo *sym_added,
		t_fifo *sym_pending);

/*
** Eliminate simple left recursion in a symbol.
** Implementation file : sym_transform_lrec.c
*/

t_symbol		*eliminate_left_recursion(t_symbol *sym);

/*
** Tool for eliminating indirect left recursion.
** Suppress reference to previous symbols by expanding them into their
** productions
** Implementation file : sym_transform_indirect_lrec.c
*/


t_bool			elim_indirect_left_recursion(
		t_symbol *sym,
		t_symbol const *sym_indir,
		t_bool dev_if_left);

/*
** Left factorize symbols to avoid necessity to have more than one token of
** lookahed when parsing
** Implementation file : sym_left_factor.c
*/

t_bool			left_factor_sym(t_symbol *sym, t_fifo *new_syms);
t_bool			is_result_of_left_factor(t_symbol const *sym);

/*
** Symbols equality (test purposes)
** Implementation file : sym_equality.c
**
** same_sym_parsed() : to be used in higher-order variadic functions.
*/

t_bool			symbol_are_identical(
		t_symbol const *sym,
		t_symbol const *sym_2);
t_bool			same_sym_parsed(const void *v_sym, va_list args);
t_bool			have_same_prods(t_symbol const *sym_1, t_symbol const *sym_2);

/*
** Symbols comparison (to compare different grammars)
** Implementation file : sym_cmp.c
*/

t_bool			sym_are_equ(t_symbol const *sym_1, t_symbol const *sym_2);
t_bool			prods_are_equ(t_symbol const *sym_1, t_symbol const *sym_2);

/*
** Sym valid names
** Implementation file : sym_valid.c
*/

t_bool			is_valid_sym_name_part(char c);
t_bool			is_valid_sym_name(char const *str);

/*
** Sym FIRST set computation
** Implementation file : sym_compute_first.c
*/

t_bool			compute_sym_first_set(t_symbol *sym, t_bool *sym_added);
t_bool			add_first_set_to_first_set(
		t_symbol const *sym,
		t_symbol *add_to,
		t_bool *sym_added);
t_bool			add_symbol_to_first_set(
		t_symbol const *sym,
		t_symbol *add_to,
		t_bool *sym_added);
t_bool			add_symbol_to_set(
		t_symbol const *sym,
		t_lst **set,
		t_bool *sym_added);
t_bool			add_first_set_to_set(
		t_symbol const *sym,
		t_lst **add_to,
		t_bool *sym_added);

/*
** Sym first set getters
** Implementation file : sym_get_sets.c
*/

t_bool			has_symbol_in_first(
		t_symbol const *search_in, t_symbol const *to_find);
t_bool			has_symbol_in_follow(
		t_symbol const *search_in, t_symbol const *to_find);
t_lst const		*get_first_set(t_symbol const *sym);
t_lst const		*get_follow_set(t_symbol const *sym);
t_bool			has_symbol_in_set(t_lst const *set, t_symbol const *to_find);

/*
** Sym FOLLOW set computation
** Implementation file : sym_compute_follow.c
*/

t_bool			compute_follow_from_first_in_sym(t_symbol *sym);
t_bool			compute_follow_sym_step_3(t_symbol *sym, t_bool *sym_added);
t_bool			add_to_follow(t_symbol *sym, t_lst const *syms_to_add);
t_bool			add_one_to_follow(
		t_symbol *add_to,
		t_symbol const *sym,
		t_bool *sym_added);
t_bool			add_set_to_follow_set(
		t_symbol *add_to,
		t_lst const *set_to_add,
		t_bool *sym_is_added);

/*
** Generation of the parsing table.
** Generate a row of the parse table for each non-terminal symbol.
** (taken all together, they form the parse table).
** Implementation file : sym_parse_table.c
*/

t_bool			init_sym_parse_table(t_symbol *sym, size_t nb_tokens);
t_bool			fill_sym_parse_table(t_symbol *sym, char const **token_name);

/*
** Get parse table
** Implementation file : sym_parse_table_get.c
*/

t_prod const	*get_prod_for_token(t_symbol const *sym, size_t token_id);

/*
** Sym exec related stuff
** Implementation file : sym_associate_functions.c
*/

t_exec const	*get_exec_functions(t_symbol const *sym);
t_bool			is_exec_construct(t_symbol const *sym);

#endif
