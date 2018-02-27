/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unix_files_interface.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 14:26:09 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/12 18:51:54 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIX_FILES_INTERFACE_H
# define UNIX_FILES_INTERFACE_H
# include "bool_interface.h"

/*
** Testing file types
** Implementationf file : is_file.c
*/

t_bool		is_dir(const char *path);
t_bool		is_regfile(const char *path);

/*
** File name and path manipulation
** Implementation file : unix_file_path_name.c
*/

const char	*get_no_dir_part(char const *full_path);
char		*bare_file_name(char const *full_path);
char		*basename(char const *file_path_full);

#endif
