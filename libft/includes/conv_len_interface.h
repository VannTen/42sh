/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_len_interface.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:00:06 by mgautier          #+#    #+#             */
/*   Updated: 2018/03/04 11:47:27 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONV_LEN_INTERFACE_H
# define CONV_LEN_INTERFACE_H
# include "conversion_interface.h"

typedef	int	(*t_get_len)(const t_conversion *);
int	ft_printf_len_di(const t_conversion *conv);
int	ft_printf_len_o(const t_conversion *conv);
int	ft_printf_len_u(const t_conversion *conv);
int	ft_printf_len_x(const t_conversion *conv);
int	ft_printf_len_e(const t_conversion *conv);
int	ft_printf_len_f(const t_conversion *conv);
int	ft_printf_len_g(const t_conversion *conv);
int	ft_printf_len_a(const t_conversion *conv);
int	ft_printf_len_c(const t_conversion *conv);
int	ft_printf_len_s(const t_conversion *conv);
int	ft_printf_len_p(const t_conversion *conv);
int	ft_printf_len_n(const t_conversion *conv);
int	ft_printf_len_no_conversion(const t_conversion *conv);
int	ft_printf_len_unknown(const t_conversion *conv);
int	ft_printf_len_unsupported(const t_conversion *conv);

# define UNSUPPORTED_CONV sizeof(g_print_len)
#endif
