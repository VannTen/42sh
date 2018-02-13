/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_command.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 09:37:24 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/13 18:11:27 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_AST_SIMPLE_COMMAND_H
# define SHELL_AST_SIMPLE_COMMAND_H

# include "libft.h"

struct s_sh_simple_command
{
	t_lst	*arglist;
	size_t	argc;
	t_lst	*redirs;
	int		child;
};

#endif
