/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_pipe_sequence.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:31:39 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/04 11:39:03 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_PIPE_SEQUENCE_H
# define SHELL_PIPE_SEQUENCE_H

# include <sys/types.h>

# define SHELL_PIPE_SEQUENCE_CHILDMAX 65536

struct	s_pipe_sequence_info
{
	pid_t				children[SHELL_PIPE_SEQUENCE_CHILDMAX];
	unsigned short		child_count;
};

#endif
