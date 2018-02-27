/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var_args_private_give.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 09:13:43 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/21 10:44:24 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variadic_args_defs.h"
#include <wchar.h>
#include <stdint.h>

intmax_t	ft_var_signed_integers(const t_var_arg *signed_integer)
{
	intmax_t	integer;

	integer = 0;
	if (signed_integer->type == INT)
		integer = signed_integer->parameter.t_int;
	if (signed_integer->type == SHORT)
		integer = signed_integer->parameter.t_short;
	if (signed_integer->type == CHAR || signed_integer->type == CARAC)
		integer = signed_integer->parameter.t_char;
	else if (signed_integer->type == LONG)
		integer = signed_integer->parameter.t_long_int;
	else if (signed_integer->type == LONG_LONG)
		integer = signed_integer->parameter.t_long_long_int;
	else if (signed_integer->type == INTMAX)
		integer = signed_integer->parameter.t_intmax_t;
	else if (signed_integer->type == PTRDIFF)
		integer = signed_integer->parameter.t_ptrdiff_t;
	else if (signed_integer->type == SSIZE)
		integer = signed_integer->parameter.t_ssize_t;
	return (integer);
}

uintmax_t	ft_var_unsigned_integers(const t_var_arg *unsigned_integer)
{
	uintmax_t	integer;

	integer = 0;
	if (unsigned_integer->type == U_INT)
		integer = unsigned_integer->parameter.t_uint;
	else if (unsigned_integer->type == U_SHORT)
		integer = unsigned_integer->parameter.t_ushort;
	else if (unsigned_integer->type == U_CHAR)
		integer = unsigned_integer->parameter.t_uchar;
	else if (unsigned_integer->type == U_LONG)
		integer = unsigned_integer->parameter.t_ulong_int;
	else if (unsigned_integer->type == U_LONG_LONG)
		integer = unsigned_integer->parameter.t_ulong_long_int;
	else if (unsigned_integer->type == U_INTMAX)
		integer = unsigned_integer->parameter.t_uintmax_t;
	else if (unsigned_integer->type == U_INTPTR)
		integer = unsigned_integer->parameter.t_uintptr_t;
	else if (unsigned_integer->type == SIZE)
		integer = unsigned_integer->parameter.t_size_t;
	return (integer);
}

void		*ft_pointer(const t_var_arg *pointer)
{
	if (pointer->type == PTR_INT)
		return (pointer->parameter.t_ptr_int);
	if (pointer->type == PTR_CHAR)
		return (pointer->parameter.t_ptr_char);
	if (pointer->type == PTR_SHORT)
		return (pointer->parameter.t_ptr_short);
	if (pointer->type == PTR_LONG)
		return (pointer->parameter.t_ptr_long_int);
	if (pointer->type == PTR_LONG_LONG)
		return (pointer->parameter.t_ptr_long_long_int);
	if (pointer->type == PTR_INTMAX)
		return (pointer->parameter.t_ptr_intmax_t);
	if (pointer->type == PTR_PTRDIFF)
		return (pointer->parameter.t_ptr_ptrdiff_t);
	if (pointer->type == PTR_SIZE)
		return (pointer->parameter.t_ptr_size_t);
	if (pointer->type == STRING)
		return (pointer->parameter.t_ptr_char);
	if (pointer->type == WSTRING)
		return (pointer->parameter.t_wstring);
	return (NULL);
}

wint_t		ft_wint_type(const t_var_arg *wint)
{
	return (wint->parameter.t_wint_t);
}
