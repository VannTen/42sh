/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtopt_errmsg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 17:00:15 by ble-berr          #+#    #+#             */
/*   Updated: 2017/11/23 17:01:59 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	builtopt_errmsg(char const *name, char opt)
{
	ft_putstr_fd("21sh: ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": invalid option: -", 2);
	ft_putchar_fd(opt, 2);
	ft_putchar_fd('\n', 2);
}
