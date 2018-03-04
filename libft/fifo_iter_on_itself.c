/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo_iter_on_itself.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:15:40 by mgautier          #+#    #+#             */
/*   Updated: 2018/03/04 11:40:56 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fifo_defs.h"
#include "lst_interface.h"
#include "bool_interface.h"
#include <stdarg.h>

t_bool		f_fifo_insert_on_itself_va(
		t_fifo *fifo,
		void *(*insert)(void *content, t_lst const *itself, va_list),
		void (*destroy)(void **content),
		...)
{
	va_list	args;
	t_bool	result;

	va_start(args, destroy);
	result = f_lst_insert_on_itself_vas(
			fifo->begin_lst, insert, destroy, args);
	fifo->end_lst = lst_last_link(fifo->end_lst);
	va_end(args);
	return (result);
}

t_bool		f_fifo_insert_on_itself_vas(
		t_fifo *fifo,
		void *(*insert)(void *content, t_lst const *itself, va_list),
		void (*destroy)(void **content),
		va_list args)
{
	t_bool	result;

	result = f_lst_insert_on_itself_vas(
			fifo->begin_lst, insert, destroy, args);
	fifo->end_lst = lst_last_link(fifo->end_lst);
	return (result);
}
