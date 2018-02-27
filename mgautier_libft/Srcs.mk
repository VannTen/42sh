# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Srcs.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/19 07:58:53 by mgautier          #+#    #+#              #
#*   Updated: 2018/01/11 17:29:19 by mgautier         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

# Define target and sources

TARGET := libft

# To exclude some files from the compilation (to gain some time on the
# moulinette timeout, for example... ;p) uncomment the line defining the set
# of files to exclude to NOTHING.

#LIB_BTREE = $(NOTHING)
#LIB_LST = $(NOTHING)
#LIB_FIFO = $(NOTHING)
#LIB_STR = $(NOTHING)
#LIB_STR_ARR = $(NOTHING)
#LIB_DISPLAY = $(NOTHING)
#LIB_MEM = $(NOTHING)
#LIB_CONVERT = $(NOTHING)
#LIB_IS_OF = $(NOTHING)
#LIB_MATH = $(NOTHING)
#LIB_MISCELLANEOUS = $(NOTHING)
#LIB_PRINTF = $(NOTHING)
#LIB_UNIX_TOOLS = $(NOTHING)
#LIB_UNIX_FILES = $(NOTHING)
#LIB_BOOLEAN = $(NOTHING)
#LIB_PATH = $(NOTHING)
#LIB_META_PROG = $(NOTHING)
#LIB_CONVERT_SET = $(NOTHING)
#LIB_FILE_IO = $(NOTHING)

LIB_BTREE ?=\
	ft_btree_ressources.c\
	ft_btree_add_take.c\
	ft_btree_use.c\
	ft_tree_node_insert.c\
	ft_tree_node_ressources.c\
	ft_tree_node_traversal.c\
	ft_tree_node_count.c
LIB_LST ?=\
	f_lst_ressources.c\
	f_lst_valid.c\
	f_lstmap.c\
	f_lst_get_elem.c\
	f_lst_insert_remove.c\
	f_lst_insert_remove_end.c\
	f_lst_variadic.c\
	f_lst_variadic_err.c\
	f_lstiter.c\
	f_lst_count.c\
	f_lstarray.c\
	f_strljoin.c\
	f_strsplit_lst.c\
	lst_iter_with_previous.c\
	lst_iter_on_itself.c\
	lst_take_elems.c\
	lst_take_elem.c\
	lst_several.c\
	lst_are_equivalent.c\
	lst_cpy.c\
	lst_cpy_ref.c\
	lst_from_end.c\
	lst_while.c
LIB_FIFO ?=\
	f_fifo_add_take.c\
	f_fifo_ressources.c\
	f_fifo_iter.c\
	fifo_iter_on_itself.c\
	f_fifo_lstrelay.c\
	f_fifo_lstrelay2.c\
	f_fifo_iter_variadic.c\
	f_fifo_every_valid.c\
	fifo_take_elems.c\
	fifo_get_elems.c\
	fifo_get.c\
	fifo_are_equivalent.c\
	fifo_several.c\
	fifo_get_intern.c
LIB_STR ?=\
	ft_strcat.c ft_strchr.c ft_strclr.c \
	ft_strcmp.c ft_strcpy.c ft_strdel.c\
	ft_strdup.c\
	ft_gen_strdup.c\
	ft_strequ.c ft_striter.c \
	ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c\
	ft_strmap.c ft_strmapi.c\
	ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnstr.c \
	ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c\
	ft_gen_strdel.c ft_strnew_char.c ft_strnew.c\
	ft_strvajoin.c\
	last_char_of.c\
	ft_strjoin_ifnot.c\
	ft_substring.c\
	ft_strip.c\
	string_put_gen.c\
	string_cmp_to_other.c
LIB_STR_ARR ?=\
	ft_string_array_dup.c\
	ft_str_array_cpy.c\
	ft_free_string_array.c\
	ft_print_string_array.c\
	string_array_get.c\
	string_array_update.c
LIB_DISPLAY ?=\
	ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
	ft_putnbr_fd.c ft_putstr.c\
	ft_putstr_fd.c
LIB_MEM ?=\
	ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c \
	ft_bzero.c\
	ft_memalloc.c\
	ft_memset.c 
LIB_CONVERT ?=\
	ft_atoi.c\
	ft_itoa.c\
	ft_tolower.c\
	ft_toupper.c\
	ft_itoa_tools.c\
	ft_wctomb.c\
	$(if $(findstring Linux, $(SYSTEM)), ft_wctomb_internal_linux.c,\
	ft_wctomb_internal.c)\
	ft_wcconv_tools.c
LIB_IS_OF ?=\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_isstring.c
LIB_MATH ?=\
	ft_int_square_root.c\
	ft_square_root_round_up.c
