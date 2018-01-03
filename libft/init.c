/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 11:43:04 by bjanik            #+#    #+#             */
/*   Updated: 2017/04/09 16:44:57 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_arg(t_arg *arg)
{
	ft_bzero(arg->flags, MAX_FLAG + 1);
	arg->spec = 0;
	arg->width = -1;
	arg->precision = -1;
	arg->arg = NULL;
	arg->w_arg = NULL;
	arg->arg_len = 0;
	arg->print_hashtag = NULL;
	arg->print_width = NULL;
	arg->print_precision = NULL;
	arg->start_format_part = NULL;
	arg->end_format_part = NULL;
	arg->end_format = NULL;
	ft_bzero(arg->lenght, 3);
}

void	init_ret(t_arg *p)
{
	p->ret.flag = 0;
	p->ret.flag2 = 0;
	p->ret.flag3 = 0;
	p->ret.flag4 = 0;
	p->ret.flag5 = 0;
	p->ret.width = 0;
	p->ret.precision = 0;
	p->ret.lenght = 0;
	p->ret.spec = 0;
}

void	init_len(t_arg *p)
{
	p->len.plus = handle_plus(p);
	p->len.hashtag = handle_hashtag(p);
	p->len.space = handle_space(p);
	p->len.precision = handle_precision(p);
	if (p->spec == 'c' && p->precision == 0)
		p->arg_len++;
	p->len.width = handle_width(p);
	if ((p->spec == 'c' && p->arg != NULL && p->arg[0] == 0) ||
				(p->spec == 'C' && p->w_arg[0] == 0))
		p->len.width--;
	if (p->spec == 'c' && p->arg != NULL && p->arg[0] == 0 &&
			p->precision == 0)
		p->len.width++;
}

void	init_print(t_arg *p)
{
	init_len(p);
	p->print_precision = ft_strnew_set(p->len.precision, '0');
	if (p->spec == '%' && is_flag(p, '0') == 1)
		p->print_width = ft_strnew_set(p->len.width, '0');
	else if ((p->precision > -1 || is_flag(p, '-') == 1 ||
				is_flag(p, '0') == 0) || p->spec == 'S')
		p->print_width = ft_strnew_set(p->len.width, ' ');
	else if (is_flag(p, '-') == 0 && is_flag(p, '0') == 1)
		p->print_width = ft_strnew_set(p->len.width, '0');
}
