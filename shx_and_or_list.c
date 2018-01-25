/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shx_and_or_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 09:26:33 by ble-berr          #+#    #+#             */
/*   Updated: 2018/01/25 09:28:40 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_ast/and_or.h"

int	shx_and_or_list(struct s_and_or_list *const and_or_list)
{
	t_list	*tmp;
	int		ret;

	if (and_or != NULL)
	{
		tmp = and_or->pipe_sequences;
		while (tmp != NULL)
		{
			ret = shx_pipe_sequence(tmp->content);
			if (tmp->next != NULL && continue_logic(tmp->next->content, ret))
				tmp = tmp->next->next;
			else
				break;
		}
		return (ret);
	}
	else
		return (-1);
}
