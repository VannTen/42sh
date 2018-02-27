/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_join.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 17:18:06 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/29 17:27:16 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path_defs.h"
#include "string_interface.h"

/*
** This functions should not be used if there is other refs to dir
** They would end up pointing to garbage data.
*/

void			get_add_path_before(char **dir, const char *path_elem)
{
	char	*new_dir;

	if (last_char_of(path_elem) == '/')
		new_dir = ft_strjoin(path_elem, *dir);
	else
		new_dir = ft_strvajoin(3, path_elem, "/", *dir);
	ft_strdel(dir);
	*dir = new_dir;
}
