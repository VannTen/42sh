/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_string_parser.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 15:31:04 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/25 15:17:15 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_string_interface.h"
#include "printf_constants.h"
#include <stdlib.h>

t_format_string	*ft_full_fmt(const char *base_text, va_list *var_args)
{
	t_format_string *fmt;

	fmt = ft_format_string_parser(base_text);
	if (fmt != NULL)
	{
		if (ft_get_var_args(fmt, var_args) < 0)
			fmt_destroy(&fmt);
		else
			ft_attributes_var_args(fmt);
	}
	return (fmt);
}

static int		adds_conversions(const char *string, t_format_string *fmt)
{
	int	index;
	int	preceding_length;
	int	conv_len;

	index = 0;
	preceding_length = 0;
	while (string[index + preceding_length] != '\0')
	{
		if (string[index + preceding_length] == CONVERSION_INDICATOR)
		{
			index += preceding_length;
			conv_len = ft_add_conversion(string + index, fmt, preceding_length);
			if (conv_len == CONVERSION_PARSE_ERROR)
				break ;
			index += conv_len;
			preceding_length = 0;
		}
		else
			preceding_length++;
	}
	return (preceding_length);
}

t_format_string	*ft_format_string_parser(const char *string)
{
	t_format_string	*format_string;

	format_string = fmt_ctor();
	if (format_string == NULL)
		return (NULL);
	ft_set_remaining_length(format_string,
			adds_conversions(string, format_string));
	return (format_string);
}
