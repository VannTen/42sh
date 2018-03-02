/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_signed_integers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 08:55:33 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/28 10:22:56 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "variadic_args_interface.h"
#include "itoa_tools.h"

static int	count_signedness(const t_conversion *conv)
{
	if (conv->flags[ALWAYS_SIGN] || conv->flags[BLANK] ||
			is_signed_negative(conv->arg))
		return (1);
	else
		return (0);
}

static int	write_signedness(char *to_write, const t_conversion *conv)
{
	if (is_signed_negative(conv->arg))
		*to_write = '-';
	else if (conv->flags[ALWAYS_SIGN])
		*to_write = '+';
	else if (conv->flags[BLANK])
		*to_write = ' ';
	else
		return (0);
	return (1);
}

int			ft_printf_len_di(t_conversion *conv)
{
	int	conversion_result;

	conversion_result = itoa_len_signed(ft_var_signed_integers(conv->arg), 10);
	conv->result_length = conversion_result;
	conv->supp_length = count_signedness(conv);
	return (length_integers(conv, conversion_result));
}

static int	di_writer(char *to_write, const t_conversion *conv)
{
	itoa_write_signed(to_write + conv->result_length - 1,
			ft_var_signed_integers(conv->arg), 10, DECIMAL_DIGITS);
	return (conv->result_length);
}

void		ft_print_to_di(char *to_write, const t_conversion *conv)
{
	write_whole_conv(to_write, conv, &write_signedness, &di_writer);
}
