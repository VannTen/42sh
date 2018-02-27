/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_construct_debug.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 18:49:59 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/25 18:49:59 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_construct_defs.h"
#include "libft.h"
#include "test_interface.h"
#include <unistd.h>

static void	print(void *tmp)
{
	print_exec_construct(tmp);
}

void	print_exec_stack(t_lst *stack)
{
	f_lstiter(stack, print);
}
void	print_exec_construct(t_exec_construct const *construct)
{
	ft_dprintf(STDERR_FILENO, "%zu\n", construct->remaining_symbols);
}
