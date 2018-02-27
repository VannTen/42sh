/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_fifo_iter_variadic.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:02:44 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/12 15:14:06 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fifo_defs.h"
#include "lst_interface.h"
#include "bool_interface.h"
#include <stdarg.h>

t_bool				f_fifoiterr_va(t_fifo *fifo,
		t_bool (*iter)(void *elem, va_list),
		...)
{
	va_list	args;
	t_bool	result;

	va_start(args, iter);
	result = f_lstiterr_vas(fifo->begin_lst, iter, args);
	va_end(args);
	return (result);
}

t_bool				f_fifoiterr_vas(t_fifo *fifo,
		t_bool (*iter)(void *elem, va_list),
		va_list args)
{
	return (f_lstiterr_vas(fifo->begin_lst, iter, args));
}
