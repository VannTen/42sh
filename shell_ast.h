/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_ast.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 09:01:45 by ble-berr          #+#    #+#             */
/*   Updated: 2018/01/22 11:00:52 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_AST_H
# define SHELL_AST_H

# include "libft.h"

/*
** =================================== AST =====================================
*/

struct	s_program
{
	t_list	*and_or_list;
};

/*
** The pipe_sequences list is meant to be composed of elements containing an
** s_pipe_sequence structure seperated by elements containing an enumerated
** value representing a logical operation. It is thusly poorly named.
*/

struct	s_and_or
{
	t_list	*pipe_sequences;
};

struct	s_pipe_sequence
{
	t_list	*simple_commands;
};

struct s_simple_command
{
	char	**args;
	t_list	*redirs;
	int		child;
};

struct s_redirection
{
	int	ionum;
	int	type;
	int	fd;
};

#endif
