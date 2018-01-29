/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 13:07:26 by ble-berr          #+#    #+#             */
/*   Updated: 2018/01/25 13:21:26 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_ast/redirection.h"

void	*ast_alloc_redirection(void)
{
	struct s_redirection	*redirection;

	redirection = (struct s_redirection*)malloc(sizeof(*redirection));
	if (redirection != NULL)
	{
		redirection->ionum = -1;
		redirection->tpye = e_redirection_type_none;
		ft_memset(&(redirection->target), 0, sizeof(redirection->target));
	}
	return (redirection);
}
