/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:51:07 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/18 15:50:42 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
** This file only purpose is to be the libft interface
** It should be only included by source using the libft, and not by the files
** of the lib itself, which should directly include the interface they need.
** This allows a centralized interface for linkage against the lib, while still
** allowing the lib to not recompile fully every time its interface change
*/

# include "includes/useful_macros.h"
# include "includes/btree_interface.h"
# include "includes/fifo_interface.h"
# include "includes/lst_interface.h"
# include "includes/bool_interface.h"
# include "includes/printf.h"
# include "includes/unix_usage_interface.h"
# include "includes/itoa_tools.h"
# include "includes/get_next_line.h"
# include "includes/get_next_elem_interface.h"
# include "includes/unix_files_interface.h"
# include "includes/path_interface.h"
# include "includes/string_interface.h"
# include "includes/string_array_interface.h"
# include "includes/stdout_interface.h"
# include "includes/convert_interface.h"
# include "includes/mem_interface.h"
# include "includes/issomething_interface.h"
# include "includes/misc_interface.h"
# include "includes/math_interface.h"
# include "includes/quote_interface.h"
# include "includes/meta_programming_interface.h"
# include "includes/file_buffer_interface.h"
# include "includes/trie_interface.h"
# include "includes/convert_data_struct_interface.h"
#endif
