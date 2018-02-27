/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_private_integer_length.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 09:48:51 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 16:32:44 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "printf_constants.h"
#include "itoa_tools.h"
#include "string_interface.h"

int		count_alternate_form(const t_conversion *conv)
{
	int	alternate_form_len;

	alternate_form_len = 0;
	if (conv->flags[ALTERNATE_FORM] && has_alternate_form_hexa(conv))
		alternate_form_len = ft_strlen(HEXA_ALTERNATE_FORM);
	return (alternate_form_len);
}

void	handle_zero_padding(t_conversion *conv)
{
	if (conv->flags[ZERO_PADDING])
	{
		conv->precision.param.value = conv->field_width.param.value
			- conv->supp_length;
	}
}
