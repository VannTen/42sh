/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_string_private_request_args.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 13:40:43 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/25 15:16:10 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_string_defs.h"
#include "conversion_interface.h"
#include "variadic_args_interface.h"
#include <stdarg.h>
#include <stddef.h>

static size_t	bigger_arg(const void *conv)
{
	return (bigger_arg_required((const t_conversion*)conv));
}

static void		normalize(void *conv)
{
	ft_normalize_args((t_conversion*)conv);
}

int				ft_get_var_args(t_format_string *fmt, va_list *var_arg_list)
{
	size_t	arg_nbr;

	arg_nbr = f_fifomax(fmt->conversion_list, &bigger_arg);
	fmt->arg_list = ft_arg_list_ctor(arg_nbr);
	f_fifoiter(fmt->conversion_list, &normalize);
	fmt->arg_count = arg_nbr;
	if (fmt->arg_list == NULL)
		return (-1);
	ft_set_types(fmt->arg_list, fmt->conversion_list, arg_nbr);
	ft_fill_args_array(fmt->arg_list, var_arg_list, arg_nbr);
	return (arg_nbr);
}

static void		conv_attribute_arg(void *conv, void *array)
{
	ft_conv_attribute_arg((t_conversion*)conv, (t_var_arg*)array);
}

void			ft_attributes_var_args(t_format_string *fmt)
{
	f_fifoiterarray(fmt->arg_list, fmt->conversion_list, &conv_attribute_arg);
}
