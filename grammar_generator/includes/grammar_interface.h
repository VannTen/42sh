/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_interface.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 11:33:25 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/09 11:47:48 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAMMAR_INTERFACE_H
# define GRAMMAR_INTERFACE_H
# include "libft.h"
# include "sym_interface.h"
# include "exec_interface.h"

typedef struct s_grammar	t_grammar;

typedef enum	e_grammar_class
{
	LL_1,
	LR_1,
	NB_GRAM_CLASS
}				t_gram_class;

/*
** Grammar creation from text file
** Implementation file : grammar_parse.c
*/

t_grammar	*parse_grammar_fd(int fd);
t_grammar	*parse_grammar_file(char const *grammar_file);
t_grammar	*parse_grammar_string(char const *grammar_string);

/*
** Ressources management
** Implementation file : grammar_ressources.c
*/

void		destroy_grammar(t_grammar **to_destroy);
t_grammar	*create_grammar(void);

/*
** Grammar output as header and source file
** Implementation file : grammar_print_*.c
**
** Deprecated.
*/

void		print_grammar_source(t_grammar const *grammar, int fd_source_file,
		char const *no_use);
void		print_grammar_proto(t_grammar const *grammar, int fd_proto_file,
		char const *name);
void		print_grammar_init(t_grammar const *grammar, int fd_init_file,
		char const *header_name);
void		print_grammar_header(t_grammar const *grammar, int fd_header_file,
		char const *name);
void		print_grammar_names(t_grammar const *grammar,
		int fd_names_file, const char *name);

/*
** Grammar printing (for debug)
** Implementation file : grammar_print.c
*/

void		print_grammar_back(int fd, t_grammar const *gram);

/*
** Test grammar, to see if it satisfy certain properties
** Implementation file : grammar_test.c
*/

t_bool		symbols_are_valid(t_grammar const *gram);
t_bool		is_of_class(t_grammar const *gram, t_gram_class type);

/*
** Grammar comparison
** Implementation file : grammar_cmp.c
*/

t_bool		gram_are_equ(t_grammar const *gram_1, t_grammar const *gram_2);

/*
** Getters
** Implementation file : grammar_get.c
*/

size_t			terminal_sym_count(t_grammar const *gram);
size_t			non_terminal_sym_count(t_grammar const *gram);
t_symbol const	*get_start_symbol(t_grammar const *gram);
t_symbol		*find_sym_by_name(t_grammar const *gram, char const *sym_name);

/*
** Performs transformation on the grammar, in order to make it suitable for some
** kind of parsing techniques.
** Implementation file : grammar_transform.c
*/

t_bool			eliminate_all_left_recursion(t_grammar *gram);

/*
** Left factorize the grammar
** Implementation file : grammar_left_factor.c
*/

t_bool			left_factor_grammar(t_grammar *gram);

/*
** Compute first on all grammar symbols
** Implementation file : grammar_compute_first.c
*/

t_bool			compute_first_grammar(t_grammar *grammar);

/*
** Compute follow for all grammar_symbols
** Implementation file grammar_compure_follow.c
*/

t_bool			compute_follow_grammar(t_grammar *grammar);

/*
** Setup the an equivalent of a parsing table.
** Implementation file : grammar_parsing_table.c
*/

t_bool			compute_parsing_table(
		t_grammar *gram,
		char const **tokens_names);
void const		**create_tokens_table(
		char const **tokens_name,
		t_grammar const *gram);

/*
** Grammar symbol association
** Implementation file : sym_associate_functions.c
*/

t_bool			associate_exec_functions(
		t_grammar const *grammar,
		t_exec const *rules);

#endif
