/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optional_and_or.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:31:26 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/15 13:54:29 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast_generation.h"
#include "shell_ast/container_labels.h"
#include "s_container.h"
#include "libft.h"
#include <stdlib.h>

void	*create_optional_and_or(void const *lex_value)
{
	(void)lex_value;
	return (new_container(NULL, NULL, 0,
				e_ast_container_label_optional_and_or));
}

t_bool	give_optional_and_or(void *construct, void *sub_construct)
{
	if (sub_construct != NULL)
	{
		((struct s_container*)construct)->content = sub_construct;
		((struct s_container*)construct)->destroy_content = &destroy_container;
	}
	return (TRUE);
}
