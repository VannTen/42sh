# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Srcs.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/19 07:58:53 by mgautier          #+#    #+#              #
#*   Updated: 2018/01/12 18:32:50 by mgautier         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

# Define target and sources

TARGET := grammar_generator

PRODUCTION :=\
	prod_ressources.c\
	prod_parse.c\
	prod_test.c\
	prod_print.c\
	prod_set.c\
	prod_set_gen.c\
	prod_get.c\
	prod_transform.c\
	prod_equality.c\
	prod_left_factor.c\
	prod_cmp.c\
	prod_compute_first.c\
	prod_compute_follow.c\
	prod_first_set.c\
	prod_exec.c
SYMBOL :=\
	sym_valid.c\
	sym_equality.c\
	sym_parse.c\
	sym_print.c\
	sym_print_back.c\
	sym_set.c\
	sym_get.c\
	sym_get_properties.c\
	sym_get_sets.c\
	sym_empty_symbol.c\
	sym_cmp.c\
	sym_ressources.c\
	sym_transform_lrec.c\
	sym_transform_indirect_lrec.c\
	sym_left_factor.c\
	sym_left_factor_compute.c\
	sym_left_factor_trie_insert_prods.c\
	sym_compute_first.c\
	sym_compute_follow.c\
	sym_associate_functions.c\
	sym_parse_table.c\
	sym_parse_table_get.c
GRAMMAR :=\
	grammar_parse.c\
	grammar_get.c\
	grammar_test.c\
	grammar_cmp.c\
	grammar_ressources.c\
	grammar_transform.c\
	grammar_left_factor.c\
	grammar_compute_first.c\
	grammar_compute_follow.c\
	grammar_print.c\
	grammar_parsing_table.c
EXEC_STACK :=\
	exec_stack_ressources.c\
	exec_stack_meta_construct.c\
	parser_exec_stack.c
PARSER :=\
	parser_generation.c\
	parser_execution.c
TEST_TOOLS :=\
	prod_get_test.c\
	sym_get_test.c\
	test_prods_syms.c\
	sym_parse_table_test.c\
	parse_table_test.c\
	sym_compute_first_test_tools.c\
	sym_compute_follow_test_tools.c\
	grammar_compute_first_test_tools.c\
	grammar_compute_set_test_tools.c\
	compute_first_test_tools.c\
	sym_set_test_tools.c\
	compute_set_test_tools.c\
	arith_expr_test_1.c\
	arith_expr_test_2.c\
	arith_expr_test_destructors.c\
	exec_stack_test.c\
	parser_exec_stack_transition_test.c\
	exec_construct_debug.c

SRC :=\
	$(PRODUCTION)\
	$(SYMBOL)\
	$(GRAMMAR)\
	$(EXEC_STACK)\
	$(PARSER)\
	$(TEST_TOOLS)

#	grammar_print_init.c\
#	grammar_print_proto.c\
#	grammar_print_header.c\
#	grammar_print_source.c\
#	grammar_print_names.c\
	generate_grammar.c\
# Directories

SRC_DIR :=
OBJ_DIR := object
INC_DIR := includes
DEP_DIR := .dep
COMPONENTS :=
LIBRARIES := libft

# Testing

TEST_DIR := test_bin
TEST_SRC_DIR := test
STATIC_TEST_FILES := arithmetic_expr.grammar\
	arithmetic_expr_init.test.c\
	arithmetic_expr_sym_list.test.h\
	arithmetic_expr_names.test.c

## Units tests

DONT_TEST := \
	prod_set_gen.c\
	prod_equality.c\
	sym_equality.c\
	sym_cmp.c\
	sym_left_factor_compute.c\
	sym_left_factor_trie_insert_prods.c\
	sym_get_sets.c\
	sym_empty_symbol.c\
	sym_parse_table_get.c\
	prod_cmp.c\
	prod_compute_first.c\
	prod_compute_follow.c\
	sym_compute_follow.c\
	grammar_print_init.c\
	grammar_print_proto.c\
	grammar_print_header.c\
	grammar_print_source.c\
	grammar_print_names.c\
	grammar_get.c\
	grammar_test.c\
	grammar_print.c\
	generate_grammar.c\
	exec_stack_ressources.c\
	exec_stack_meta_construct.c\
	$(TEST_TOOLS)

## Function tests

TEST_LIST :=
