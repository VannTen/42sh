/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_interface.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 11:13:58 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/29 17:22:36 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_INTERFACE_H
# define PATH_INTERFACE_H
# include "bool_interface.h"
# include <stddef.h>

/*
** Navigating in path strings (from one path componenent to another)
** Implementation file : path_tools.c
*/

size_t		get_previous_component(const char *path, size_t index_start);
size_t		path_comp_len(const char *path_elem);
t_bool		path_component_are_equal(const char *path1, const char *path2);
t_bool		is_root_component(const char *path, size_t index);
size_t		advance_nbr_path_comp(const char *path, size_t nbr);

/*
** Joining path elements
** Implementation file : path_join.c
*/

void		get_add_path_before(char **dir, const char *path_to_add);

/*
** Getting path components
** Implementation file : get_path_element.c
*/

const char	*get_file_part(const char *full_path);

/*
** Path canonicalization, as described in cd POSIX manual
** http://pubs.opengroup.org/onlinepubs/9699919799/
** Implementation file : canonical_path.c
*/

char		*canonize_path(char *path);

/*
** Convert path absolute/relative
** Implementation file : path_abs_rel.c
*/

/*
** Do not duplicate the string.
** The return of this string should not be freed, it would be when the string
** given as path parameter will be freed.
*/

size_t		relative_pathname(const char *directory);

#endif
