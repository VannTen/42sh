/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_commands.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 09:46:27 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/02 13:14:15 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_AST_COMPLETE_COMMANDS_H
# define SHELL_AST_COMPLETE_COMMANDS_H

# include "libft.h"

struct s_sh_complete_commands
{
	t_list	*sequence;
};

#endif
