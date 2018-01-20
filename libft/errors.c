/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 14:44:14 by bjanik            #+#    #+#             */
/*   Updated: 2017/01/20 12:13:12 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		valid_flags(t_arg *p)
{
	if (p->ret.flag < 0 || p->ret.flag2 < 0 || p->ret.flag3 < 0 ||
			p->ret.flag4 < 0 || p->ret.flag5 < 0)
		return (-1);
	return (1);
}

int		valid_remain(t_arg *p)
{
	if (p->ret.width < 0 || p->ret.precision < 0 ||
			p->ret.lenght < 0 || p->ret.spec < 0)
		return (-1);
	return (1);
}

int		incompatible_flag_and_specifier(t_arg *p, char c)
{
	int	error;

	error = 0;
	if (is_flag(p, '#') == 1 && ft_strchr("XxOo%", c) == NULL)
		error = error_wrong_flag(p, '#');
	if (is_flag(p, '+') == 1 && ft_strchr("sSuUxXcCpoO", c) != NULL)
		error = error_wrong_flag(p, '+');
	if (is_flag(p, '0') == 1 && ft_strchr("sSpCc", c) != NULL)
		error = error_wrong_flag(p, '0');
	if (is_flag(p, ' ') == 1 && ft_strchr("sSxXcCoOuUp", c) != NULL)
		error = error_wrong_flag(p, ' ');
	if (error == 1)
		return (-1);
	return (1);
}

int		incompatible_lenght_and_specifier(t_arg *p)
{
	int	error;

	error = 0;
	if (p->spec == 'p' && p->lenght[0] != 0)
		error = error_wrong_lenght(p);
	else if ((p->spec == 's' || p->spec == 'c')
			&& ((p->lenght[0] != 0 && p->lenght[0] != 'l')
				|| p->lenght[1] != 0))
		error = error_wrong_lenght(p);
	else if ((p->spec == 'S' || p->spec == 'C') && p->lenght[0] != 0)
		error = error_wrong_lenght(p);
	if (error == -1)
		return (-1);
	return (0);
}

int		incompatible_precision_and_specifier(t_arg *p)
{
	int	error;

	error = 0;
	if ((p->spec == 'S' || p->spec == 'c' || p->spec == 'p')
			&& p->precision > 0)
	{
		ft_putstr_fd(RED, 2);
		ft_putstr_fd("ERROR: precision used with '", 2);
		ft_putchar_fd(p->spec, 2);
		ft_putstr_fd("' conversion spec, resulting in undefined", 2);
		ft_putendl_fd(" behaviour [-Wformat]", 2);
		ft_putstr_fd(RESET, 2);
		error = -1;
	}
	return (error);
}
