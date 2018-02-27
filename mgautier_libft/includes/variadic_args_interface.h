/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic_args_interface.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 10:34:04 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/25 15:20:02 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIADIC_ARGS_INTERFACE_H
# define VARIADIC_ARGS_INTERFACE_H
# include "fifo_interface.h"
# include "bool_interface.h"
# include <wchar.h>
# include <stdarg.h>
# include <stdint.h>

struct s_var_arg;
typedef struct s_var_arg	t_var_arg;

/*
** Ressources management and getting actual va_arg
** Implementation file : ft_variadic_args_private_ressources.c
*/

t_var_arg		*ft_arg_list_ctor(size_t arg_nbr);
void			ft_arg_list_dtor(t_var_arg **array, size_t size);
void			ft_fill_args_array(t_var_arg *arg_list, va_list *var_args,
		size_t size);

/*
** Waiting for doc
*/

void			ft_set_types(t_var_arg *args_array, t_fifo *conversion_list,
		size_t args_number);
void			ft_fill_args_array(t_var_arg *arg_list, va_list *var_args,
		size_t size);
/*
** Const functions
*/

int				ft_get_int(const t_var_arg *var_arg);
const t_var_arg	*ft_get_address(const t_var_arg *array, size_t index);

intmax_t		ft_var_signed_integers(const t_var_arg *signed_integer);
uintmax_t		ft_var_unsigned_integers(const t_var_arg *unsigned_integer);
wint_t			ft_wint_type(const t_var_arg *wint);
void			*ft_pointer(const t_var_arg *pointer);

t_bool			is_signed_positive(const t_var_arg *arg);
t_bool			is_signed_negative(const t_var_arg *arg);
t_bool			has_no_null_value(const t_var_arg *arg);
#endif
