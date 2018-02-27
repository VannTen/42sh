/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 13:05:31 by bjanik            #+#    #+#             */
/*   Updated: 2017/02/07 15:53:42 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	*handle_arg_2(t_arg *p, va_list ap)
{
	char	*s;

	s = NULL;
	if (p->spec == 'p')
	{
		s = (ft_strjoin_free("0x",
					ft_itoa_base((intmax_t)va_arg(ap, long long), HEXA_L), 2));
		return (s);
	}
	if (p->spec == '%')
		return (ft_strdup("%"));
	if (p->spec == 'b')
		return (convert_binary(p, ap));
	return (NULL);
}

void		*handle_arg(t_arg *p, va_list ap)
{
	if (p->spec == 'd' || p->spec == 'i')
		return (convert_decimal(p, ap));
	if (p->spec == 'D')
		return (convert_long_decimal(p, ap));
	if (p->spec == 'x')
		return (convert_hexa_lower(p, ap));
	if (p->spec == 'X')
		return (convert_hexa_upper(p, ap));
	if (p->spec == 'o')
		return (convert_octal(p, ap));
	if (p->spec == 'O')
		return (convert_long_octal(p, ap));
	if (p->spec == 'u')
		return (convert_unsigned(p, ap));
	if (p->spec == 'U')
		return (convert_unsigned_long(p, ap));
	if (p->spec == 'S' || (p->spec == 's' && p->lenght[0] == 'l'))
		return (va_arg(ap, wchar_t*));
	if (p->spec == 's')
		return (va_arg(ap, char*));
	if (p->spec == 'C' || (p->spec == 'c' && p->lenght[0] == 'l'))
		return (convert_wide_char(ap));
	if (p->spec == 'c')
		return (convert_char(ap));
	return (handle_arg_2(p, ap));
}
