/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shx_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 09:23:09 by ble-berr          #+#    #+#             */
/*   Updated: 2018/01/25 09:40:13 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell_ast/program.h"

int	shx_list(struct s_program *const program,
		struct s_shell_globals *const g)
{
	t_list	*and_or_list;
	int		ret;

	if (program != NULL)
	{
		and_or_list = program->and_or_list;
		while (and_or_list != NULL)
		{
			ret = shx_and_or_list(and_or_list->content, g);
			and_or_list = and_or_list->next;
		}
		return (ret);
	}
	else
		return (-1)
}
