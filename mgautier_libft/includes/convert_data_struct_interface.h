/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_data_struct_interface.h                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:30:33 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/18 17:02:15 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_DATA_STRUCT_INTERFACE_H
# define CONVERT_DATA_STRUCT_INTERFACE_H
# include "lst_interface.h"
# include "fifo_interface.h"

/*
** Functions to convert a data struct to another (array to list, for example)
** Content is copied by reference.
*/

t_lst	*str_to_lst(char const *array);
char	*lst_to_str(t_lst const *lst);
t_fifo	*str_to_fifo(char const *str);
t_lst	*array_to_lst(void const *array);
t_lst	*array_to_lst_index(void const *array, size_t index);

#endif
