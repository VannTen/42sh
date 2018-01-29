/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 09:51:58 by ble-berr          #+#    #+#             */
/*   Updated: 2018/01/25 10:13:01 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_AST_AND_OR_H
# define SHELL_AST_AND_OR_H

# include "libft.h"

struct	s_and_or
{
	t_list	*pipe_sequences;
};

#endif
