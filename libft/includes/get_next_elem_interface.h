/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_elem_interface.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:23:03 by mgautier          #+#    #+#             */
/*   Updated: 2018/03/21 16:33:16 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_ELEM_INTERFACE_H
# define GET_NEXT_ELEM_INTERFACE_H
# include "bool_interface.h"
# include "lst_interface.h"

/*
** Constants definitions
*/

# define ONE_LINE_READ 1
# define READ_ERROR -1
# define FILE_IS_OVER 0
# define BUFF_SIZE 4096

/*
** Types definitions
*/

typedef struct	s_file_cache
{
	t_lst	*lines;
	t_bool	is_over;
	int		fd;
}				t_file_cache;

int				get_next_elem(const int fd, char **line, char elem_delimiter);
#endif
