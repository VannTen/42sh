/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_set_gen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:06:10 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/16 16:09:27 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_interface.h"
#include "libft.h"
#include <stdarg.h>

t_bool	gen_append_to_prod(void *prod, va_list args)
{
	return (append_to_prod(prod, va_arg(args, t_symbol const*)));
}

t_bool	gen_prefix_to_prod(void *prod, va_list args)
{
	return (prefix_to_prod(prod, va_arg(args, t_symbol const*)));
}

void	gen_remove_symbols_head(void *prod, va_list args)
{
	remove_symbols_head(prod, va_arg(args, size_t));
}

void	gen_remove_symbols_tail(void *prod, va_list args)
{
	remove_symbols_tail(prod, va_arg(args, size_t));
}
