/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_command.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 09:47:50 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/05 22:35:06 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_AST_COMPLETE_COMMAND_H
# define SHELL_AST_COMPLETE_COMMAND_H

# include "shell_ast/list.h"

struct	s_sh_complete_command
{
	struct s_sh_list	*list;
};

#endif
