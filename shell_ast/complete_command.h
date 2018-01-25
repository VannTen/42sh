/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_command.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 09:47:50 by ble-berr          #+#    #+#             */
/*   Updated: 2018/01/25 10:09:53 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_AST_COMPLETE_COMMAND_H
# define SHELL_AST_COMPLETE_COMMAND_H

# include "libft.h"

struct s_complete_command
{
	t_list	*lists;
};

#endif
