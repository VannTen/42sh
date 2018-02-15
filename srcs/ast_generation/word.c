/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:08:25 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/15 15:43:07 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "s_container.h"
#include "shell_ast/container_labels.h"
#include "tokens.h"

void	*create_word(void const *lex_value)
{
	t_token const		*token;

	token = lex_value;
	if (token != NULL && token->value != NULL)
	{
		return (new_container(token->value,
				&ft_memdel,
				ft_strlen(token->value) + 1,
				e_ast_container_label_word));
	}
	else
		return (NULL);
}
