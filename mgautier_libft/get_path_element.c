/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_element.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 13:17:28 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/29 13:35:00 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path_defs.h"
#include "string_interface.h"

/*
** From a path of the form foo/bar/foz or /foo/bar/foz , will get "foz"
*/

const char	*get_file_part(const char *full_path)
{
	const char	*file_name;

	file_name = ft_strrchr(full_path, '/');
	if (file_name != NULL)
		file_name = file_name + 1;
	else
		file_name = full_path;
	return (file_name);
}
