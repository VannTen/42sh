/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_string_private_const.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:35:42 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/20 13:19:42 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_string_defs.h"
#include "conversion_interface.h"
#include "bool_interface.h"

static t_bool	write_to_next_conv(const void **fmt,
		void **final_string, void *conv)
{
	return (ft_write_next_conv((const char**)fmt, (char**)final_string,
			(t_conversion*)conv));
}

void			ft_write_result_string(const char *fmt_src, char *final_string,
		t_format_string *fmt)
{
	f_fifomaparray(fmt_src, final_string, fmt->conversion_list,
			&write_to_next_conv);
}
