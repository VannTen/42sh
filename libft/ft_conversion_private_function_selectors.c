/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_private_function_selectors.c         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 10:10:57 by mgautier          #+#    #+#             */
/*   Updated: 2018/03/04 11:49:00 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "conv_len_interface.h"
#include "conv_write_interface.h"

int		ft_get_len_conv(const t_conversion *conv)
{
	const t_get_len	get_len[] = {
		&ft_printf_len_di,
		&ft_printf_len_di,
		&ft_printf_len_o,
		&ft_printf_len_u,
		&ft_printf_len_x,
		&ft_printf_len_x,
		&ft_printf_len_unsupported,
		&ft_printf_len_unsupported,
		&ft_printf_len_unsupported,
		&ft_printf_len_unsupported,
		&ft_printf_len_unsupported,
		&ft_printf_len_unsupported,
		&ft_printf_len_unsupported,
		&ft_printf_len_unsupported,
		&ft_printf_len_c,
		&ft_printf_len_s,
		&ft_printf_len_p,
		&ft_printf_len_unsupported,
		&ft_printf_len_no_conversion,
		&ft_printf_len_unsupported };

	return (get_len[conv->type](conv));
}

void	ft_select_writer_conv(char *to_write, const t_conversion *conv)
{
	const t_print_to	print_to[] = {
		&ft_print_to_di,
		&ft_print_to_di,
		&ft_print_to_o,
		&ft_print_to_u,
		&ft_print_to_x,
		&ft_print_to_x,
		&ft_print_to_unsupported,
		&ft_print_to_unsupported,
		&ft_print_to_unsupported,
		&ft_print_to_unsupported,
		&ft_print_to_unsupported,
		&ft_print_to_unsupported,
		&ft_print_to_unsupported,
		&ft_print_to_unsupported,
		&ft_print_to_c,
		&ft_print_to_s,
		&ft_print_to_p,
		&ft_print_to_unsupported,
		&ft_print_to_no_conversion,
		&ft_print_to_unsupported };

	print_to[conv->type](to_write, conv);
}
