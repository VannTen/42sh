/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_if.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:08:25 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/09 16:13:18 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "s_container.h"
#include "shell_ast/container_labels.h"

void	*create_and_if(void const *lex_value)
{
	return (new_container(NULL, 0, e_ast_container_label_and_if));
}
