/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_variadic_params.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 12:48:04 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/20 19:44:33 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_VARIADIC_PARAMS_H
# define GET_VARIADIC_PARAMS_H
# include <stdarg.h>
# include <stddef.h>

void		get_no_param(t_var_arg *param, va_list *arg_list);
void		get_int_param(t_var_arg *param, va_list *arg_list);
void		get_char_param(t_var_arg *param, va_list *arg_list);
void		get_short_param(t_var_arg *param, va_list *arg_list);
void		get_short_param(t_var_arg *param, va_list *arg_list);
void		get_long_param(t_var_arg *param, va_list *arg_list);
void		get_long_long_param(t_var_arg *param, va_list *arg_list);
void		get_intmax_t_param(t_var_arg *param, va_list *arg_list);
void		get_ptrdiff_t_param(t_var_arg *param, va_list *arg_list);
void		get_size_t_param(t_var_arg *param, va_list *arg_list);
void		get_uint_param(t_var_arg *param, va_list *arg_list);
void		get_uchar_param(t_var_arg *param, va_list *arg_list);
void		get_ushort_param(t_var_arg *param, va_list *arg_list);
void		get_ulong_param(t_var_arg *param, va_list *arg_list);
void		get_ulong_long_param(t_var_arg *param, va_list *arg_list);
void		get_uintmax_t_param(t_var_arg *param, va_list *arg_list);
void		get_int_ptr_param(t_var_arg *param, va_list *arg_list);
void		get_char_ptr_param(t_var_arg *param, va_list *arg_list);
void		get_short_ptr_param(t_var_arg *param, va_list *arg_list);
void		get_long_ptr_param(t_var_arg *param, va_list *arg_list);
void		get_long_long_ptr_param(t_var_arg *param, va_list *arg_list);
void		get_intmax_t_ptr_param(t_var_arg *param, va_list *arg_list);
void		get_ptrdiff_t_ptr_param(t_var_arg *param, va_list *arg_list);
void		get_size_t_ptr_param(t_var_arg *param, va_list *arg_list);
void		get_wint_param(t_var_arg *param, va_list *arg_list);
void		get_wstring_param(t_var_arg *param, va_list *arg_list);
typedef void	(*t_get_variadic)(t_var_arg *param, va_list *);

# define CONST_GET_ARG_INITIALIZER\
	&get_no_param,\
	&get_int_param,\
	&get_long_param,\
	&get_long_long_param,\
	&get_short_param,\
	&get_char_param,\
	&get_intmax_t_param,\
	&get_ptrdiff_t_param,\
	&get_size_t_param,\
	NULL,\
	&get_uint_param,\
	&get_ulong_param,\
	&get_ulong_long_param,\
	&get_ushort_param,\
	&get_uchar_param,\
	&get_uintmax_t_param,\
	&get_ptrdiff_t_param,\
	&get_size_t_param,\
	NULL,\
	&get_int_ptr_param,\
	&get_long_ptr_param,\
	&get_long_long_ptr_param,\
	&get_short_ptr_param,\
	&get_char_ptr_param,\
	&get_intmax_t_ptr_param,\
	&get_ptrdiff_t_ptr_param,\
	&get_size_t_ptr_param,\
	NULL,\
	&get_char_param,\
	&get_wint_param,\
	&get_char_ptr_param,\
	&get_wstring_param

#endif
