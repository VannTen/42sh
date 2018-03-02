/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_result_string.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:13:35 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/28 16:25:11 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_string_interface.h"
#include "printf_constants.h"
#include "bool_interface.h"
#include <stddef.h>

static size_t	advance_to_conv(const char *fmt, char *final_string)
{
	size_t	index;

	index = 0;
	while (fmt[index] != CONVERSION_INDICATOR && fmt[index] != '\0')
	{
		final_string[index] = fmt[index];
		index++;
	}
	return (index);
}

t_bool			ft_write_next_conv(const char **fmt, char **final_string,
		t_conversion *conv)
{
	size_t	index;
	int		conv_result_size;

	if (conv != NULL && conversion_result_produces_error(conv))
		return (FALSE);
	index = advance_to_conv(*fmt, *final_string);
	*fmt += index;
	*final_string += index;
	if (**fmt == CONVERSION_INDICATOR && conv != NULL)
	{
		*fmt += ft_get_conv_text_len(conv);
		conv_result_size = ft_write_conversion(*final_string, conv);
		{
			*final_string += conv_result_size;
			return (TRUE);
		}
	}
	return (FALSE);
}
