/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 11:57:13 by ble-berr          #+#    #+#             */
/*   Updated: 2018/01/25 12:00:26 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_ast/list.h"

void	*ast_alloc_list(void)
{
	struct s_list	*list;

	list = (struct s_list*)malloc(sizeof(*list));
	if (list != NULL)
	{
		list->and_or_list = NULL;
	}
	return (list);
}
