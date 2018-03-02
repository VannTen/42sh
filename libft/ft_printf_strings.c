/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_strings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 13:07:32 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 16:34:56 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "length_modifier_defs.h"
#include "variadic_args_interface.h"
#include "printf_constants.h"
#include "wide_char_interface.h"
#include "string_interface.h"
#include <wchar.h>

static int	len_s(const t_conversion *conv)
{
	int		result;
	char	*string;

	string = ft_pointer(conv->arg);
	if (string == NULL)
		string = STRING_NULL_POINTER;
	if (conv->precision.param.value != NO_PRECISION)
		result = ft_strnlen(string,
				conv->precision.param.value);
	else
		result = ft_strlen(string);
	return (result);
}

static int	len_wides(const t_conversion *conv)
{
	wchar_t	*string;

	string = ft_pointer(conv->arg);
	if (string == NULL)
		return (ft_strnlen(STRING_NULL_POINTER, conv->precision.param.value));
	else
		return (ft_wcstrntomb_len(ft_pointer(conv->arg),
					conv->precision.param.value));
}

int			ft_printf_len_s(t_conversion *conv)
{
	return (strings_chars_length(conv, &len_s, &len_wides));
}

static int	s_writer(char *to_write, const t_conversion *conv)
{
	int		index;
	void	*string;

	index = 0;
	string = ft_pointer(conv->arg);
	if (string == NULL)
	{
		ft_strncpy(to_write, STRING_NULL_POINTER, conv->precision.param.value);
		index += conv->precision.param.value;
	}
	else if (conv->length_modifier == LONG)
		index = ft_wcstrntomb_write(to_write, ft_pointer(conv->arg),
				conv->precision.param.value);
	else
	{
		ft_strncpy(to_write, string,
				conv->precision.param.value);
		index = conv->precision.param.value;
	}
	return (index);
}

void		ft_print_to_s(char *to_write, const t_conversion *conv)
{
	write_whole_conv_strings_chars(to_write, conv, &s_writer);
}
