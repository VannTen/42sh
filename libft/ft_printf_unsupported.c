/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsupported.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:25:17 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 16:33:59 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_interface.h"
#include "printf_constants.h"
#include "string_interface.h"

static int	len_unsupported(const t_conversion *conv)
{
	(void)conv;
	return (ft_strlen(UNSUPPORTED_CONVERSION_STRING));
}

int			ft_printf_len_unsupported(t_conversion *conv)
{
	return (strings_chars_length(conv, &len_unsupported, &len_unsupported));
}

static int	unsupported_writer(char *to_write, const t_conversion *conv)
{
	(void)conv;
	ft_strcpy(to_write, UNSUPPORTED_CONVERSION_STRING);
	return (ft_strlen(UNSUPPORTED_CONVERSION_STRING));
}

void		ft_print_to_unsupported(char *to_write, const t_conversion *conv)
{
	write_whole_conv_strings_chars(to_write, conv, &unsupported_writer);
}
