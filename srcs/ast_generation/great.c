/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   great.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:08:25 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/13 13:03:36 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "s_container.h"
#include "shell_ast/container_labels.h"

void	*create_great(void const *lex_value)
{
	(void)lex_value;
	return (new_container(NULL, 0, e_ast_container_label_great));
}
