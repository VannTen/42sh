/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_put_gen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:12:54 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/12 17:47:19 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_interface.h"
#include "printf.h"

void	ft_gen_putstr(void const *s)
{
	ft_putstr(s);
}

void	ft_gen_putendl(void const *s)
{
	ft_putendl(s);
}

void	ft_gen_putstr_fd(int const fd, void const *s)
{
	ft_putstr_fd(s, fd);
}

void	ft_gen_putendl_fd(int const fd, void const *s)
{
	ft_putendl_fd(s, fd);
}

void	ft_putstr_fd_sep_gen(void const *s, va_list args)
{
	int			fd;
	char const	*sep;
	char const	*str;

	str = s;
	fd = va_arg(args, int);
	sep = va_arg(args, char const*);
	ft_dprintf(fd, "%s%s", str, sep);
}
