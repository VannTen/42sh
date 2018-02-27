/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_defs.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 11:15:30 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 11:54:01 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_DEFS_H
# define PATH_DEFS_H
# include "path_interface.h"

/*
** Path canonization internals (as described in cd POSIX manual)
** Implementation file : canonical_path_internals.c
*/

void	delete_dot(char *path);
char	*delete_parent_ref(char *path);
void	delete_unneeded_slash(char *path);

#endif
