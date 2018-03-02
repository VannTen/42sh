/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 10:57:31 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 16:34:43 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "itoa_tools.h"
#include "string_interface.h"

int			ft_printf_len_p(t_conversion *conv)
{
	int conversion_result;

	conversion_result =
		itoa_len_unsigned(ft_var_unsigned_integers(conv->arg), 16);
	conv->result_length = conversion_result;
	conv->supp_length = ft_strlen(HEXA_ALTERNATE_FORM);
	return (length_integers(conv, conversion_result));
}

static int	p_writer(char *to_write, const t_conversion *conv)
{
	itoa_write_unsigned(to_write + conv->result_length - 1,
			ft_var_unsigned_integers(conv->arg), 16, HEXADECIMAL_DIGITS);
	return (conv->result_length);
}

static int	alt_form(char *to_write, const t_conversion *conv)
{
	(void)conv;
	ft_strcpy(to_write, HEXA_ALTERNATE_FORM);
	return (ft_strlen(HEXA_ALTERNATE_FORM));
}

void		ft_print_to_p(char *to_write, const t_conversion *conv)
{
	write_whole_conv(to_write, conv, &alt_form, &p_writer);
}
