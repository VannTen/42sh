/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_buffer_interface.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:01:44 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/27 17:36:03 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_BUFFER_INTERFACE_H
# define FILE_BUFFER_INTERFACE_H
# include "lst_interface.h"

/*
** Bufferizing a file.
** Implementation file : file_buffer.c
**
** get_elem_list : Call on a unclosed pipe will hang.
*/

t_lst	*get_no_empty_elem_list(
		int fd,
		char sep,
		t_bool (*is_empty)(char const*));

#endif
