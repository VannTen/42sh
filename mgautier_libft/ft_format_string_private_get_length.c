/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_string_private_get_length.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 13:15:48 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/24 12:28:28 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_string_defs.h"
#include "conversion_interface.h"

static int	set_and_get_conv_len(void *conv)
{
	return (set_and_get_final_conversion_length((t_conversion*)conv));
}

int			ft_set_and_get_resulting_length(const t_format_string *fmt)
{
	return (f_fifodosum(fmt->conversion_list, &set_and_get_conv_len) +
			(ft_format_string_is_valid(fmt) ? fmt->remaining_length : 0));
}

int			ft_get_current_conv_text_len(t_format_string *fmt)
{
	t_conversion const	*conv;

	conv = f_fifo_first_elem(fmt->conversion_list);
	return (ft_get_conv_text_len(conv));
}

void		ft_set_remaining_length(t_format_string *fmt, int length)
{
	fmt->remaining_length = length;
}
