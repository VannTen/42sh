/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canonical_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 14:14:09 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 11:56:11 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path_defs.h"
#include <stddef.h>

char	*canonize_path(char *path)
{
	delete_dot(path);
	if (delete_parent_ref(path) == NULL)
		return (NULL);
	delete_unneeded_slash(path);
	return (path);
}
