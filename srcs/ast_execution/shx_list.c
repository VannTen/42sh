/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shx_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 09:15:01 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/08 14:24:25 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_shx_global.h"
#include "shell_ast.h"
#include <stddef.h>

int	shx_list(struct s_sh_list *const list, struct s_sh_global *const global)
{
	if (list != NULL)
		(void)shx_and_or(list->and_or, global);
	return (0);
}