LIB_MISCELLANEOUS ?=\
	do_nothing.c\
	get_next_line.c\
	get_next_elem.c\
	misc_error.c\
	quote_correctness.c
LIB_PRINTF ?=\
	ft_printf.c\
	ft_vprintf.c\
	ft_conversion_private_parameters.c\
	ft_flags.c ft_format_string_private.c\
	ft_format_string_parser.c ft_format_string_private_const.c\
	ft_conversion.c\
	ft_conversion_private_get_parameters.c\
	ft_conversion_private_set_parameters.c\
	ft_conversion_private_ressources.c\
	ft_conversion_private_set_var_args.c\
	ft_conversion_private_set_final_length.c\
	ft_conversion_private_write.c\
	ft_conversion_private_is_conv.c\
	ft_conversion_private_is_conv_numeric.c\
	ft_conversion_private_args_index.c\
	ft_conversion_private_is_valid.c\
	ft_conversion_private_function_selectors.c\
	ft_conversion_private_integer_length.c\
	ft_conversion_private_integer_write.c\
	ft_int_params.c ft_int_params_tools.c ft_var_args_private.c\
	ft_format_string_private_get_length.c\
	ft_format_string_private_request_args.c\
	ft_format_string_private_arg_index.c\
	ft_format_string_private_is_valid.c\
	ft_printf_no_conv.c\
	ft_printf_unsupported.c\
	ft_write_result_string.c\
	ft_var_args_private_const.c\
	ft_printf_signed_integers.c\
	ft_printf_unsigned_integers.c\
	ft_printf_unsigned_integers_hexa.c\
	ft_printf_octals.c\
	ft_printf_pointers.c\
	ft_printf_chars.c\
	ft_printf_strings.c
LIB_VARIADIC ?=\
	ft_variadic_get_char.c\
	ft_variadic_get_int.c\
	ft_variadic_get_intmax_t.c\
	ft_variadic_get_long.c\
	ft_variadic_get_long_long.c\
	ft_variadic_get_ptrdiff_t.c\
	ft_variadic_get_short.c\
	ft_variadic_get_size_t.c\
	ft_variadic_no_get.c\
	ft_var_args_private_give.c\
	ft_variadic_args_private_ressources.c
LIB_UNIX_TOOLS ?=\
	ft_unix_usage.c\
	ft_unix_usage_apply.c\
	ft_unix_usage_param_opt.c\
	unix_usage_error.c
LIB_UNIX_FILES ?=\
	is_file.c\
	unix_file_path_name.c
LIB_BOOLEAN ?=\
	boolean.c\
	boolean_on_char.c\
	boolean_on_char_follow.c
LIB_PATH ?=\
	path_tools.c\
	canonical_path.c\
	canonical_path_internals.c\
	path_abs_rel.c\
	get_path_element.c\
	path_join.c
LIB_META_PROG ?=\
	header_guard.c\
	header_42.c
LIB_CONVERT_SET ?=\
	convert_array_list.c
LIB_FILE_IO ?=\
	file_buffer.c
LIB_TRIE ?=\
	trie_ressources.c\
	trie_insert.c\
	trie_print.c\
	trie_list_prefix.c\
	trie_get.c\
	trie_test.c

SRC := $(LIB_BTREE) $(LIB_LST) $(LIB_FIFO)\
	$(LIB_STR)\
	$(LIB_STR_ARR)\
	$(LIB_DISPLAY) $(LIB_MEM)\
	$(LIB_CONVERT) $(LIB_IS_OF) $(LIB_MATH)\
	$(LIB_MISCELLANEOUS) $(LIB_PRINTF) $(LIB_VARIADIC)\
	$(LIB_UNIX_TOOLS) $(LIB_UNIX_FILES) $(LIB_BOOLEAN)\
	$(LIB_PATH) $(LIB_META_PROG) $(LIB_CONVERT_SET)\
	$(LIB_FILE_IO) $(LIB_TRIE)

# Directories

SRC_DIR :=
OBJ_DIR := object
INC_DIR := includes
DEP_DIR := .dep

# Units test

TEST_IT :=\
	lst_iter_with_previous.c\
	f_lst_variadic_err.c\
	f_lst_insert_remove_end.c\
	ft_strsplit.c\
	lst_several.c\
	f_lstmap.c\
	lst_take_elems.c\
	fifo_get_elems.c\
	f_strsplit_lst.c\
	ft_strip.c\
	file_buffer.c\
	lst_iter_on_itself.c\
	lst_are_equivalent.c\
	trie_insert.c\
	trie_list_prefix.c\
	convert_array_list.c\
	lst_from_end.c\
	lst_while.c
DONT_TEST := $(filter-out $(TEST_IT),$(SRC))
TEST_DIR := test_bin
TEST_SRC_DIR := test
