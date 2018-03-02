/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_elem_defs.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 12:48:14 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/09 13:33:02 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_ELEM_DEFS_H
# define GET_NEXT_ELEM_DEFS_H
# include "get_next_elem_interface.h"

/*
** Internals functions
** Implememtation file : get_next_elem.c
*/

int				ft_read_file(char **line_to_complete, int fd,
		char elem_delimiter);
int				ft_read_cache(t_file_cache *file, char **line,
		char elem_delimiter);
void			cache_dtor(void **cache_);
int				get_fd(const void *file_cache);

#endif
