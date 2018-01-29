/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 09:51:58 by ble-berr          #+#    #+#             */
/*   Updated: 2018/01/29 09:20:10 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_AST_AND_OR_H
# define SHELL_AST_AND_OR_H

# include "libft.h"

enum	e_logic
{
	e_logic_none;
	e_logic_and;
	e_logic_or;
};

struct	s_sh_and_or_elem
{
	void					*pipe_sequence;
	enum e_logic			logic;
	struct s_sh_and_or_elem	*next;
};

struct	s_sh_and_or
{
	t_list	*pipe_sequences;
};

#endif
