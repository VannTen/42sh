/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_errmsg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:02:37 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/22 10:46:32 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell_errmsg.h"
#include "g_shell_errmsg_array.h"

static void	print_errmsg(char const *const errmsg, char const *const buf)
{
	ft_dprintf(2, "42sh: %s: %s\n", buf ? buf : "", errmsg);
}

void		shell_errmsg(int const index, char const *const buf)
{
	extern	char const	*const g_errmsg_array[e_shell_errmsg_max];

	if (index < 0 || e_shell_errmsg_max <= index)
		print_errmsg("undocumented error code", buf);
	else
		print_errmsg(g_errmsg_array[index], buf);
}
