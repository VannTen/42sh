/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 09:45:20 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/05 22:35:59 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_AST_PROGRAM_H
# define SHELL_AST_PROGRAM_H

# include "shell_ast/complete_command.h"

struct	s_sh_program
{
	struct s_sh_complete_command	*complete_command;
};

#endif
