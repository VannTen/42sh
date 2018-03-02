/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_string_private.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 10:52:44 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/25 15:22:41 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_string_defs.h"
#include "printf_constants.h"
#include "conversion_interface.h"
#include "bool_interface.h"
#include <stdlib.h>

static void		conv_dtor(void **conversion)
{
	conversion_destroy((t_conversion*)*conversion);
	*conversion = NULL;
}

void			fmt_destroy(t_format_string **where_to_destroy)
{
	t_format_string	*to_destroy;

	to_destroy = *where_to_destroy;
	if (to_destroy != NULL)
	{
		ft_arg_list_dtor(&to_destroy->arg_list, to_destroy->arg_count);
		to_destroy->arg_count = 0;
		f_fifo_destroy(&to_destroy->conversion_list, &conv_dtor);
		to_destroy->conversion_list = NULL;
		free(to_destroy);
		*where_to_destroy = NULL;
	}
}

t_format_string	*fmt_ctor(void)
{
	t_format_string *format_string;

	format_string = malloc(sizeof(t_format_string));
	if (format_string != NULL)
	{
		format_string->conversion_list = f_fifo_create();
		if (format_string->conversion_list == NULL)
		{
			fmt_destroy(&format_string);
			return (NULL);
		}
		format_string->arg_count = 0;
	}
	return (format_string);
}

t_bool			f_add_conv_to_fmt(t_format_string *fmt,
		t_conversion *conversion)
{
	return (f_fifo_add(fmt->conversion_list, conversion) != NULL);
}
