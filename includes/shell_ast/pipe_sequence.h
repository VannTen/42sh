/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_sequence.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 09:55:41 by ble-berr          #+#    #+#             */
/*   Updated: 2018/01/29 09:38:21 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_AST_PIPE_SEQUENCE_H
# define SHELL_AST_PIPE_SEQUENCE_H

# include "libft.h"

struct	s_sh_pipe_sequence
{
	t_list	*simple_commands;
};

#endif
