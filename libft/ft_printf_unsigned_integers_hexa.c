/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_integers_hexa.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 19:02:34 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 16:34:26 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "variadic_args_interface.h"
#include "itoa_tools.h"
#include "string_interface.h"

static int	write_alt_form(char *to_write, const t_conversion *conv)
{
	if (conv->flags[ALTERNATE_FORM] && conv->result_length != 0)
	{
		ft_strcpy(to_write, conv->type == X ?
				HEXA_ALTERNATE_FORM : HEXA_MAJ_ALTERNATE_FORM);
		return (ft_strlen(HEXA_ALTERNATE_FORM));
	}
	else
		return (0);
}

static int	x_writer(char *to_write, const t_conversion *conv)
{
	itoa_write_unsigned(to_write + conv->result_length - 1,
			ft_var_unsigned_integers(conv->arg), 16,
			conv->type == X ? HEXADECIMAL_DIGITS : HEXADECIMAL_DIGITS_CAPS);
	return (conv->result_length);
}

int			ft_printf_len_x(t_conversion *conv)
{
	int conversion_result;

	conversion_result =
		itoa_len_unsigned(ft_var_unsigned_integers(conv->arg), 16);
	conv->result_length = conversion_result;
	conv->supp_length = count_alternate_form(conv);
	return (length_integers(conv, conversion_result));
}

void		ft_print_to_x(char *to_write, const t_conversion *conv)
{
	write_whole_conv(to_write, conv, &write_alt_form, &x_writer);
}
