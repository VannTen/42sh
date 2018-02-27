/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_guard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:48:09 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/23 11:39:11 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "meta_programming_defs.h"
#include "convert_interface.h"
#include "unix_files_interface.h"
#include "string_interface.h"
#include "printf.h"

void	print_header_guard_in(int fd, const char *file_name)
{
	char *unix_const;

	unix_const = ft_strmap(get_no_dir_part(file_name), f_to_unix_const);
	ft_dprintf(fd, "#ifndef %1$s\n# define %1$s\n\n", unix_const);
}

void	print_header_guard_out(int fd)
{
	ft_dprintf(fd, "#endif");
}
