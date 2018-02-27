/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 13:50:44 by bjanik            #+#    #+#             */
/*   Updated: 2017/01/20 12:11:45 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_wide_s(t_arg *p)
{
	if (p->width > p->arg_len)
	{
		is_flag(p, '-') == 0 ? ft_putstr(p->print_width) : 0;
		if (p->w_arg == NULL)
			ft_putnstr("(null)", p->arg_len);
		else
			ft_putnwstr(p->w_arg, p->arg_len);
		is_flag(p, '-') == 1 ? ft_putstr(p->print_width) : 0;
		return (p->width);
	}
	else
	{
		if (p->w_arg == NULL)
			return (ft_putnstr("(null)", p->arg_len));
		return (ft_putnwstr(p->w_arg, p->arg_len));
	}
}

int	print_ls(t_arg *p)
{
	if (p->width > p->arg_len)
	{
		is_flag(p, '-') == 0 ? ft_putstr(p->print_width) : 0;
		if (p->w_arg == NULL)
			ft_putnstr("(null)", p->arg_len);
		else
			ft_putnwstr(p->w_arg, p->arg_len);
		is_flag(p, '-') == 1 ? ft_putstr(p->print_width) : 0;
		return (p->width);
	}
	else
	{
		if (p->w_arg == NULL)
			return (ft_putnstr("(null)", p->arg_len));
		return (ft_putnwstr(p->w_arg, p->arg_len));
	}
}

int	print_wide_c(t_arg *p)
{
	if (p->width > p->arg_len)
	{
		is_flag(p, '-') == 0 ? ft_putstr(p->print_width) : 0;
		if (p->w_arg[0] == 0)
			ft_putwchar_t(0);
		else
			ft_putwstr(p->w_arg);
		is_flag(p, '-') == 1 ? ft_putstr(p->print_width) : 0;
		return (p->width);
	}
	if (p->w_arg[0] == 0)
		return (ft_putwchar_t(0));
	return (ft_putwstr(p->w_arg));
}
