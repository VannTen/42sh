/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_fifo_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 13:52:54 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/12 18:22:26 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fifo_defs.h"
#include "lst_interface.h"
#include <stdarg.h>

void				f_fifoiter_va(t_fifo const *fifo,
		void (*iter)(const void *elem, va_list),
		...)
{
	va_list	args;

	va_start(args, iter);
	f_lstiter_vas(fifo->begin_lst, iter, args);
	va_end(args);
}

void				f_fifoiter_vas(t_fifo const *fifo,
		void (*iter)(const void *elem, va_list),
		va_list args)
{
	f_lstiter_vas(fifo->begin_lst, iter, args);
}

t_bool				f_fifoiterr(t_fifo *fifo, t_bool (*iter)(void *elem))
{
	return (f_lstiterr(fifo->begin_lst, iter));
}
