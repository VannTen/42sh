/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_write_interface.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 14:20:52 by mgautier          #+#    #+#             */
/*   Updated: 2018/03/04 11:49:32 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONV_WRITE_INTERFACE_H
# define CONV_WRITE_INTERFACE_H
# include "conversion_interface.h"

typedef	void	(*t_print_to)(char *to_write, const t_conversion *conv);
void ft_print_to_di(char *to_write, const t_conversion *conv);
void ft_print_to_o(char *to_write, const t_conversion *conv);
void ft_print_to_u(char *to_write, const t_conversion *conv);
void ft_print_to_x(char *to_write, const t_conversion *conv);
void ft_print_to_x_maj(char *to_write, const t_conversion *conv);
void ft_print_to_e(char *to_write, const t_conversion *conv);
void ft_print_to_f(char *to_write, const t_conversion *conv);
void ft_print_to_g(char *to_write, const t_conversion *conv);
void ft_print_to_a(char *to_write, const t_conversion *conv);
void ft_print_to_c(char *to_write, const t_conversion *conv);
void ft_print_to_s(char *to_write, const t_conversion *conv);
void ft_print_to_p(char *to_write, const t_conversion *conv);
void ft_print_to_n(char *to_write, const t_conversion *conv);
void ft_print_to_no_conversion(char *to_write, const t_conversion *conv);
void ft_print_to_unsupported(char *to_write, const t_conversion *conv);

#endif
