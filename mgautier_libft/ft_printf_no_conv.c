/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_no_conv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 10:26:38 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/28 10:39:52 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_interface.h"
#include "printf_constants.h"

static int	len_no_conv(const t_conversion *conv)
{
	(void)conv;
	return (1);
}

int			ft_printf_len_no_conversion(t_conversion *conv)
{
	return (strings_chars_length(conv, &len_no_conv, &len_no_conv));
}

static int	no_conv_writer(char *to_write, const t_conversion *conv)
{
	(void)conv;
	*to_write = CONVERSION_INDICATOR;
	return (1);
}

void		ft_print_to_no_conversion(char *to_write, const t_conversion *conv)
{
	write_whole_conv_strings_chars(to_write, conv,
			&no_conv_writer);
}
