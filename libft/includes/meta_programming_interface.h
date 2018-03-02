/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_programming_interface.h                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:45:49 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/07 15:15:20 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef META_PROGRAMMING_INTERFACE_H
# define META_PROGRAMMING_INTERFACE_H

/*
** Printing standard C header guards
** Implementation file : header_guard.c
*/

void	print_header_guard_in(int fd, char const *file_name);
void	print_header_guard_out(int fd);

/*
** Print 42 header
** Implementation file : header_42.c
*/

void	print_header_42(int fd, char const *file_name);

#endif
