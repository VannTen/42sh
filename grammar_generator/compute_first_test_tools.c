/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_first_test_tools.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:37:11 by mgautier          #+#    #+#             */
/*   Updated: 2018/03/02 15:59:53 by heynard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test_interface.h"

static void		*string_to_first_set(void const *str)
{
	return (f_strsplit_lst(str, ' '));
}

void			destroy_cmp_first_set(void **first_set)
{
	f_lstdel((t_lst**)first_set, ft_gen_strdel);
}

static void		print_sym_comp(void const *v_str, va_list args)
{
	char const	*str;

	str = v_str;
	ft_dprintf(va_arg(args, int), "%s ", str);
}

static void		print_set_comp(void const *first_set, va_list args)
{
	int	fd;

	fd = va_arg(args, int);
	f_lstiter_va(first_set, print_sym_comp, fd);
	ft_putstr_fd("\n", fd);
}

void			print_first_set_comp(t_lst const *first_set_cmp, int const fd)
{
	f_lstiter_va(first_set_cmp, print_set_comp, fd);
}
