/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 12:41:14 by bjanik            #+#    #+#             */
/*   Updated: 2017/04/03 20:12:12 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_space(t_arg *p)
{
	if (is_flag(p, ' ') == 1 && is_flag(p, '+') == 0 && p->spec != '%' &&
			p->arg[0] != '-')
		return (1);
	return (0);
}

int	handle_plus(t_arg *p)
{
	if (is_flag(p, '+') == 1 && ft_strchr("DdiUu", p->spec) && p->neg == 0)
		return (1);
	return (0);
}

int	handle_hashtag(t_arg *p)
{
	if (is_flag(p, '#') == 1 && p->arg[0] != '0')
	{
		if (p->spec == 'x')
		{
			p->print_hashtag = ft_strdup("0x");
			return (2);
		}
		if (p->spec == 'X')
		{
			p->print_hashtag = ft_strdup("0X");
			return (2);
		}
		if ((p->spec == 'o' || p->spec == 'O')
				&& p->precision < p->arg_len)
		{
			p->print_hashtag = ft_strdup("0");
			return (1);
		}
	}
	return (0);
}
